//
// Created by DongHoony on 2019-11-29.
//

#include <stdlib.h>
#include "player.h"
#include "random.h"
#include "money.h"
#include "show.h"

/*
 * Roll dice
 *
 *
 *
 * */

int dice_cycle(Land* gameboard, Player* p){
    int d1, d2;
    int dice_value, i;

    d1 = rand_roll_dice_only();
    d2 = rand_roll_dice_only();

    dice_value = d1 + d2;

    for(i = 0; i < dice_value; i++){

        show_player_move(gameboard, p, p->position, (p->position + 1) % 21);
        player_move(p, 1);

        if (p->position == 22) {
            money_get_income(p);
            p->position = 0;
        }

        _sleep(100);
    }

}

int cycle(Player* p){
}