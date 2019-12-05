//
// Created by DongHoony on 2019-11-20.
//

#include <stdlib.h>
#include "player.h"
#include "land.h"
#include "resident.h"
#include "money.h"
#include "gotoyx.h"

// suppose player has enough money  (functions below)
int land_buy_build(Player* p, Land* land, Resident* r, int level){
    const char* STR[4] = {"T", "S", "M", "L"};
    const char* NUM[7] = {"0", "1", "2", "3", "4", "5", "6"};
    const int PEOPLE[] = {0, 2, 3, 4};
	int i, book_people;
	int x_pos[4] = {NULL, land->p_b1.x, land->p_b2.x, land->p_b3.x};
	int y_pos[4] = {NULL, land->p_b1.y, land->p_b2.y, land->p_b3.y};
    int label = p->label;
    int pos = land->land_position;

    gotoyx_print(35, 15, "LANDBUYBUILD FUNC");
    getchar();
    gotoyx_print(35, 15, "                  ");

    land->label = label;
	land->level[level] = 1; //해당 건물 소유함으로 변경
	if(level == ONLY_LAND-1) return OK;

	// level is 0-based
	if(level == 4) {
		for(i = 0; i < LANDMARK-1; i++) {
			r->resident_info[LANDMARK-1][pos] += r->resident_info[i][pos];
		}
	}
	else {
	    book_people = rand() % PEOPLE[level] + 1;
	    (r->resident_info[level-1])[pos] = book_people;
	}

    gotoyx_set_color(label == COMPUTER ? C_RED : C_BLUE);
	gotoyx_print(y_pos[level], x_pos[level], STR[level]);
	gotoyx_print(y_pos[level], x_pos[level] + 1, NUM[book_people]);
	gotoyx_set_color(C_WHITE);
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
// 이미 돈 충분하다고 가정한다
int land_buy(Player* p, Land* land, Resident* res, int level){
    // [12345] land villa building hotel landmark
    // User buys land with level
    const double MULTIPLY[] = {1.0, 1.2, 1.5, 1.7, 2.0};
    int price = land->land_price * MULTIPLY[level];
    // if you have enough money
    land_buy_build(p, land, res, level);
    return OK;
}


void land_check_label(Player* p,Land* land){//땅의 상태를 파악함(이미 내가 산땅, 상대땅, 빈땅)-> 각 상황에 맞게 함수를 불러와 해결(빈땅에 건물 짓는 함수,상대방한테 임대료 주는 함수, 원래 내땅에 건물 더 지을지 판단하는 함수)
	if(land->label==0);
	else if(land->label==p->label);
	else if(land->label!=p->label);
} //광일

int land_check_land(Land* land, int level) { //건물을 올리려면 반드시 땅을 보유중이어야 함을 확인해주는 함수
	int i=0;
	if(level > ONLY_LAND && land->level[ONLY_LAND-1] == 0) return NOT_OK;  //땅을 보유하지 않고 건물 올리는 경우 -1 반환
	else return OK; //그 외의 경우 1반환
}

int land_check_lap(Player* p, int level) {  //lap수에 따라 살 수 있는 건물 제한하는 함수   ->   굳이 함수로 처리 해야하는가에 대해서는 의문.
	if(p->lap + 1 >= level) return OK; 
	else return NOT_OK;
}

/*  랜드마크 지으려면 랜드마크 하위 건물들이 모두 존재해야 지을 수 있음.
int i=0, sum=0;
for(i=0; i<LANDMARK-1; i++) {
	sum += land->level[i];
}
if(sum == 4) return OK
else return NOT_OK;
*/
