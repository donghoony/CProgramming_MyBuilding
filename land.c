//
// Created by DongHoony on 2019-11-20.
//

#include <stdlib.h>
#include "player.h"
#include "land.h"
#include "resident.h"
#include "money.h"

// suppose player has enough money  (functions below)

int land_buy_build(Player* p, Land* land, Resident* r, int level){
    const int PEOPLE[] = {0, 0, 2, 3, 4};
    int pos = land->land_position;
    land->label = p->label;
    if (level == ONLY_LAND) return OK;
    r->resident_info[level-1][pos] = rand() % PEOPLE[level] + 1;
}
/*
int land_buy_only_land(Player* p, Land* land, Resident* r){
    land->label = p->label;
}


int land_buy_villa(Player* p, Land* land, Resident* r){
    int pos = land->land_position;
    land->label = p->label;
    rand_person_villa(p, r);
}

int land_buy_building(Player* p, Land* land, Resident* r){

}

int land_buy_hotel(Player* p, Land* land, Resident* r){

}

int land_buy_landmark(Player* p, Land* land, Resident* r){

}

int land_check_valid(){

}
*/
// 1.0 1.2 1.5 1.7 2.0

// level은 ONLY_LAND, VILLA, BUILDING, HOTEL, LANDMARK로 전달할 것!
int land_buy(Player* p, Land* land, Resident* res, int level){
    // [12345 land villa building hotel landmark
    // User buys land with level
    const double MULTIPLY[] = {0, 1.0, 1.2, 1.5, 1.7, 2.0};
    int price = land->land_price * MULTIPLY[level];
    // if you have enough money
    if (money_compare(p->money, price)){
        land_buy_build(p, land, res, level);
        money_spend(p, price);
        return OK;
    }
    else return NOT_OK;
}