#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "show.h"
#include "player.h"
#include "gotoyx.h"
#include "file.h"
#include "cycle.h"
#include "func.h"

int main() {
    // !!! 선 언 먼 저 합 니 다 , srand도 함 수 니 까 선 언 다 음 에 하 세 요 !!!
    Land *gameboard;
    Player user = {100000, 0,  PLAYER, 5, 0};
    Player bot = {100000, 0, COMPUTER, 5, 0};
	Resident resident = { {0},{0},{0}, {0},
                       {resident.rand_person_villa, resident.rand_person_building,
                                    resident.rand_person_hotel, resident.res_person_landmark}};
    int signal, turn = 30 * 2;

    show_set_cursor_disable();
    srand((unsigned) time(NULL));

    // make_user_name보다는 그냥 한번에 setting해주는 함수로 짜는 게 나을듯, 위에 100, 0, "",
    // PLAYER 넣어주는 걸로 (단, 세세히 모듈화)
    gameboard = (Land *) file_get_land_info();

    // Check gameboard is successfully attatched
    if (gameboard == NULL) {
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }
    file_get_land_pos(&gameboard);
    system("cls");

    // Showing initialization
    show_gameboard_grid();
    show_dice_grid();
    show_player_move(gameboard, &user, user.position, user.position);
    show_player_move(gameboard, &bot, bot.position, bot.position);

    //ending credit below
//    ending_credit();
    show_init_update(&user, &bot);
//    show_dice_big_size(19);

    while(turn--){
        show_turn_update(turn, (turn%2 == 1) ? PLAYER : COMPUTER);
        signal = game_cycle(gameboard, (turn%2 == 1) ? &user : &bot, (turn%2 == 1) ? &bot : &user, &resident);
        if (signal == NOT_OK) break;
    }
    gotoyx(36,0);
    if(turn%2 == 0) printf("PLAYER WINS");
    else printf("BOT WINS");
    gotoyx(35, 0);
    system("pause");
	return 0;
}

