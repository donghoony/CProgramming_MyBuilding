
#pragma once
#include "resident.h"
#include "player.h"

void rand_person_villa(Player* user, Resident* people) {
	people->rand_person_villa[user->position] = rand() % 2 + 1;
}
void rand_person_building(Player* user, Resident* people) {
	people->rand_person_building[user->position] = rand() % 3 + 1;
}
void rand_person_hotel(Player* user, Resident* people) {
	people->rand_person_hotel[user->position] = rand() % 4 + 1;
}