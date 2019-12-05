
#include <stdlib.h>
#include "resident.h"
#include "player.h"
#include <memory.h>

//no need since we initialize on main at first
//void resident_init(Resident* res_list){
//    memset(res_list, 0x0, sizeof(res_list));
//    res_list->resident_info[0] = res_list->rand_person_villa;
//    res_list->resident_info[1] = res_list->rand_person_building;
//    res_list->resident_info[2] = res_list->rand_person_hotel;
//}

void rand_person_villa(Player* user, Resident* people) {
	people->rand_person_villa[user->position] = rand() % 2 + 1;
}
void rand_person_building(Player* user, Resident* people) {
	people->rand_person_building[user->position] = rand() % 3 + 1;
}
void rand_person_hotel(Player* user, Resident* people) {
	people->rand_person_hotel[user->position] = rand() % 4 + 1;
}