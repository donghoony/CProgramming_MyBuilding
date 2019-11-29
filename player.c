//
// Created by DongHoony on 2019-11-20.
//
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include "player.h"

// constants for after use


void* make_user_name(Player* user) {
//	user->name = (Player*)malloc(sizeof(Player));
//	printf("사용자 이름 : ");
//	scanf("%s", user->name);
//	user->label = PLAYER;
}

void player_move(Player* p, int move_value){
    p->position += move_value;
};