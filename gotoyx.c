//
// Created by DongHoony on 2019-11-20.
//

#include <wincon.h>
#include <winbase.h>
#include <stdio.h>

void gotoyx(int y, int x){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gotoyx_print(int y, int x, char* arg){
    gotoyx(y, x);
    printf("%s", arg);
}