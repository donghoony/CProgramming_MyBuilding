//
// Created by DongHoony on 2019-11-20.
//


#ifndef KONKUK_LAND_H
#define KONKUK_LAND_H

#endif //KONKUK_LAND_H

// land.h -> 재욱
typedef struct land{
    int land_position;
    char* name;
    int land_price;
    int land_multiply; //배수 설정 (페스티벌)
    int label; //누구건지 0, 1, 2
    int level; // 0000 -> 2진수를 통한 별장, 빌딩, 호텔, 랜드마크 여부
}Land;


int land_buy(Player*, Land*, int);
//-> 반환값 따라서 성공여부