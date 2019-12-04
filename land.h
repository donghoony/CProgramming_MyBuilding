//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#include "player.h"
#include "resident.h"

#define START_LAND 0
#define ABANDONED_ISLAND 4
#define FESTIVAL 11
#define TRAVEL 15

#define NORMAL_TYPE 0
#define SPECIAL_TYPE 1

#define NOT_OK -1
#define OK 0

#define ONLY_LAND 1
#define VILLA 2
#define BUILDING 3
#define HOTEL 4
#define LANDMARK 5

typedef struct point{
    int y;
    int x;
}Point;


// land.h -> 재욱
typedef struct land{
    int land_position;
    char* name;
    char* landmark_name;
    int land_type; // NORMAL_TYPE, SPECIAL_TYPE - 일반 땅, 스페셜 땅
    int land_price;
    int land_multiply; //배수 설정 (페스티벌) - 1
    int label; //누구건지 NO_ONE, PLAYER, COMPUTER
    int level[5]; //별장, 빌딩, 호텔, 랜드마크 여부 (1~5) 0: 무소유 1: 땅만 보유 ~ 5: 랜드마크 보유
    // 땅 빌라 빌딩 호텔 랜마
    Point p_b1, p_b2, p_b3, p_player, p_bot;
}Land;

int land_buy(Player* user, Land* l, Resident* res, int level);

void land_buy_menu();