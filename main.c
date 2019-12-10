#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "show.h"
#include "player.h"
#include "file.h"
#include "cycle.h"
#include "func.h"
#include "intro_1.h"
#include "release.h"

int main() {
    // !!! 선 언 먼 저 합 니 다 , srand도 함 수 니 까 선 언 다 음 에 하 세 요 !!!
    Land *gameboard;
    Player user = {100000, 0,  PLAYER, 0, 0};
    Player bot = {100000, 0, COMPUTER, 0, 0};
	Resident resident = { {0},{0},{0}, {0},
                       {resident.rand_person_villa, resident.rand_person_building,
                                    resident.rand_person_hotel, resident.res_person_landmark}};
    int signal, turn = 30 * 2, winner, cheat = 0;
    srand((unsigned) time(NULL));

    gameboard = (Land *) file_get_land_info();
    // Check gameboard is successfully attatched
    if (gameboard == NULL) {
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }
    file_get_land_pos(&gameboard);

    // Showing initialization
    show_window_init(gameboard, &user, &bot);

    cheat = getch();
    if (cheat == '1') user.lap = bot.lap = 5;
    while(turn--){
        show_turn_update(turn, (turn%2 == 1) ? PLAYER : COMPUTER);
        signal = game_cycle(gameboard, (turn%2 == 1) ? &user : &bot, (turn%2 == 1) ? &bot : &user, &resident, cheat);
        if (signal == NOT_OK) break;
    }
    winner = (turn%2 == 1) ? PLAYER : COMPUTER;
    if (signal == OK && turn == 0) winner = tie_breaker(gameboard, &resident);
    show_winner(winner);
    ending_credit();

    release(&gameboard);
	return 0;
}

