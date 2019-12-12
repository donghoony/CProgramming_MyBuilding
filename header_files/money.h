#pragma once

#ifndef KONKUK_MONEY_H
#define KONKUK_MONEY_H

#endif //KONKUK_MONEY_H

#include "land.h"
#include "basic_const.h"

#define SALARY 20000
int money_spend(Player*, int);
void money_earn(Player* p, int value);
int money_trade(Player* p_from, Player* p_to, int value);
void money_get_income(Player* p); //-> earn_money로 가져옴
int all_land_rent_fee(Land* l,Player* p, Resident* r);
int money_compare(int have, int need);
int find_festival_pos(Land* l);
int make_festival(Land* gameboard,Player* p);
int col_festival(Land* gameboard,Player* p);

//int col_land_price(Land* l);