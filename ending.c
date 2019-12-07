#include<stdio.h>
#include"gotoxy.h"
#include"ending.h"
#include"file.h"
#include<Windows.h>
#define MAX 40
#include<time.h>

void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void show_ending(End e[],int index){//아마 재귀함수로 가야할듯
	int i;
	int j=0;
	system("cls");
	for(i=0;i<index+1;i++){
		//if(index>49) j++;
		e[i].y_pos=MAX-(index-i);
		if(e[i].y_pos>=0){
			gotoxy(e[i].x_pos,e[i].y_pos);
			printf("%s",e[i].word);	
		}
		if(i==49 && e[i].y_pos<0) break;
		}
	Sleep(500);
	show_ending(e,index+1);
}