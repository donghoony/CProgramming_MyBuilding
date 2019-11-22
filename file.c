//
// Created by DongHoony on 2019-11-20.
//
#include <malloc.h>
#include <stdio.h>
#include "land.h"
#include <string.h>

#define START_CHAR '!'

int is_nullptr(FILE* f){
    if (f == NULL){
        printf("NULLPTR\n");
        return 1;
    }
    else return 0;
}

void get_chars_until_specific_char(FILE* f, char specific_char){
    char c;
    while (1){
        c = fgetc(f);
        if(c == specific_char) break;
        else printf("%c", c);
    }
}

// returns Land* array => Land**
Land* file_get_land_info(){
    int land_price, land_number, i;
    char land_name[100], landmark_name[100];
    Land temp_land;
    // land tmp;
    // land array <Struct array>
    Land* land_array = (Land*) malloc(sizeof(Land) * 21);

    // LAND_INFO
    FILE* f = fopen("C:\\Users\\DongHoony\\CLionProjects\\KONKUK\\CProgramming_TeamProject_MyBuilding\\LAND_INFO", "r");

    if (is_nullptr(f)) return NULL;
    get_chars_until_specific_char(f, START_CHAR);

    for(i = 0; i < 21; i++){
        memset(land_name, 0x0, 100);
        memset(landmark_name, 0x0, 100);

        fscanf(f, "%d", &land_number);
        fscanf(f, "%s", land_name);
        fscanf(f, "%d", &land_price);
        fscanf(f, "%s", landmark_name);

        temp_land.name = (char*) malloc(sizeof(char) * strlen(land_name) + 1);
        strcpy(temp_land.name, land_name);
        temp_land.landmark_name = (char*) malloc(sizeof(char) * strlen(landmark_name) + 1);
        strcpy(temp_land.landmark_name, landmark_name);
        temp_land.land_price = land_price;
        temp_land.land_position = land_number;
        land_array[i] = temp_land;

        // test codes below
        /*
        tmp = land_array[i];
        printf("%d %s %d %s\n", tmp.land_position, tmp.name, tmp.land_price, tmp.landmark_name);
        */
        //test code ends

    }
    fclose(f);
    return land_array;
}

int file_get_land_pos(Land **land_arr_addr){
    Land* arr = *land_arr_addr;
    FILE* f = fopen("C:\\Users\\DongHoony\\CLionProjects\\KONKUK\\CProgramming_TeamProject_MyBuilding\\LAND_POS_INFO", "r");


    fclose(f);
}