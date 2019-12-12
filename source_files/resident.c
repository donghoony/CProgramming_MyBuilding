#include <stdlib.h>
#include "../header_files/resident.h"

int res_set_residents(Resident* r, int pos, int level){
    const int PEOPLE[] = {0, 2, 3, 4};
    int book_people;
    book_people = rand() % PEOPLE[level] + 1;
    *((r->resident_info[level-1]) + pos) = book_people;
    return book_people;
}

int res_set_landmark_residents(Resident* r, int pos){
    int book_people;
    book_people = r->rand_person_hotel[pos] + r->rand_person_building[pos] + r->rand_person_villa[pos];
    r->res_person_landmark[pos] = book_people;
    return book_people;
}