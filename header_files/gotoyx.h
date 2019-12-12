#pragma once

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
void gotoyx_clear();