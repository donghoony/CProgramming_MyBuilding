#include <stdio.h>
#include <stdlib.h>

#include "show.h"
#include "player.h"
#include "gotoyx.h"
#include "file.h"

int main() {
    int i;
    Land* gameboard;
    Land cur_land;
    gameboard = file_get_land_info();
    if (gameboard == NULL){
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }
    for(i = 0; i < 22; i++){\
        cur_land = gameboard[i];
        printf("%d %s %d %s\n", cur_land.land_position, cur_land.name, cur_land.land_price, cur_land.landmark_name);
    }

    system("pause");
}
