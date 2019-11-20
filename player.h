//
// Created by DongHoony on 2019-11-20.
//

#ifndef KONKUK_PLAYER_H
#define KONKUK_PLAYER_H

#endif //KONKUK_PLAYER_H

#include "land.h"

typedef struct player{
    int money;
    int position;
    int label; //->identify bot or not
    int lap; // 몇 바퀴 돌았는지
}Player;
void player_move(Land from, Land to);