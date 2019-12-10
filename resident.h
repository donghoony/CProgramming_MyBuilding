#pragma once
#include <stdio.h>

#include "player.h"
#define MAX_TILE 22

typedef struct resident {
	int rand_person_villa[MAX_TILE];
	int rand_person_building[MAX_TILE];
	int rand_person_hotel[MAX_TILE];
	int res_person_landmark[MAX_TILE];
	int* resident_info[4];
}Resident;

void rand_person_villa(Player* user, Resident* people);
void rand_person_building(Player* user, Resident* people);
void rand_person_hotel(Player* user, Resident* people);
