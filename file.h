//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#ifndef KONKUK_FILE_H
#define KONKUK_FILE_H

#endif //KONKUK_FILE_H

int is_nullptr(FILE* f);
void get_chars_until_specific_char(FILE* f, char specific_char);
Land** file_get_land_info();
int file_get_land_pos(Land **land_arr_addr);
