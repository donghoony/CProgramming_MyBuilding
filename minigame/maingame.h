#include "class.h"

#define GAME_NUMBER 1

int SetBet(int* bet);
int ChooseGame();
int GoOrStop(int* go_or_stop);

int PlayHeadOrTail(int bet, int* multiple, int* win_or_lose);
int HeadOrTail0(int* guess, int* menu, GameObject* SystemMenu, GameObject* SystemCursor, GameObject* Player);
int HeadOrTail1(int* menu, GameObject* SystemMenu, GameObject* Coin);
int HeadOrTail2(int* menu, int* guess, int* win_or_lose, int* multiple, GameObject* SystemMenu, GameObject* Coin, GameObject* Player);
int PlayShellGame(int bet, int* multiple, int* win_or_lose);
int SetResult(int*multiple, int* bet, int* win_or_lose);
