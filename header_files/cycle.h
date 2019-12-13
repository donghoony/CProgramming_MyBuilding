#pragma once

#include "random.h"
#include "land.h"
#include "basic_const.h"

int move_cycle(Land* gameboard, Player* p, Resident* res, Dice d);
int land_cycle(Land* gameboard, Land* land, Player* p, Player*, Resident* res);
int game_cycle(Land* gameboard, Player* p, Player* p2, Resident* res, int);
int land_normal_cycle(Land* land, Player* p, Player* p_2, Resident* res);
int travel_cycle(Land* gameboard, Player* p, Player* p_2, Resident* res);
int start_point_cycle(Land* gameboard,Player* p, Resident* res);
void festival_cycle(Land* gameboard, Player* p);
void minigame_cycle(Player* p);
int tie_breaker(Land* gameboard, Resident* res);
