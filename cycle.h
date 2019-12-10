#pragma once

#include "land.h"
#include "random.h"

#define TRUE 1
#define FALSE 0

int move_cycle(Land* gameboard, Player* p, Resident* res, Dice d);
int determine_double(Dice d);
int land_cycle(Land* gameboard, Land* land, Player* p, Player*, Resident* res);
int game_cycle(Land* gameboard, Player* p, Player* p2, Resident* res, int);
int land_normal_cycle(Land* land, Player* p, Player* p_2, Resident* res);
int travel_cycle(Land* gameboard, Player* p, Player* p_2, Resident* res);
int tie_breaker(Land* gameboard, Resident* res);