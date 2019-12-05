//
// Created by DongHoony on 2019-11-29.
//
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "random.h"
#include "show.h"
#include "gotoyx.h"
#include "cycle.h"

Dice dice_roll(){
    Dice d;
    d.d1 = rand_roll_dice_only();
    d.d2 = rand_roll_dice_only();
    return d;
}

int determine_double(Dice d){
    return (d.d1 == d.d2) ? DOUBLE : NOT_DOUBLE;
}

// includes animation
int move_cycle(Land* gameboard, Player* p, Dice d){
    int i;
    for(i = 0; i < d.d1 + d.d2; i++){
        show_player_move(gameboard, p, p->position, (p->position + 1) % 22);
        player_move_value(p, 1);

        if (p->position == 22) {
            money_get_income(p);
            p->position = 0;
            show_player_move(gameboard, p,21, 0);
        }
        _sleep(300);
    }
    return p->position;
}

int land_cycle(Land* gameboard, Player* p, int pos){
    int land_owner = gameboard[pos].label;
    if (land_owner == NO_ONE){

    }
    else if (land_owner == p->label){

    }
    else if (land_owner != p->label){

    }
}

int cycle(Land* gameboard, Player* p, Resident* res){
    int pos, land_owner, label, double_count = 0;
    int is_double = 0, lap, i;
    int land_label, land_type;
    int* selected_building = NULL;
    Dice dice;

    srand((unsigned)time(NULL));
    // label indicates whose turn now
    label = p->label;

    while (1){
        // 주사위 굴리기
        dice = dice_roll();
        show_dice_roll(dice.d1, dice.d2);

        is_double = determine_double(dice);
        double_count += is_double ? 1 : 0;

        // 더블 두 번인지 체크하기, 2회 이상이면 무인도행
        if (double_count >= 2) {
            player_move_toward(p, ABANDONED_ISLAND);
            return 1;
        }

        // 움직이기
        p->position = move_cycle(gameboard, p, dice);
        pos = p->position;
        lap = p->lap;
        gotoyx(35,0);
        printf("NOW AT %02d", p->position);

        // 도착한 곳 확인 (출발, 무인도와 같은 특별 타일인지, 일반 땅 타일인지 확인)
        land_type = gameboard[pos].land_type;

        //도착한 곳이 땅 타일이면
        if (land_type == NORMAL_TYPE){
            land_owner = gameboard[pos].label;

            // 빈 땅, 내 땅, 남 땅 확인 및 통행료 지급
            // 빈 땅이면 살 수 있음
            if (land_owner == NO_ONE || land_owner == label){
                selected_building = show_choice_building(&gameboard[pos], p);
                // !!!!!!!!!!! 합을 구한 뒤에 현재 금액이 더 많이 갖고있는지 확인 필요함  !!!!!!!!!!!!
                for(i = 0; i < 5; i++){
                    if (selected_building[i] == 1){
                        gotoyx_print(34, 0, "Attempt to buy..");
                        land_buy(p, &gameboard[pos], res, i);
                    }
                }
                free(selected_building);
            }
            // 내 땅이면 증가시킬 수 있음
            else if (land_owner == label){
                selected_building = show_choice_building(&gameboard[pos], p);

            }
            // 남 땅이면 통행료 냄
            else if (land_owner != label && land_owner != NO_ONE){

            }
        }

        //도착한 곳이 특별 타일이면
        if (land_type == SPECIAL_TYPE){

        }

        // 더블이 아니면 루프 탈출하기
        if (is_double == NOT_DOUBLE) break;
    }
    return 0;
}