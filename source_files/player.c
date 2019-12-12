#include "../header_files/player.h"
#include "../header_files/cycle.h"
#include "../header_files/show.h"

void player_move_value(Player* p, int move_value){
    p->position += move_value;
};

void player_move_toward(Player* p, int land_num){
    p->position = land_num;
}

int player_check_abandoned(Player* p){
    return (p->abandon_island_count > 0) ? TRUE : FALSE;
}

void player_reduce_abandoned_count(Player* p){
    p->abandon_island_count--;
    return;
}

void player_abandon_init(Player* p){
    p->abandon_island_count = 1;
    return;
}