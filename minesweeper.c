#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

// 숫자를 받는다, scanf에서 발생할 예외를 처리한다
// get_number의 끝에서 num을 초기화해줘야한다.
int get_number(char num[], int size);

// difficulty에 따라서 할당된 배열의 포인터를 main으로 넘겨준다.
// 배열의 크기가 다양할 수 있으므로 동적할당으로 해 준다.
// 선욱
int* init(int difficulty);


// 2차원 배열의 주소를 넘긴다
// 재욱
void set_mine(int ***mine_board, int difficulty, int mine_num);

// int 반환, 1이면 폭탄 0이면 정상, 재귀구현 필요,
// 깃발 누르면 아무일 없음
// 숫자 누르면 깃발개수 확인 후 주변 다 열기
// 이미 열린 곳 눌러도 아무 일 없음
// 현희
int open_cell(int ***player_board, int ***mine_board, int r, int c);

//주변 8칸의 지뢰 개수 반환 - 광일
int get_neighbor_mine_cnt(int ***mine_board, int r, int c);




//


//



int main(){
    // Random
    srand((unsigned)time(NULL));

    int row, col, difficulty, mine_cnt, win, pressed_key;
    char num[SIZE] = "";

//    difficulty = get_number(num, SIZE);






}
