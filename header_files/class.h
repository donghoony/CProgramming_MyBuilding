#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <malloc.h>
#include <stdlib.h>
#include "..\\header_files\\gotoyx.h"

/* 컴포넌트 관련 상수 */
#define COMPONENT_NUMBERS 7
#define RENDER_COMPONENT 0
#define INPUT_COMPONENT 1
#define ROLL_COMPONENT 2
#define TRIGGER_COMPONENT 3
#define ANIMATION_COMPONENT 4
#define TIME_COMPONENT 5
#define CURSOR_COMPONENT 6

/* 객체 관련 상수 */
#define PLAYER_GAMEOBJECT 100
#define COIN_GAMEOBJECT 101
#define SYSTEMMENU_GAMEOBJECT 102
#define SYSTEMCURSOR_GAMEOBJECT 103
#define SHELL_GAMEOBJECT 104

/* 키 관련 상수 */
#define RIGHT_ARROW 77
#define LEFT_ARROW 75
#define ENTER 13

/* 객체 */
typedef struct _GameObject{

	struct _GameObject* cthis;

	struct _ComponentBase** Component_Table;	//index번호가 component의 ID값이 될 NULL포인터 집합
	int GameObjectID;	//말 그대로 GameObject의 ID

	int (*InsertComponent)(struct _GameObject *cthis, int ComponentID, struct _ComponentBase* pComponentBase);	//Component_Table[ComponentID]에 ComponentBase*값을 넣음
	int (*DeleteComponent)(struct _GameObject *cthis, int ComponentID);	//Component_Table[ComponentID]의 값을 NULL로 초기화
	struct _ComponentBase* (*GetComponent)(struct _GameObject *cthis, int ComponentID);	//원하는 ID의 Component의 ComponentBase*로 형변환된 주소값 반환 -> 접근에 이용할 듯?

}GameObject;
typedef struct _ComponentBase{

	struct _ComponentBase *cthis;

	int ComponentID;	//Component의 ID - 0부터 시작
	struct _GameObject *pOwner;	//이 Component를 소유한 GameObject의 주솟값 - 다른 Component를 참조하기 위해 사용 ex)애니메이션 Component, 트리거 Component 등

	int (*SetpOwner)(struct _ComponentBase *cthis, struct _GameObject *pNewOwner);	//입력받은 GameObject의 주솟값을 pOwner값으로 할당
	struct _GameObject* (*GetpOwner)(struct _ComponentBase *cthis);	//pOwner값 반환

}ComponentBase;
typedef struct _RenderComponent{	//ID - 0

	struct _RenderComponent* cthis;

	struct _ComponentBase* pComponentBase;

	char*** str;
	int input_height;
	int input_width;
	int calc_height;
	int fps; //calc_height / input_height

	int (*SetInputHeight)(struct _RenderComponent* cthis, int new_input_height);	//input_height = new_input_height;
	int (*SetInputWidth)(struct _RenderComponent* cthis, int new_input_width); 
	int (*GetData)(struct _RenderComponent* cthis, const char* FileName);	//파일 입출력으로 행의 갯수 구한 뒤(calc_height) str[0]부터 str[행의 갯수 - 1]까지 문자열 긁어오기 - 파일입출력 중 fgets를 이용하면 될 듯 char* str[]에 한줄 한줄 입력받고 render함수에 modeldata.str를 전달
	int (*Render)(struct _RenderComponent* cthis, int x, int y, int select_fps, int color);	//모델 데이터를 가져와서 한줄 씩 ScreenWrite 한다. y 좌표를 height만큼 하나씩 늘려가면서

}RenderComponent;
typedef struct _InputComponent{	//ID - 1

	struct _InputComponent *cthis;

	struct _ComponentBase *pComponentBase;

	int input;

	int (*GetInput)(struct _InputComponent *cthis);	//if(_kbhit())으로 입력값 받아오기

}InputComponent;
typedef struct _RollComponent{	//ID - 2

	struct _RollComponent *cthis;

	struct _ComponentBase *pComponentBase;

	int random_number;

	int (*GetRandom)(struct _RollComponent *cthis, int n);	//rand()%n 반환

}RollComponent;
typedef struct _TriggerComponent{	//ID - 3

	struct _TriggerComponent *cthis;

	struct _ComponentBase *pComponentBase;

	int (*SetValue)(struct _TriggerComponent *cthis, int* target, int adjustment);	//target변수를 adjust값으로 초기화
	int (*AddValue)(struct _TriggerComponent *cthis, int* target, int adjustment);	//target변수에 adjust값 만큼 합 - 음수도 가능

}TriggerComponent;
typedef struct _AnimationComponent{	//ID - 4

	struct _AnimationComponent *cthis;

	struct _ComponentBase* pComponentBase;
	struct _RenderComponent *pRenderComponent;
	struct _TimeComponent *pTImeComponent;

	int animation_switch;
	int fps;
	int (*Animation)(struct _AnimationComponent* cthis, int lasting_time, const char* FileName, int x, int y, int new_input_height, int new_input_width, int color);	//시간과 render의 적절한 조합	- lasting_time은 하나의 이미지 지속 시간, full_time은 총 애니메이션 시간

}AnimationComponent;
typedef struct _TimeComponent{	//ID - 5

	struct _TimeComponent *cthis;

	ComponentBase* pComponentBase;

	clock_t PoTime, CurTime;

	int (*SetStdTime)(struct _TimeComponent *cthis);	//PoTime에 GetTick함수를 이용해서 시간 저장
	int (*GetLapTime)(struct _TimeComponent *cthis);	//CurTimedp GetTick함수를 이용해서 현재시간 저장 후 PoTime과의 차를 구해서 반환

}TimeComponent;
typedef struct _CursorCopmonent {

	struct _CursorComponent* cthis;

	ComponentBase* pComponentBase;
	TriggerComponent* pTriggerComponent;

	int arrow;
	int max, min;

}CursorComponent;

/* 생성자 */
GameObject* NewGameObject(int NewGameObjectID);
ComponentBase* NewComponentBase(int NewComponentID);
RenderComponent* NewRenderComponent(int NewComponentID);
InputComponent* NewInputComponent(int NewComponentID);
RollComponent* NewRollComponent(int NewComponentID);
TriggerComponent* NewTriggerComponent(int NewComponentID);
AnimationComponent* NewAnimationComponent(int NewComponentID);
TimeComponent* NewTimeComponent(int NewComponentID);
CursorComponent* NewCursorComponent(int NewComponentID);

/* GameObject */
int InsertComponent_(GameObject* cthis, int ComponentID, ComponentBase* pComponentBase);
int DeleteComponent_(GameObject* cthis, int ComponentID);
ComponentBase* GetComponent_(GameObject* cthis, int ComponentID);

/* ComponentBase */
int SetpOwner_(ComponentBase* cthis, GameObject* pNewOwner);
GameObject* GetpOwner_(ComponentBase* cthis);

/* RenderComponent */
int SetInputHeight_(RenderComponent* cthis, int new_input_height);
int SetInputWidth_(RenderComponent* cthis, int new_input_width);
int GetData_(RenderComponent* cthis, const char* FileName);
int Render_(RenderComponent* cthis, int x, int y, int select_fps, int color);

/* InputComponent */
int GetInput_(InputComponent* cthis);

/* RollComponent */
int GetRandom_(RollComponent* cthis, int n);

/* TriggerComponent */
int SetValue_(TriggerComponent* cthis, int* target, int adjustment);
int AddValue_(TriggerComponent* cthis, int* target, int adjustment);

/* AnimationComponent */
int Animation_(AnimationComponent* cthis, int lasting_time, const char* FileName, int x, int y, int new_input_height, int new_input_width, int color);

/* TimeComponent */
int SetStdTime_(TimeComponent* cthis);
int GetLapTime_(TimeComponent* cthis);
