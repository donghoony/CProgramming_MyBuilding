#include "../header_files/ending.h"
#include "../header_files/gotoyx.h"
#include <string.h>
#include <windows.h>

#define MAX 40
void show_ending(End e[],int index){ //아마 재귀함수로 가야할듯
	int i;
	if(index == 69){
	    system("cls");
	    gotoyx_print(20, 51, "The End");
	    getchar();
	    return;
	}
    system("cls");
	for(i = 0; i < index+1; i++){
		e[i].y_pos = MAX - (index-i);
		if(e[i].y_pos>=0){
		    gotoyx_print(e[i].y_pos, e[i].x_pos, e[i].word);
		}
		if(i==49 && e[i].y_pos<0) break;
		}
	Sleep(200);
	show_ending(e,index+1);
}

void play_ending_credit_song() {
	PlaySound(TEXT(ending_credit_song), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | 1);
}