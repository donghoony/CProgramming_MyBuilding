#include <stdio.h>
#include <stdlib.h>

#include "show.h"
#include "player.h"
#include "gotoyx.h"
#include "file.h"

int main() {
	srand((unsigned)time(NULL));

    int i;
	Player user = { 100,0,"",1,0 };
    Land* gameboard;
    Land cur_land;
	make_user_name(&user);
    gameboard = file_get_land_info();
    if (gameboard == NULL){
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }
    for(i = 0; i < 21; i++){\
        cur_land = gameboard[i];
        printf("%d %s %d %s\n", cur_land.land_position, cur_land.name, cur_land.land_price, cur_land.landmark_name);
    }
    system("cls");
    show_gameboard_grid();
    system("pause");
}
