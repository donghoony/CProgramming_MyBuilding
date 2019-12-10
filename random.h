#pragma once
#ifndef KONKUK_RANDOM_H
#define KONKUK_RANDOM_H

#endif //KONKUK_RANDOM_H

#define DICE_MAX 5
#define DOUBLE 1
#define NOT_DOUBLE 0

typedef struct dice{
    int d1;
    int d2;
}Dice;

Dice rand_dice_roll();
int rand_roll_dice_only();
int rand_house_person();
