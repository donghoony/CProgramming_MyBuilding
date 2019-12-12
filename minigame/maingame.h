#include "class.h"

#define GAME_NUMBER 1

int SetBet(int* bet);
int ChooseGame();
int PlayMaingame();
int PlayHeadOrTail(int bet, int* multiple, int* win_or_lose);
int HeadOrTail0(int* menu, int*guess, GameObject* SystemMenu, GameObject* SystemCursor, GameObject* Player);
int HeadOrTail1(int* menu, GameObject* SystemMenu, GameObject* Coin);
int HeadOrTail2(int* menu, GameObject* SystemMenu);