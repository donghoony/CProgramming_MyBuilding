#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "show.h"
#include "player.h"
#include "file.h"
#include "cycle.h"
#include "func.h"
#include "intro_1.h"

int main() {
    // !!! 선 언 먼 저 합 니 다 , srand도 함 수 니 까 선 언 다 음 에 하 세 요 !!!
    Land *gameboard;
    Player user = {100000, 0,  PLAYER, 5, 0};
    Player bot = {100000, 0, COMPUTER, 5, 0};
	Resident resident = { {0},{0},{0}, {0},
                       {resident.rand_person_villa, resident.rand_person_building,
                                    resident.rand_person_hotel, resident.res_person_landmark}};
    int signal, turn = 30 * 2;
    srand((unsigned) time(NULL));

    gameboard = (Land *) file_get_land_info();
    // Check gameboard is successfully attatched
    if (gameboard == NULL) {
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }
    file_get_land_pos(&gameboard);
    system("cls");

//    intro();


    // Showing initialization
    show_set_cursor_disable();
    show_gameboard_grid();
    show_dice_grid();
    show_player_move(gameboard, &user, user.position, user.position);
    show_player_move(gameboard, &bot, bot.position, bot.position);
    show_init_update(&user, &bot);

    while(turn--){
        show_turn_update(turn, (turn%2 == 1) ? PLAYER : COMPUTER);
        signal = game_cycle(gameboard, (turn%2 == 1) ? &user : &bot, (turn%2 == 1) ? &bot : &user, &resident);
        if (signal == NOT_OK) break;
    }
    show_winner(turn);
    ending_credit();

	return 0;
}

