#include <stdio.h>
#include <stdlib.h>

#include "show.h"
#include "player.h"
#include "gotoyx.h"
#include "file.h"

int main() {
    int i;
    Land** gameboard = file_get_land_info();
    Land* c_land;
    for(i = 0; i < 22; i++){
        c_land = &(*gameboard)[i];
        printf("%s(%d) : %d <%s>\n", c_land->name, i+1, c_land->land_price, c_land->landmark_name);
    }

    system("pause");
}
