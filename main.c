#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>

#include "show.h"
#include "player.h"
#include "gotoyx.h"


int main() {
    show_gameboard_grid();


    gotoyx(0, 0);
    getch();

}
