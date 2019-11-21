//
// Created by DongHoony on 2019-11-20.
//


#include "player.h"

// constants for after use
#define NO_ONE 0
#define PLAYER 1
#define COMPUTER 2

void player_move(Player* p, int move_value){
    int cur_position, nxt_position;
    cur_position = p->position;
    nxt_position = (cur_position + move_value) % 22;
}