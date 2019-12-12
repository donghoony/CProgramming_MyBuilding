#include "../header_files/player.h"
#include "../header_files/money.h"
#include "../header_files/land.h"
#include "../header_files/show.h"
#include "../header_files/gotoyx.h"
#include "../header_files/cycle.h"
#include <stdlib.h>
#include <time.h>

int money_spend(Player* p, int value){//단순 돈 관리
   int i, cur_money = p->money;
   if (p->money < value) return NOT_OK;
   for(i = cur_money; i > cur_money - value; i -= 10){
       p->money -= 10;
       show_money_update(p, FALSE);
       if (i % 250 == 0)_sleep(20);
   }
   show_money_normal_update(p);
   return OK;
}
void money_earn(Player* p, int value){
    int i, cur_money = p->money;
    for(i = cur_money; i < cur_money+value; i+=10){
        p->money += 10;
        show_money_update(p, TRUE);
        if (i % 250 == 0)_sleep(20);
    }
    show_money_normal_update(p);
    return;
}
int money_trade(Player* p_from, Player* p_to, int value){
    int i, cur_money = p_from->money;
    for(i = cur_money; i < cur_money + value; i+=10){
        if (p_from->money < 0) return NOT_OK;
        p_from->money -= 10;
        p_to->money += 10;
        show_money_update(p_from, FALSE);
        show_money_update(p_to, TRUE);
        if (i % 250 == 0) _sleep(20);
    }
    show_money_normal_update(p_from);
    show_money_normal_update(p_to);
    return OK;
}

void money_get_income(Player* p){
    money_earn(p, SALARY);
}
int money_compare(int have, int need){
    return (have >= need) ? OK : NOT_OK;
}
int find_festival_pos(Land* gameboard){ //어디가 원래 페스티벌 개최지인지 확인하는 함수
    int i, sum = 0;
    for(i = 0; i < MAX_TILE; i++){
        if(gameboard[i].land_multiply > 1){
            sum = i;
            break;
        }
    }
    return sum;
}

// land_calculate_cost 있음
//int col_land_price(Land* land){
//	int i;
//	int sum = 0;
//	const double MULTIPLY_FEE[5] = {1.0, 1.1, 1.3, 1.5, 1.7};
//	for(i = 0; i < 5; i++){
//		if(land->level[i] == 0){
//			sum += land->land_price * MULTIPLY_FEE[i];
//		}
//	}
//	sum *= land->land_multiply;
//	return sum;
//}

int make_festival(Land* gameboard,Player* p){//내 땅중 랜덤하게 하나 선택//페스티벌 지역 설정
	int i, cnt =0 ;
	srand((unsigned)time(NULL));
    for(i = 0; i < MAX_TILE; i++) if (gameboard[i].label == p->label) cnt++;
    if (cnt == 0) return START_LAND;
	while(1){
		i = rand() % MAX_TILE;
		if(p->label == gameboard[i].label) break;
	}
	return i;
}

int col_festival(Land* gameboard,Player* p){ //2배설정함수
	int origin_pos = find_festival_pos(gameboard); //원래 페스티벌 지역
	int new_pos = make_festival(gameboard, p); //새로운 페스티벌 장소
	if(origin_pos != new_pos) gameboard[origin_pos].land_multiply = 1;
    gameboard[new_pos].land_multiply *= 2;
    return new_pos;
}

int all_land_rent_fee(Land* l,Player* p, Resident* r){ //모든 땅에 대한 임대료
    int i, sum = 0, price;
    for(i=0; i < MAX_TILE; i++){
        price = l[i].land_price/100;
        if(l[i].label == p->label){
            sum += price * r->rand_person_villa[i];
            sum += price * r->rand_person_building[i] * 2;
            sum += price * r->rand_person_hotel[i] * 3;
            sum += price * r->res_person_landmark[i] * 5;
        }
    }
    sum *= 10;
    gotoyx(33, 70);
    printf("RES : %d", sum);
    return sum;
}
