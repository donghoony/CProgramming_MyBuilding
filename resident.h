#pragma once
#include <stdio.h>
#include "player.h"

typedef struct resident {
	int rand_person_villa[21];
	int rand_person_building[21];
	int rand_person_hotel[21];
}Resident;

void rand_person_villa(Player* user, Resident* people);
void rand_person_building(Player* user, Resident* people);
void rand_person_hotel(Player* user, Resident* people);
