//
// Created by DongHoony on 2019-12-03.
//

//
// Created by DongHoony on 2019-11-20.
//

#include "player.h"
#include "land.h"
#include "resident.h"

#define ????_value 1.3
#define ????_value 1.5
#define ???_value 1.7
#define ???Óá?_value 2

#define NOT_OK -1
#define OK 0

int land_buy(Player* user, Land* l){
    int number=0;
    int i=0;
    l->level=0;

    while(1) {
        land_buy_menu();
        scanf_s("%d", &number);
        if(number>4 || number<0) printf("0~4 ???? ???? ???? ??? ?????????? \n");

        if(user->lap==0) {
            if(number>0 && number<=4) printf("? ??¡Æ lap?????? ????? ???? ?? ???????! \n");
            else if(number==0)  {
                buy_only_land(&user, &l, i); break;
            }
        }

        if(user->lap==1) {
            if(number>1 && number<=4) printf("?? ??¡Æ lap?????? ???? ????? ????? ???? ?? ???????! \n");
            else if(number==0) 	{
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i); break;
            }
        }
        if(user->lap==2) {
            if(number>2 && number<=4) printf("?? ??¡Æ lap?????? ??? ????? ????? ???? ?? ???????! \n");
            else if(number==0) 	{
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i);  break;
            }
            else if(number==2) {
                buy_building(&user, &l, &i); break;
            }
        }

        if(user->lap==3) {
            if(number==4) printf("?? ??¡Æ lap?????? ???Óá??? ???? ?? ???????! \n");
            else if(number==0) {
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i); break;
            }
            else if(number==2) {
                buy_building(&user, &l, &i); break;
            }
            else if(number==3) {
                buy_hotel(&user, &l, &i); break;
            }
        }

        if(user->lap==4) {
            if(number==0) {
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i);  break;
            }
            else if(number==2) {
                buy_building(&user, &l, &i);  break;
            }
            else if(number==3) {
                buy_hotel(&user, &l, &i); break;
            }
            else if(number==4) {
                buy_landmark(&user, &l, &i); break;
            }
        }
    }
}

void buy_only_land(Player *user, Land *l, int i) {
    i = money_spend(&user, l->land_price);
    if(i==-1) printf("???? ????????! \n");
    else if(i==0) {
        printf("???? ????????! \n");
        l->level = 1;
    }
}

void buy_villa(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*????_value);
    if(i==-1) printf("???? ????????! \n");
    else if(i==0) {
        printf("?????? ????????! \n");
        rand_person_villa(&user, &people);
        l->level = 2;
    }
}

void buy_building(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
        buy_villa(&user, &l, i);
    }
    else if(l->level==1) {
        buy_villa(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*????_value);
    if(i==-1) printf("???? ????????! \n");
    else if(i==0) {
        printf("?????? ????????! \n");
        rand_person_building(&user, &people);
        l->level = 3;
    }
}

void buy_hotel(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
    }
    else if(l->level==1) {
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
    }
    else if(l->level==2) {
        buy_building(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*???_value);
    if(i==-1) printf("???? ????????! \n");
    else if(i==0) {
        printf("????? ????????! \n");
        rand_person_hotel(&user, &people);
        l->level = 4;
    }
}

void buy_landmark(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
        buy_hotel(&user, &l, i);
    }
    else if(l->level==1) {
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
        buy_hotel(&user, &l, i);
    }
    else if(l->level==2) {
        buy_building(&user, &l, i);
        buy_hotel(&user, &l, i);
    }
    else if(l->level==3) {
        buy_hotel(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*???Óá?_value);
    if(i==-1) printf("???? ????????! \n");
    else if(i==0) {
        printf("???Óá??? ????????! \n");
        l->level = 5;
    }
}

void land_buy_menu() {
    printf("==========?©ª? ??? ????==========\n");
    printf("0. ???? ???? \n");
    printf("1. ???? \n");
    printf("2. ???? \n");
    printf("3. ??? \n");
    printf("4. ???Óá? \n");
    printf("===================================\n");
}
