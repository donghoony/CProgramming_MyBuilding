#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "../header_files/cycle.h"
#include "../header_files/player.h"
#include "../header_files/show.h"
#include "../header_files/gotoyx.h"
#include "../header_files/money.h"
#include "../minigame/maingame.h"

void minigame_cycle(Player* p){
    int win_rate = PlayMaingame();
    const int WIN_COST[] = {0, 5000, 10000, 20000};
    money_earn(p, WIN_COST[win_rate]);
}

int start_point_cycle(Land* gameboard,Player* p, Resident* res){
    money_get_income(p);
    money_earn(p, all_land_rent_fee(gameboard, p, res));
    p->position = 0;
    p->lap++;
    show_lap_update(p);
    show_player_move(gameboard, p,21, 0);
}

void festival_cycle(Land* gameboard, Player* p){
    int before_fest_pos, fest_pos;
    before_fest_pos = find_festival_pos(gameboard);
    fest_pos = col_festival(gameboard, p);
    show_festival(&gameboard[before_fest_pos], &gameboard[fest_pos]);
}

// includes animation
int move_cycle(Land* gameboard, Player* p, Resident* res, Dice d){
    int i;
    for(i = 0; i < d.d1 + d.d2; i++){
        show_player_move(gameboard, p, p->position, (p->position + 1) % MAX_TILE);
        player_move_value(p, 1);
        if (p->position == MAX_TILE) start_point_cycle(gameboard, p, res);
        _sleep(150);
    }
    return p->position;
}

int land_normal_cycle(Land* land, Player* p, Player* p_2, Resident* res){
    int land_owner = land->label;
    int label = p->label;
    int* selected_building = NULL;
    int i, predicted_price, signal;
    // 빈 땅, 내 땅, 남 땅 확인 및 통행료 지급
    // 빈 땅이거나 내 땅이면 사면 됨
    if (land_owner == NO_ONE || land_owner == label){
        // 합 및 현재금액 -> show_choice에서 비교함
        selected_building = show_choice_building(land, p);
        for(i = 0; i < 5; i++){
            if (selected_building[i] == 1){
                land_buy(p, land, res, i);
            }
        }
        free(selected_building);
    }
        // 남 땅이면 통행료 냄
    else {
        predicted_price = land_calculate_cost(land, res);
        signal = money_trade(p, p_2, predicted_price);
        if (signal == NOT_OK) return NOT_OK;
    }
    return OK;
}

int land_cycle(Land* gameboard, Land* land, Player* p, Player* p_2, Resident* res){
    int land_type = land->land_type;
    int signal;

    //도착한 곳이 땅 타일이면
        if (land_type == NORMAL_TYPE){
            signal = land_normal_cycle(land, p, p_2, res);
            if (signal == NOT_OK) return NOT_OK;
    }
    //도착한 곳이 특별 타일이면
    if (land_type == SPECIAL_TYPE) {
        switch(land->land_position){
            case TRAVEL:
                signal = travel_cycle(gameboard, p, p_2, res);
                if (signal == NOT_OK) return NOT_OK;
                break;
            case FESTIVAL:
                festival_cycle(gameboard, p);
                break;
            case START_LAND:
                show_lap_update(p);
                break;
            case ABANDONED_ISLAND:
                player_abandon_init(p);
                break;
            case MINIGAME:
                minigame_cycle(p);
                break;
        }
    }
    return OK;
}

int travel_cycle(Land* gameboard, Player* p, Player* p_2, Resident* res){
    int signal, pos;
    int destination = show_travel_choice(gameboard);
    Dice d = {0, (destination > 15) ? destination-15 : 7 + destination};
    p->position = move_cycle(gameboard, p, res, d);
    pos = p->position;

    signal = land_cycle(gameboard, &gameboard[pos], p, p_2, res);
    if (signal == NOT_OK) return NOT_OK;
}

int game_cycle(Land* gameboard, Player* p, Player* p_2, Resident* res, int cheat){
    // CYCLE : ROLL -> MOVE -> LAND -> END PHASE
    int pos, double_count = 0, key = 0;
    int is_double = 0, signal;
    Dice dice;
    srand((unsigned)time(NULL));

    while (1){
        // CHECK ABANDON ISLAND PHASE
        if (player_check_abandoned(p)){
            player_reduce_abandoned_count(p);
            _sleep(500);
            return OK;
        }

        // ROLL PHASE
        if (cheat != '1') key = getch();
        if (key != KEY_SPACE && cheat != '1') continue;
        dice = rand_dice_roll();

        //test for control dice below 4 lines
        if (cheat == '1'){
            gotoyx(33, 50);
            printf("DICE :         ");
            gotoyx(33, 57);
            scanf("%d %d", &dice.d1, &dice.d2);
        }
        //enable below if non-cheat version
        else{
            show_dice_roll(dice.d1, dice.d2);
            show_dice_big_size(dice.d1 + dice.d2);
        }

        is_double = determine_double(dice);
        double_count += is_double ? 1 : 0;

        // 더블 두 번인지 체크하기, 2회 이상이면 무인도행
        if (double_count >= 2) {
            show_player_move(gameboard, p, p->position, ABANDONED_ISLAND);
            player_move_toward(p, ABANDONED_ISLAND);
            player_abandon_init(p);
            return OK;
        }
        // MOVE PHASE
        p->position = move_cycle(gameboard, p, res, dice);
        pos = p->position;
        //indicates player's position in cheat mode
        if (cheat == '1') {
            gotoyx(33,0);
            printf("NOW AT %02d", p->position);
        }
        // LAND PHASE
        if (pos == TRAVEL) is_double = FALSE;
        signal = land_cycle(gameboard, &gameboard[pos], p, p_2, res);
        if (signal == NOT_OK) return NOT_OK;

        // END PHASE, 더블이 아니면 루프 탈출하기
        if (is_double == FALSE || p->position == ABANDONED_ISLAND) break;
    }
    return OK;
}

int tie_breaker(Land* gameboard, Resident* res){
    int i, j, p1_land_cnt = 0, p2_land_cnt = 0, p1_res_cnt = 0, p2_res_cnt = 0;
    for(i = 0; i < MAX_TILE; i++){
        if (gameboard[i].label == PLAYER) {
            p1_land_cnt++;
            for(j = 0; j < 3; j++) p1_res_cnt += res->resident_info[j][i];
        }
        else if (gameboard[i].label == COMPUTER) {
            p2_land_cnt++;
            for(j = 0; j < 3; j++) p2_res_cnt += res->resident_info[j][i];
        }
    }
    if (p1_land_cnt == p2_land_cnt){
        return (p1_res_cnt > p2_res_cnt) ? PLAYER : COMPUTER;
    }
    else return (p1_land_cnt > p2_land_cnt) ? PLAYER : COMPUTER;
}
