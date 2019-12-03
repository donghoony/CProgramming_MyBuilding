//
// Created by DongHoony on 2019-11-20.
//

#include "player.h"
#include "money.h"
#include "land.h"
#include<stdio.h>

#define NOT_OK -1
#define OK 0
#define SALARY 200

int money_spend(Player* p, int value){//단순 돈 관리
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


int enemy_land_spend(Player* p,int value){//적이나 내가 상대방의 땅을 걸릴시 돈을  지불하는 함수,소유권 확인
   int condition;
   condition=money_spend(p,value);//돈을 낼수 있는 상황인지 확인
   return condition;//ok or not
}
void start_pont_income(Player* p,Land l,int member){
   money_get_income(p);
   all_land_rent_fee(l,p,member);
}
void all_Myland_rent_fee(Land* l,Player* p,int member){//모든 땅에 대한 임대료 나
   int i;
   for(i=0;i<22;i++){
      if(l[i].label==1){
         p->money+=(l[i].land_price/100)*member;
      }
   }
}
void all_Comland_rent_fee(Land* l,Player* p,int member){//모든 땅에 대한 임대료 상대
   int i;
   for(i=0;i<22;i++){
      if(l[i].label==2){
         p->money+=(l[i].land_price/100)*member;
      }
   }
}