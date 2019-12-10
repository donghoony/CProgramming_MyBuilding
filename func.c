#include "ending_file.h"
#include "func.h"
int ending_credit(){
	End e[100] = {{0, 0, '\0'}};
	open_word(e);
	open_x(e);
	open_y(e);
	show_ending(e,0);
	return 0;
}