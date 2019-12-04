//
// Created by DongHoony on 2019-11-29.
//
#include <stdlib.h>
#include "player.h"
#include "random.h"
#include "show.h"
#include "gotoyx.h"
#include "cycle.h"

Dice dice_roll(){
    Dice d;
    d.d1 = rand_roll_dice_only();
    d.d2 = rand_roll_dice_only();
    return d;
}

int determine_double(Dice d){
    return (d.d1 == d.d2) ? DOUBLE : NORMAL;
}

// includes animation
int move_cycle(Land* gameboard, Player* p, Dice d){
    int i;
    for(i = 0; i < d.d1 + d.d2; i++){

        show_player_move(gameboard, p, p->position, (p->position + 1) % 21);
        player_move_value(p, 1);

        if (p->position == 22) {
            money_get_income(p);
            p->position = 0;
            show_player_move(gameboard, p,21, 0);
        }
        _sleep(100);
    }
}

int land_buy_cycle(Land* gameboard, Player *p, int pos){
    int lap = p->lap;
    int level = gameboard[pos].level;
}

int land_upgrade_cycle(Land* gameboard, Player *p, int pos){

}

int land_cycle(Land* gameboard, Player* p, int pos){
    int land_owner = gameboard[pos].label;
    if (land_owner == NO_ONE){

    }
    else if (land_owner == p->label){

    }
    else if (land_owner != p->label){

    }
}

int cycle(Land* gameboard, Player* p){
    int pos, land_owner, label, double_count = 0;
    Dice dice;

    label = p->label;
    while (1){
        dice = dice_roll();
        double_count += determine_double(dice);
        if (double_count >= 2) {
            player_move_toward(p, ABANDONED_ISLAND);
            return 1;
        }

        if (gameboard[pos].land_type == NORMAL_TYPE){
            land_owner = gameboard[pos].label;
            if (land_owner == NO_ONE);
            if (land_owner == label);
            if (land_owner != label && land_owner != NO_ONE);
        }

        if (determine_double(dice) == NORMAL) break;
    }
    return 0;
}