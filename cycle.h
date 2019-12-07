//
// Created by DongHoony on 2019-11-29.
//
#pragma once

#include "land.h"
#include "random.h"

int move_cycle(Land* gameboard, Player* p, Dice d);
int determine_double(Dice d);
//int land_buy_cycle(Land* gameboard, Player *p, int pos);
//int land_upgrade_cycle(Land* gameboard, Player *p, int pos);
int land_cycle(Land* land, Player* p, Player*, Resident* res);
int game_cycle(Land* gameboard, Player* p, Player* p2, Resident* res);
int land_normal_cycle(Land* land, Player* p, Player* p_2, Resident* res);
