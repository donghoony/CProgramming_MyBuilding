#include <windef.h>
#include <wincon.h>
#include <pbt.h>
#include "../header_files/ending_file.h"
#include "../header_files/func.h"
int ending_credit(){
	End e[100] = {{0, 0, '\0'}};
	open_word(e);
	open_x(e);
	open_y(e);
	play_ending_credit_song();
	show_ending(e,0);
	return 0;
}

void ending(){
    HWND hwnd = GetConsoleWindow();
    play_ending_credit_song();
    if (hwnd != NULL) MoveWindow(hwnd, 0, 0, 1430, 1700, TRUE);
    ending_credit();
}