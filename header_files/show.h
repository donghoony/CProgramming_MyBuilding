//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#include "land.h"

#ifndef KONKUK_SHOW_H
#define KONKUK_SHOW_H

#endif //KONKUK_SHOW_H

#define KEY_LEFT 75
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_ENTER 13
#define KEY_INTRO 224

void show_set_cursor_disable();
void show_gameboard_grid();
void show_player_move(Land* gameboard, Player* p, int from, int to);
int* show_choice_building(Land* land, Player* p);
void show_dice_grid();
void show_dice_roll(int, int);
int show_landmark_satisfy(int*);
void show_update_predict_price(Player* p, int predict_price);
void show_money_update(Player*, int);
int show_predict_price(Land* land, Player* p, int* selected_building, int now_price, int cur);
int show_predict_price_with_cur_zero(Land* land, Player* p, int* selected_building);
void show_lap_update(Player*);
void show_init_update(Player*, Player*);
void show_money_normal_update(Player* p);
int show_travel_choice(Land* gameboard);
void show_turn_update(int turn, int label);
void show_dice_big_size(int sum);
void show_winner(int turn);
void show_festival(Land*, Land*);
char show_window_init(Land* gameboard, Player* user, Player* bot);
void show_land_building_residents(Land* land, int level, int book_people);
void show_land_building_landmark_residents(Land* land, int book_people);
void show_land_building_only_land(Land* land, Player* p);