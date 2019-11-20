//
// Created by DongHoony on 2019-11-20.
//

#ifndef KONKUK_MONEY_H
#define KONKUK_MONEY_H

#endif //KONKUK_MONEY_H
#include "player.h"

void money_spend(Player p, int value);
void money_earn(Player p, int value);
void money_trade(Player p_from, Player p_to, int value);
void money_get_income(Player p); //-> earn_money로 가져옴
void money_get_rent_fee(Player p, Land);
