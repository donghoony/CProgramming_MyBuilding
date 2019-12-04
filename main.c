#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "show.h"
#include "player.h"
#include "gotoyx.h"
#include "file.h"
#include "cycle.h"

int main() {
    // !!! 선 언 먼 저 합 니 다 , srand도 함 수 니 까 선 언 다 음 에 하 세 요 !!!
    int i, y, x;
    Land *gameboard;
    Land cur_land;
    Player user = {2000, 0, "", PLAYER, 0};
    Player bot = {2000, 0, "", COMPUTER, 0};
	Resident resident = { {0},{0},{0} };
	Land l;

    show_set_cursor_disable();
    srand((unsigned) time(NULL));

    // make_user_name보다는 그냥 한번에 setting해주는 함수로 짜는 게 나을듯, 위에 100, 0, "", PLAYER 넣어주는 걸로 (단, 세세히 모듈화)
    make_user_name(&user);

    gameboard = (Land *) file_get_land_info();
    if (gameboard == NULL) {
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }

    file_get_land_pos(&gameboard);
    system("cls");

    show_gameboard_grid();
//    show_test_gameboard(gameboard);


    for(i = 0; i < 22; i++){
        if (gameboard[i].land_type == SPECIAL_TYPE) continue;
        show_build_building(gameboard, (rand()%2 == 1) ? &user : &bot, i, 3);
    }


//  animation test
    for(i = 0; i < 21; i++){
        show_player_move(gameboard, &user, i, i+1);
        _sleep(200);
        show_player_move(gameboard, &bot, i, i+1);
        _sleep(200);
    }

    gotoyx(35, 0);
    system("pause");

}

