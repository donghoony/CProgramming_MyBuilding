//
// Created by DongHoony on 2019-11-20.
//

#include "player.h"
#include "land.h"
#include "resident.h"

#define 별장_value 1.3
#define 빌딩_value 1.5
#define 호텔_value 1.7
#define 랜드마크_value 2

#define NOT_OK -1
#define OK 0

int land_buy(Player* user, Land* l){
	int number=0;
	int i=0;
	l->level=0;

	while(1) {
	land_buy_menu();
	scanf_s("%d", &number);
	if(number>4 || number<0) printf("0~4 범위 안의 수로 다시 입력해주세요 \n");

	if(user->lap==0) {
		if(number>0 && number<=4) printf("첫 번째 lap에서는 건물을 세울 수 없습니다! \n");
		else if(number==0)  {
			buy_only_land(&user, &l, i); break;
		}
	}

	if(user->lap==1) {
		if(number>1 && number<=4) printf("두 번째 lap에서는 빌딩 이상의 건물을 세울 수 없습니다! \n");
		else if(number==0) 	{
			buy_only_land(&user, &l, &i); break;
		}
		else if(number==1) {
			buy_villa(&user, &l, &i); break;
		}
	}
	if(user->lap==2) {
		if(number>2 && number<=4) printf("세 번째 lap에서는 호텔 이상의 건물을 세울 수 없습니다! \n");
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
		if(number==4) printf("네 번째 lap에서는 랜드마크를 세울 수 없습니다! \n");
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
		if(i==-1) printf("돈이 부족합니다! \n");
		else if(i==0) {
			printf("땅을 구매합니다! \n");
			l->level = 1;
	}
}

void buy_villa(Player *user, Land *l, int i) {
	if(l->level==0) {
		buy_only_land(&user, &l, i);
	}
	i = money_spend(&user, (l->land_price)*별장_value);
	if(i==-1) printf("돈이 부족합니다! \n");
		else if(i==0) {
			printf("별장을 구매합니다! \n");
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
	i = money_spend(&user, (l->land_price)*빌딩_value);
	if(i==-1) printf("돈이 부족합니다! \n");
		else if(i==0) {
			printf("빌딩을 구매합니다! \n");
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
	i = money_spend(&user, (l->land_price)*호텔_value);
	if(i==-1) printf("돈이 부족합니다! \n");
		else if(i==0) {
			printf("호텔을 구매합니다! \n");
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
	i = money_spend(&user, (l->land_price)*랜드마크_value);
	if(i==-1) printf("돈이 부족합니다! \n");
		else if(i==0) {
			printf("랜드마크를 구매합니다! \n");
			l->level = 5;
	}
}

void land_buy_menu() {
	printf("==========올릴 건물 선택==========\n");
	printf("0. 땅만 구매 \n");
	printf("1. 별장 \n");
	printf("2. 빌딩 \n");
	printf("3. 호텔 \n");
	printf("4. 랜드마크 \n");
	printf("===================================\n");
}
