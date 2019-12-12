#pragma once
#include "player.h"


//int minigame_oddeven(Player p, int level); //-> 3레벨까지 진행가능 (재귀)
int minigame_init();
int minigame_oddeven(int level);
void show_minigame_flip(int win);
void show_minigame_grid();
int minigame_win_continue();
