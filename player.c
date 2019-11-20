//
// Created by DongHoony on 2019-11-20.
//


#include "player.h"

void player_move(Player* p, int move_value){
    int cur_position, nxt_position;
    cur_position = p->position;
    nxt_position = (cur_position + move_value) % 22;
}