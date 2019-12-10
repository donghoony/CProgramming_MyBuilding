#include "player.h"

void player_move_value(Player* p, int move_value){
    p->position += move_value;
};

void player_move_toward(Player* p, int land_num){
    p->position = land_num;
}