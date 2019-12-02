//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#include "land.h"

#ifndef KONKUK_SHOW_H
#define KONKUK_SHOW_H

#endif //KONKUK_SHOW_H
void show_set_cursor_disable();
void show_land_info(Land);
void show_gameboard(Land* gameboard);
void show_gameboard_grid();

void show_player_move(Land* gameboard, Player* p, int from, int to);

void show_test_gameboard(Land* gameboard);