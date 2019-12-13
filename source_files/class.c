#include "..\\header_files\\class.h"

/* 생성자 */
GameObject* NewGameObject(int NewGameObjectID)	{

	GameObject* temp = (GameObject*)malloc(sizeof(GameObject));

	temp->cthis = temp;

	temp->Component_Table = (ComponentBase*)malloc(sizeof(ComponentBase*)*COMPONENT_NUMBERS);
	temp->GameObjectID = NewGameObjectID;

	temp->InsertComponent = InsertComponent_;
	temp->DeleteComponent = DeleteComponent_;
	temp->GetComponent = GetComponent_;

	return temp;
}
ComponentBase* NewComponentBase(int NewComponentID) {

	ComponentBase* temp = (ComponentBase*)malloc(sizeof(ComponentBase));

	temp->cthis = temp;

	temp->ComponentID = NewComponentID;
	temp->pOwner = NULL;

	temp->SetpOwner = SetpOwner_;
	temp->GetpOwner = GetpOwner_;
	
	return temp;
}
RenderComponent* NewRenderComponent(int NewComponentID) {

	RenderComponent* temp = (RenderComponent*)malloc(sizeof(RenderComponent));

	temp->cthis = temp;

	temp->pComponentBase = NewComponentBase(NewComponentID);

	temp->str = NULL;
	temp->input_width = 0;
	temp->input_height = 0;
	temp->calc_height = 0;
	temp->fps = 0;

	temp->SetInputHeight = SetInputHeight_;
	temp->SetInputWidth = SetInputWidth_;
	temp->GetData = GetData_;
	temp->Render = Render_;

	return temp;
}
InputComponent* NewInputComponent(int NewComponentID) {

	InputComponent* temp = (InputComponent*)malloc(sizeof(InputComponent));

	temp->cthis = temp;

	temp->pComponentBase = NewComponentBase(NewComponentID);

	temp->input = -1;

	temp->GetInput = GetInput_;

	return temp;
}
RollComponent* NewRollComponent(int NewComponentID) {

	RollComponent* temp = (RollComponent*)malloc(sizeof(RollComponent));

	temp->cthis = temp;

	temp->pComponentBase = NewComponentBase(NewComponentID);

	temp->random_number = 0;

	temp->GetRandom = GetRandom_;

	return temp;
}
TriggerComponent* NewTriggerComponent(int NewComponentID) {

	TriggerComponent* temp = (TriggerComponent*)malloc(sizeof(TriggerComponent));

	temp->cthis = temp;

	temp->pComponentBase = NewComponentBase(NewComponentID);

	temp->SetValue = SetValue_;
	temp->AddValue = AddValue_;

	return temp;
}
AnimationComponent* NewAnimationComponent(int NewComponentID) {

	AnimationComponent* temp = (AnimationComponent*)malloc(sizeof(AnimationComponent));

	temp->cthis = temp;

	temp->pComponentBase = NewComponentBase(NewComponentID);
	temp->pRenderComponent = NewRenderComponent(RENDER_COMPONENT);
	temp->pTImeComponent = NewTimeComponent(TIME_COMPONENT);

	temp->animation_switch = 1;
	temp->fps = 0;

	temp->Animation = Animation_;
	
	return temp;
}
TimeComponent* NewTimeComponent(int NewComponentID) {

	TimeComponent* temp = (TimeComponent*)malloc(sizeof(TimeComponent));

	temp->cthis = temp;

	temp->pComponentBase = NewComponentBase(NewComponentID);

	temp->CurTime = 0;
	temp->PoTime = 0;

	temp->GetLapTime = GetLapTime_;
	temp->SetStdTime = SetStdTime_;

	return temp;
}
CursorComponent* NewCursorComponent(int NewComponentID) {

	CursorComponent* temp = (CursorComponent*)malloc(sizeof(CursorComponent));

	temp->cthis = temp;

	temp->pComponentBase = NewComponentBase(NewComponentID);
	temp->pTriggerComponent = NewTriggerComponent(TRIGGER_COMPONENT);

	temp->arrow = 0;
	temp->max = 0;
	temp->min = 0;

	return temp;
}

/* GameObject */
int InsertComponent_(GameObject* cthis, int ComponentID, ComponentBase* pComponentBase) {

	cthis->Component_Table[ComponentID] = pComponentBase;
	
	return 0;
}
int DeleteComponent_(GameObject* cthis, int ComponentID) {

	cthis->Component_Table[ComponentID] = NULL;

	return 0;
}
ComponentBase* GetComponent_(GameObject* cthis, int ComponentID) {

	return cthis->Component_Table[ComponentID];
}

/* ComponentBase */
int SetpOwner_(ComponentBase* cthis, GameObject* pNewOwner) {

	cthis->pOwner = pNewOwner;

	return 0;
}
GameObject* GetpOwner_(ComponentBase* cthis) {

	return cthis->pOwner;
}

/* RenderComponent */
int SetInputHeight_(RenderComponent* cthis, int new_input_height) {

	cthis->input_height = new_input_height;

	return 0;
}
int SetInputWidth_(RenderComponent* cthis, int new_input_width) {

	cthis->input_width = new_input_width;

	return 0;
}
int GetData_(RenderComponent* cthis, const char* FileName) {

	FILE* fp;
	char* temp;
	temp = (char*)malloc(sizeof(char) * 100);
	fp = fopen(FileName, "r+");

	while (fgets(temp, 100, fp) != NULL) {	//길이 측정
		cthis->calc_height++;
	}
	free(temp);

	fclose(fp);

	fp = fopen(FileName, "r+");

	cthis->fps = cthis->calc_height / cthis->input_height;

	cthis->str = (char***)malloc(sizeof(char**) * cthis->fps);

	for (int i = 0; i < cthis->fps; i++) {
		*(cthis->str + i) = (char**)malloc(sizeof(char*) * cthis->input_height);
		for (int j = 0; j < cthis->input_height; j++)
			*(*(cthis->str + i) + j) = (char*)malloc(sizeof(char) * cthis->input_width);
	}

	for (int i = 0; i < cthis->fps; i++) {
		for (int j = 0; j < cthis->input_height; j++) {
			fgets(*(*(cthis->str + i) + j), cthis->input_width, fp);
		}
	}

	return 0;
}
int Render_(RenderComponent* cthis, int x, int y, int select_fps, int color) {

	gotoyx_set_color(color);
	for (int i = 0; i < cthis->input_height; i++)
		gotoyx_print( y+i, x, *(*(cthis->str + select_fps) + i));

	return 0;
}

/* InputComponent */
int GetInput_(InputComponent* cthis) {
	
	int key = 0;
	
	if (_kbhit()) {
		key = getch();

		if (key == 224) {
			key = getch();

			switch (key) {
			case RIGHT_ARROW: return RIGHT_ARROW;
			case LEFT_ARROW: return LEFT_ARROW;
			default: return 0;
			}
		}
		
		switch (key) {
			case ENTER: return ENTER;
			default: return 0;
		}
	}

	return 0;
}

/* RollComponent */
int GetRandom_(RollComponent* cthis, int n) {

	srand((unsigned)time(NULL));

	cthis->random_number = rand() % n;

	return 0;
}

/* TriggerComponent */
int SetValue_(TriggerComponent* cthis, int* target, int adjustment) {

	*target = adjustment;

	return 0;
}
int AddValue_(TriggerComponent* cthis, int* target, int adjustment) {

	*target += adjustment;

	return 0;
}

/* AnimationComponent */
int Animation_(AnimationComponent* cthis, int lasting_time, const char* FileName, int x, int y, int new_input_height, int new_input_width, int color) {

	if (cthis->animation_switch == 1) {
		cthis->pTImeComponent->SetStdTime(cthis->pTImeComponent->cthis);
		cthis->pRenderComponent->SetInputHeight(cthis->pRenderComponent->cthis, new_input_height);
		cthis->pRenderComponent->SetInputWidth(cthis->pRenderComponent->cthis, new_input_width);
		cthis->pRenderComponent->GetData(cthis->pRenderComponent, FileName);
		cthis->animation_switch = 0;
	}
	else if (cthis->animation_switch != 1 && cthis->animation_switch != 0)
		return 0;

	if (cthis->fps != (cthis->pTImeComponent->GetLapTime(cthis->pTImeComponent->cthis)) / lasting_time) {
		cthis->fps = (cthis->pTImeComponent->GetLapTime(cthis->pTImeComponent->cthis)) / lasting_time;
	}


	if (cthis->pRenderComponent->fps > cthis->fps) {
		cthis->pRenderComponent->Render(cthis->pRenderComponent->cthis, x, y, cthis->fps, color);
	}

	if (cthis->pRenderComponent->fps * lasting_time <= cthis->fps * lasting_time)
		cthis->animation_switch = 2;

	return 0;
}

/* TimeComponent */
int SetStdTime_(TimeComponent* cthis) {

	cthis->PoTime = GetTickCount();

	return 0;
}
int GetLapTime_(TimeComponent* cthis) {

	cthis->CurTime = GetTickCount();

	return (cthis->CurTime - cthis->PoTime);
}
