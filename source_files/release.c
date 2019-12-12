//
// Created by DongHoony on 2019-12-10.
//

#include <stdlib.h>
#include "../header_files/land.h"

void release_land(Land* land){
    free(land->name);
    free(land->landmark_name);
    land->name = land->landmark_name = NULL;
}

void release_gameboard(Land** gameboard){
    int i;
    for(i = 0; i < MAX_TILE; i++){
        release_land(gameboard[i]);
        gameboard[i] = NULL;
    }
    free(gameboard);
}

void release(Land** gameboard){
    release_gameboard(gameboard);
    *gameboard = NULL;
}
