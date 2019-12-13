#include "..\\header_files\\class.h"

#define GAME_NUMBER 1
#define BASE_MONEY 5000

int SetBet();
int ChooseGame();
int GoOrStop(int* go_or_stop);
int PlayMaingame();
int PlayHeadOrTail(int* multiple, int* win_or_lose);
int HeadOrTail0(int* guess, int* menu, GameObject* SystemMenu, GameObject* SystemCursor, GameObject* Player);
int HeadOrTail1(int* menu, GameObject* SystemMenu, GameObject* Coin);
int HeadOrTail2(int* menu, int* guess, int* win_or_lose, int* multiple, GameObject* SystemMenu, GameObject* Coin, GameObject* Player);
int PlayShellGame(int* multiple, int* win_or_lose);
int SetResult(int*multiple, int* win_or_lose);
int Square(int num, int times);