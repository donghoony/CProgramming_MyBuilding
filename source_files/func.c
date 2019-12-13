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