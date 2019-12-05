//
// Created by DongHoony on 2019-11-29.
//
#pragma once

#include "land.h"

typedef struct dice{
    int d1;
    int d2;
}Dice;

Dice dice_roll();
int move_cycle(Land* gameboard, Player* p, Dice d);
int determine_double(Dice d);
int land_buy_cycle(Land* gameboard, Player *p, int pos);
int land_upgrade_cycle(Land* gameboard, Player *p, int pos);
int land_cycle(Land* gameboard, Player* p, int pos);
int cycle(Land* gameboard, Player* p, Resident* res);