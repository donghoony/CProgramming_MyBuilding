#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "../header_files/show.h"
#include "../header_files/player.h"
#include "../header_files/file.h"
#include "../header_files/cycle.h"
#include "../header_files/func.h"
#include "../header_files/release.h"

void cheat_enable(char key, Player* p1, Player* p2){
    if (key == '1') p1->lap = p2->lap = 5;
    if (key == '2') {
        p1->lap = p2->lap = 5;
        p2->money = 5000;
    }
}

int main() {
    // !!! 선 언 먼 저 합 니 다 , srand도 함 수 니 까 선 언 다 음 에 하 세 요 !!!
    Land *gameboard;
    Player user = {100000, 0,  PLAYER, 0, 0};
    Player bot = {100000, 0, COMPUTER, 0, 0};
	Resident resident = { {0},{0},{0}, {0},
                       {resident.rand_person_villa, resident.rand_person_building,
                                    resident.rand_person_hotel, resident.res_person_landmark}};
    int signal, turn = 30 * 2, winner, key = 0;
    srand((unsigned) time(NULL));

    signal = file_modify(&gameboard);
    if (signal == NOT_OK) return NOT_OK;
    // Showing initialization

    key = show_window_init(gameboard, &user, &bot);
    show_init_update(&user, &bot);
    cheat_enable(key, &user, &bot);
    while(turn--){
        show_turn_update(turn, (turn%2 == 1) ? PLAYER : COMPUTER);
        signal = game_cycle(gameboard, (turn%2 == 1) ? &user : &bot, (turn%2 == 1) ? &bot : &user, &resident, (key == '1' || key == '2' ? '1' : '0'));
        if (signal == NOT_OK) break;
    }
    winner = (turn%2 == 1) ? PLAYER : COMPUTER;
    if (signal == OK && turn == 0) winner = tie_breaker(gameboard, &resident);
    ending();

    release(&gameboard);

	return 0;
}