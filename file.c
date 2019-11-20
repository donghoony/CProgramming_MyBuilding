//
// Created by DongHoony on 2019-11-20.
//
#include <malloc.h>
#include <stdio.h>
#include "land.h"
#include <string.h>
// returns Land* array => Land**
Land** file_get_land_info(){
    char c;
    Land* current_land_addr;
    int land_price, land_number, i;
    char land_name[100], landmark_name[100];
    Land* land_array = (Land*) malloc(sizeof(Land) * 22);

    FILE* f = fopen("C:\\Users\\DongHoony\\CLionProjects\\KONKUK\\CProgramming_TeamProject_MyBuilding\\File", "r");
    if (f == NULL){
        printf("NULLPTR");
        return NULL;
    }
    while (1){
        c = fgetc(f);
        if(c == '!') break;
        else printf("%c", c);
    }
    for(i = 0; i < 22; i++){
        fscanf(f, "%d", &land_number);
        fscanf(f, "%s", land_name);
        fscanf(f, "%d", &land_price);
        fscanf(f, "%s", landmark_name);
        current_land_addr = &land_array[land_number];
        current_land_addr->name = (char*) malloc(sizeof(char) * strlen(land_name) + 1);
        strcpy(current_land_addr->name, land_name);
        current_land_addr->land_position = land_number;
        current_land_addr->land_price = land_price;
        current_land_addr->landmark_name = landmark_name;
    }
    return &land_array;
}