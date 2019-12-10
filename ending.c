#include "ending.h"
#include "gotoyx.h"
#include <Windows.h>
#define MAX 40

void show_ending(End e[],int index){//아마 재귀함수로 가야할듯
	int i;
	system("cls");
	for(i=0;i<index+1;i++){
		//if(index>49) j++;
		e[i].y_pos=MAX-(index-i);
		if(e[i].y_pos>=0){
		    gotoyx_print(e[i].y_pos, e[i].x_pos, e[i].word);
		}
		if(i==49 && e[i].y_pos<0) break;
		}
	Sleep(500);
	show_ending(e,index+1);
}