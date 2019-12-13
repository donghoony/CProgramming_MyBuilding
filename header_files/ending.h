#pragma once
#include <stdio.h>
#define ending_credit_song "..\\data\\ending.wav"

typedef struct end{
	int x_pos;
	int y_pos;
	char word[100];
}End;

void show_ending(End e[],int index);
void play_ending_credit_song();