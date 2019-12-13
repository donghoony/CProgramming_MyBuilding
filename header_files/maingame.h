#include "..\\header_files\\class.h"

#define GAME_NUMBER 1
#define BASE_MONEY 500

int SetBet();
int ChooseGame();
int GoOrStop();
int PlayHeadOrTail();
int HeadOrTail0(GameObject* SystemMenu, GameObject* SystemCursor, GameObject* Player);
int HeadOrTail1(GameObject* SystemMenu, GameObject* Coin);
int HeadOrTail2(int* guess, GameObject* SystemMenu, GameObject* Coin, GameObject* Player);
//int PlayShellGame(int* multiple, int* win_or_lose);