//file.h
void file_get_land_info();

//player.h -> 선욱
typedef player(){
	int money;
	int position;
	char* name;
	int label; //->identify bot or not
	int lap; // 몇 바퀴 돌았는지
}Player;
void player_move(Land from, Land to);

//random.h
int rand_roll_dice();
int rand_house_person();

// land.h -> 재욱
typedef struct land(){
	int land_position;
	char* name;
	int land_price;
	int land_multiply; //배수 설정 (페스티벌)
	int label; //누구건지 0, 1, 2
	int level; // 0000 -> 2진수를 통한 별장, 빌딩, 호텔, 랜드마크 여부
}Land;

int land_buy(Player p, Land l, int level); 
//-> 반환값 따라서 성공여부

// money.h -> 김광일
void money_spend(Player p, int value);
void money_earn(Player p, int value);
void money_trade(Player p_from, Player p_to, int value);
void money_get_income(Player p); //-> earn_money로 가져옴
void money_get_rent_fee(Player p, Land);

//show.h
void show_land_info(Land);
void show_gameboard(Land* gameboard);

//gotoyx.h
void gotoyx(int y, int x);
void gotoyx_print(int y, int x, char* arg);

//minigame.h -> 현희
int minigame_oddeven(Player, int level); //-> 3레벨까지 진행가능 (재귀)





