#pragma once

#define DICE_MAX 5

typedef struct dice{
    int d1;
    int d2;
}Dice;

Dice rand_dice_roll();
int rand_roll_dice_only();
int determine_double(Dice d);