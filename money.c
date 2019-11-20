//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#include "player.h"
#include "money.h"

#define NOT_OK -1
#define OK 0
int money_spend(Player* p, int value){
   if (p->money < value) return NOT_OK;
   p->money -= value;
   return OK;
}
void money_earn(Player* p, int value){
    p->money += value;
    return;
}
int money_trade(Player* p_from, Player* p_to, int value){
    int ret;
    ret = money_spend(p_from, value);
    if (ret == NOT_OK) return NOT_OK;
    money_earn(p_to, value);
    return OK;
}

void money_get_income(Player* p){
    money_earn(p, SALARY);
} //-> earn_money로 가져옴

void money_get_rent_fee(Player* p, Land l){

}
