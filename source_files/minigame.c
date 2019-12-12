

#include <stdlib.h>
#include <conio.h>
#include "../header_files/player.h"
#include "../header_files/basic_const.h"
#include "../header_files/gotoyx.h"
#include "../header_files/show.h"

int minigame_win_continue(int level){
    int choice = TRUE;
    int key;
    const int WIN_RATE[] = {80, 70, 60};
    if (level == 0) {
        gotoyx_print(20, 72, "80%");
    }
    else {
        gotoyx_set_color(C_GREEN);
        gotoyx_print(20, 55, "Continue?    WIN RATE : ");
        printf("%d%%", WIN_RATE[level]);
        gotoyx_print(21, 50, "弛          VV            --         弛");
        gotoyx_print(22, 50, "弛          GO           STOP        弛");

    }
    while(1){
        key = getch();
        if (key == KEY_ENTER) break;
        if (key == KEY_INTRO){
            key = getch();
            if (key == KEY_LEFT || key == KEY_RIGHT) {
                choice = (choice == TRUE) ? FALSE : TRUE;
                gotoyx_print(21, 61, (choice == TRUE) ? "VV" : "--");
                gotoyx_print(21, 75, (choice == TRUE) ? "--" : "VV");
            }
        }
    }
    return choice;
}

void show_minigame_grid(){
    gotoyx_set_color(C_GREEN);
    gotoyx_print(18, 50, "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
    gotoyx_print(19, 50, "弛             COIN FLIP !           弛");
    gotoyx_print(20, 50, "弛          WIN RATE :               弛");
    gotoyx_print(21, 50, "弛          VV            --         弛");
    gotoyx_print(22, 50, "弛          GO           STOP        弛");
    gotoyx_print(23, 50, "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
}

void show_minigame_flip(int win){
    int i;
    const char* FLIP_MOTION[] = {"|", "/", "-", "\\"};
    for (i = 0; i < 4; i++) gotoyx_print(19 + i, 50, "弛                                   弛");
    for(i = 0; i < 15; i++){
        gotoyx_print(21, 68, FLIP_MOTION[i%4]);
        _sleep(100);
    }
    if (win == TRUE) {
        gotoyx_print(20, 60, "CORRECT ! ");
        _sleep(1000);
    }
    else {
        gotoyx_print(20, 60, "FAILED !!");
        _sleep(1000);
        for(i = 0; i < 6; i++) gotoyx_print(18 + i, 50, "                                     ");
    }
}

int minigame_oddeven(int level){
    const int WIN_RATE[] = {80, 70, 60};
    int win, next_continue = FALSE, i;
    if (level > 2) return level;
    if (level == 0){
        next_continue = minigame_win_continue(level);
        if (next_continue == FALSE) {
            for(i = 0; i < 6; i++) gotoyx_print(18 + i, 50, "                                     ");
            gotoyx_set_color(C_WHITE);
            return 0;
        }
    }
    win = (WIN_RATE[level] >= rand() % 99) ? TRUE : FALSE;
    show_minigame_flip(win);
    if (level == 2) for(i = 0; i < 6; i++) gotoyx_print(18 + i, 50, "                                     ");


    gotoyx_set_color(C_WHITE);
    if (win == TRUE){
        level++;
        if (level < 3) next_continue = minigame_win_continue(level);
        else next_continue = FALSE;

        if (next_continue == TRUE) return minigame_oddeven(level);
        else return level;
    }

    else return 0;
}

int minigame_init(){
    int win_cnt;
    show_minigame_grid();
    win_cnt = minigame_oddeven(0);

    return win_cnt;
}

