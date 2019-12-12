#pragma once
#include <stdlib.h>
#include "../header_files/random.h"
#include "../header_files/cycle.h"


Dice rand_dice_roll(){
    Dice d;
    d.d1 = rand_roll_dice_only();
    d.d2 = rand_roll_dice_only();
    return d;
}

int rand_roll_dice_only(){
    int ret;
    ret = rand() % DICE_MAX + 1;
    return ret;
}

int determine_double(Dice d){
    return (d.d1 == d.d2) ? TRUE : FALSE;
}
