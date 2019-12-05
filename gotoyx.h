//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#ifndef KONKUK_GOTOYX_H
#define KONKUK_GOTOYX_H

#endif //KONKUK_GOTOYX_H

#define C_BLUE 9
#define C_GREEN 10
#define C_CYAN 11
#define C_RED 12
#define C_YELLOW 14
#define C_WHITE 15

//gotoyx.h
void gotoyx(int y, int x);
void gotoyx_print(int y, int x, char* arg);
void gotoyx_set_color(int color);
void gotoyx_print_int(int y, int x, int n);