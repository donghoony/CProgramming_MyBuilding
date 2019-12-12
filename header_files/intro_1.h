#pragma once
#pragma comment(lib, "winmm.lib")
#include <stdio.h>
#define BLA "\x1b[30m"
#define RED "\x1b[91m"
#define YEL "\x1b[33m"
#define BLU "\x1b[36m"
#define WHI "\x1b[37m"
#define RES "\x1b[0m"
#define BACK_WHI "\x1b[47m"
#define BYE "\x1b[93m"

#define netmarble_2 "..\\data\\netmarble_2.wav"
#define netmarble "..\\data\\netmarble.wav"
#define netmarble_3 "..\\data\\netmarble_3.wav"
#define netmarble_4 "..\\data\\netmarble_4.wav"
#define netmarble_5 "..\\data\\netmarble_5.wav"

void screen_1();
void screen_2();
void screen_3();
void screen_4();
void play_intro();
void play_intro_2();
void play_intro_3();
void intro();