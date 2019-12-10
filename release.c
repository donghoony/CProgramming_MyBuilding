//
// Created by DongHoony on 2019-12-10.
//

#include <stdlib.h>
#include "player.h"
#include "land.h"

void release_land(Land* land){
    free(land->name);
    free(land->landmark_name);
}

void release_gameboard(Land** gameboard){
    int i;
    for(i = 0; i < MAX_TILE; i++){
        release_land(gameboard[i]);
    }
    free(gameboard);
}

void release(Land** gameboard){
    release_gameboard(gameboard);
}
