//
// Created by DongHoony on 2019-11-20.
//

#include <stdlib.h>
#include <time.h>
#define DICE_MAX 5

int rand_roll_dice(){
    int ret;
    srand((unsigned)time(NULL));
    ret = rand() % DICE_MAX + 1;
    return ret;
}
int rand_house_person(){

}