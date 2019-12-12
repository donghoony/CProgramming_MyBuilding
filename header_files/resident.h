#pragma once
#include <stdio.h>

#define MAX_TILE 22

typedef struct resident {
	int rand_person_villa[MAX_TILE];
	int rand_person_building[MAX_TILE];
	int rand_person_hotel[MAX_TILE];
	int res_person_landmark[MAX_TILE];
	int* resident_info[4];
}Resident;

int res_set_residents(Resident* r, int pos, int level);
int res_set_landmark_residents(Resident* r, int pos);