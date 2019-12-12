#pragma once

#define NO_ONE 0
#define PLAYER 1
#define COMPUTER 2

typedef struct player {
	int money;
	int position;
	int label; //->identify bot or not
	int lap; // 몇 바퀴 돌았는지
	int abandon_island_count;
}Player;

void player_move_value(Player* p, int move_value);
void player_move_toward(Player* p, int land_num);

// ADDED MANUALLY
int player_check_abandoned(Player* p);
void player_reduce_abandoned_count(Player* p);
void player_abandon_init(Player* p);