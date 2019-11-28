#pragma once
#include<stdio.h>

typedef struct player {
	int money;
	int position;
	char* name;
	int label; //->identify bot or not
	int lap; // 몇 바퀴 돌았는지
}Player;

//random.h
int rand_roll_dice(Player* user);
void* make_user_name(Player* user);
int rand_house_person();

void player_move(Player* p, int move_value);