//
// Created by DongHoony on 2019-11-20.
//

#include <wincon.h>
#include <winbase.h>

void gotoyx(int y, int x){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gotoyx_print(int y, int x, char* arg);