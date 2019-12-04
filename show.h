//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#include "land.h"
#include "cycle.h"

#ifndef KONKUK_SHOW_H
#define KONKUK_SHOW_H

#endif //KONKUK_SHOW_H
void show_set_cursor_disable();
void show_land_info(Land);
void show_gameboard(Land* gameboard);
void show_gameboard_grid();
void show_player_move(Land* gameboard, Player* p, int from, int to);
void show_test_gameboard(Land* gameboard);
int show_build_building(Land* gameboard, Player* p, int pos, int level);
void show_choice_buliding(Land* land, Player* p);
void show_dice_grid();
void show_dice_roll(int, int);