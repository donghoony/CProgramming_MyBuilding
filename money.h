//
// Created by DongHoony on 2019-11-20.
//
#pragma once

#ifndef KONKUK_MONEY_H
#define KONKUK_MONEY_H

#endif //KONKUK_MONEY_H
#define SALARY 1000

#include "land.h"

#define NOT_OK -1
#define OK 0

int money_spend(Player*, int);
void money_earn(Player* p, int value);
int money_trade(Player* p_from, Player* p_to, int value);
void money_get_income(Player* p); //-> earn_money로 가져옴
//void money_get_rent_fee(Player* p, Land l);
//void all_Comland_rent_fee(Land* l,Player* p,Resident r);
void all_Myland_rent_fee(Land* l,Player* p,Resident r);
int enemy_land_spend(Player* p,int value);
int col_land_price(Land* l);
int money_compare(int have, int need);