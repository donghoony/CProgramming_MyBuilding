//
// Created by DongHoony on 2019-11-20.
//

#pragma  once
typedef struct player{
    int money;
    int position;
    int label; //->identify bot or not
    int lap; // 몇 바퀴 돌았는지
}Player;

void player_move(Player* p, int move_value);