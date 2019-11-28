//
// Created by DongHoony on 2019-11-20.
//
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include "player.h"

// constants for after use
#define NO_ONE 0
#define PLAYER 1
#define COMPUTER 2

void* make_user_name(Player* user) {
	user->name = (Player*)malloc(sizeof(Player));
	printf("사용자 이름 : ");
	scanf("%s", user->name);
	user->label = PLAYER;
}
