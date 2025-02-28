#include "..\\header_files\\maingame.h"

int SetBet() {

	//기능이 하나뿐이면 굳이 게임오브젝트로 선언하지 말고 COMPONENT자체가 오브젝트인 것 처럼 사용도 가능
	RenderComponent* Menu = NewRenderComponent(RENDER_COMPONENT);

	//기능이 두 개 이상이면 게임오브젝트로 선언해야함
	GameObject* Cursor = NewGameObject(SYSTEMCURSOR_GAMEOBJECT);

	//물론 기능이 하나여도 게임오브젝트로 선언해도 됨
	GameObject* Player = NewGameObject(PLAYER_GAMEOBJECT);

	//게임오브젝트 별 컴포넌트 선언
	RenderComponent* CursorRender = NewRenderComponent(RENDER_COMPONENT);
	CursorComponent* CursorCursor = NewCursorComponent(CURSOR_COMPONENT);
	InputComponent* PlayerInput = NewInputComponent(INPUT_COMPONENT);

	//게임오브젝트인 Cursor에 Render 컴포넌트와 InputComponent 컴포넌트, Trigger 컴포넌트 추가
	Cursor->InsertComponent(Cursor->cthis, RENDER_COMPONENT, (ComponentBase*)CursorRender);
	Cursor->InsertComponent(Cursor->cthis, CURSOR_COMPONENT, (ComponentBase*)CursorCursor);
	//Player 오브젝트에 Input 컴포넌트 추가
	Player->InsertComponent(Player->cthis, INPUT_COMPONENT, (ComponentBase*)PlayerInput);
	
	/* Render 컴포넌트 데이터 불러오기 */
	Menu->SetInputHeight(Menu->cthis, 7);
	Menu->SetInputWidth(Menu->cthis, 100);
	Menu->GetData(Menu->cthis, "..\\data\\SetBetMenu.txt");
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->SetInputHeight(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, 1);
	// CursorRender->SetInputHeight(CursorRender->cthis, 1);과 같다
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->SetInputWidth(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, 3);
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->GetData(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, "..\\data\\SetBetCursor.txt");
	// CursorRender->GetData(CursorRender->cthis, "SetBetCursor.txt");와 같다

	// Cursor 컴포넌트 설정
	((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->max = 3;
	((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->min = 0;
	
	Menu->Render(Menu->cthis, 50, 17, 0, C_GREEN);
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow * 7 + 54, 22, 0, C_BLUE);

	while (1) {

		//Player게임 오브젝트에서 InputComponent 이용해서 입력값 받아오기
		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput(((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->cthis);
		
		//입력값이 오른쪽 화살표이면
		if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow < ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->max) {
			((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow++;
			gotoyx_clear(); 
			Menu->Render(Menu->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow * 7 + 54, 22, 0, C_BLUE);

		}
		//입력값이 왼쪽 화살표이면
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow > ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->min) {
			((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow--;
			gotoyx_clear();
			Menu->Render(Menu->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow * 7 + 54, 22, 0, C_BLUE);

		}
		//입력값이 엔터이면
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
			gotoyx_clear();
			break;
		}

	}

	gotoyx_clear();

	return (((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow)*5000;
}
int ChooseGame() {

	srand((unsigned)time(NULL));

	return rand() % GAME_NUMBER;
}
int GoOrStop() {

	int go_or_stop;

	GameObject* SystemMenu = NewGameObject(SYSTEMMENU_GAMEOBJECT);
	GameObject* SystemCursor = NewGameObject(SYSTEMCURSOR_GAMEOBJECT);
	GameObject* Player = NewGameObject(PLAYER_GAMEOBJECT);

	RenderComponent* SystemMenuRender = NewRenderComponent(RENDER_COMPONENT);
	RenderComponent* SystemCursorRender = NewRenderComponent(RENDER_COMPONENT);
	CursorComponent* SystemCursorCursor = NewCursorComponent(CURSOR_COMPONENT);

	InputComponent* PlayerInput = NewInputComponent(INPUT_COMPONENT);

	SystemMenu->InsertComponent(SystemMenu->cthis, RENDER_COMPONENT, (ComponentBase*)SystemMenuRender);
	SystemCursor->InsertComponent(SystemCursor->cthis, RENDER_COMPONENT, (ComponentBase*)SystemCursorRender);
	SystemCursor->InsertComponent(SystemCursor->cthis, CURSOR_COMPONENT, (ComponentBase*)SystemCursorCursor);

	Player->InsertComponent(Player->cthis, INPUT_COMPONENT, (ComponentBase*)PlayerInput);

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 7);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 100);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), "..\\data\\GoOrStopMenu.txt");
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), 1);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), 5);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), "..\\data\\GoOrStopCursor.txt");
	
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->cthis, 50, 17, 0, C_GREEN);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

	while (1) {

		
		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT));
		if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow < 1) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, 1);
			gotoyx_clear(); 
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow > 0) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, -1);
			gotoyx_clear(); 
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
			go_or_stop = !(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow);
			gotoyx_clear();
			gotoyx_set_color(C_WHITE);
			return go_or_stop;
		}
		

	}
}

int PlayHeadOrTail() {

	int guess = 0;
	int win_or_lose = 0;

	//게임 오브젝트 선언
	GameObject* Player = NewGameObject(PLAYER_GAMEOBJECT);
	GameObject* Coin = NewGameObject(COIN_GAMEOBJECT);
	GameObject* SystemMenu = NewGameObject(SYSTEMMENU_GAMEOBJECT);
	GameObject* SystemCursor = NewGameObject(SYSTEMCURSOR_GAMEOBJECT);

	//Player 오브젝트에 Input기능 추가
	InputComponent* PlayerInput = NewInputComponent(INPUT_COMPONENT);
	Player->InsertComponent(Player->cthis, INPUT_COMPONENT, (ComponentBase*)PlayerInput);
	
	//Coin 오브젝트에 Roll기능, Animation기능 추가
	RollComponent* CoinRoll = NewRollComponent(ROLL_COMPONENT);
	Coin->InsertComponent(Coin->cthis, CoinRoll->pComponentBase->ComponentID, (ComponentBase*)CoinRoll);
	AnimationComponent* CoinAnimation = NewAnimationComponent(ANIMATION_COMPONENT);
	Coin->InsertComponent(Coin->cthis, CoinAnimation->pComponentBase->ComponentID, (ComponentBase*)CoinAnimation);

	//SystemMenu오브젝트에 Trigger기능, Render기능 추가
	TriggerComponent* SystemMenuTrigger = NewTriggerComponent(TRIGGER_COMPONENT);
	SystemMenu->InsertComponent(SystemMenu->cthis, SystemMenuTrigger->pComponentBase->ComponentID, (ComponentBase*)SystemMenuTrigger);
	RenderComponent* SystemMenuRender = NewRenderComponent(RENDER_COMPONENT);
	SystemMenu->InsertComponent(SystemMenu->cthis, SystemMenuRender->pComponentBase->ComponentID, (ComponentBase*)SystemMenuRender);

	//SystemCursor오브젝트에 Render기능, Cursor기능 추가
	RenderComponent* SystemCursorRender = NewRenderComponent(RENDER_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, SystemCursorRender->pComponentBase->ComponentID, (ComponentBase*)SystemCursorRender);
	CursorComponent* SystemCursorCursor = NewCursorComponent(CURSOR_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, SystemCursorCursor->pComponentBase->ComponentID, (ComponentBase*)SystemCursorCursor);


	//RENDER 데이터 설정
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 7);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT)->cthis, 100);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT)->cthis, "..\\data\\HeadOrTailSystemMenu.txt");
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, 1);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, 3);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, "..\\data\\HeadOrTailSystemCursor.txt");

	//ROll 데이터 설정
	((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT))->GetRandom((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT)->cthis, 2);

	guess = HeadOrTail0(SystemMenu, SystemCursor, Player);
	HeadOrTail1(SystemMenu, Coin);
	win_or_lose = HeadOrTail2(&guess, SystemMenu, Coin, Player);

	return win_or_lose;
}
HeadOrTail0(GameObject* SystemMenu, GameObject* SystemCursor, GameObject* Player) {
	
	int guess = 0;

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 0, C_GREEN);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

	while (1) {
		
		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT));
		if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow < 1) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, 1);
			gotoyx_clear();
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);
		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow > 0) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, -1);
			gotoyx_clear(); ((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
			guess = ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow;
			((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = 0;
			gotoyx_clear(); 
			break;
		}
	}

	return guess;
}
HeadOrTail1(GameObject* SystemMenu, GameObject* Coin) {

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 1, C_GREEN);

	while (1) {
			
		((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT))->Animation((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT), 100, "..//data\\HeadOrTailCoinAnimation.txt", 68, 22, 1, 4, C_GREEN);

		if (((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT))->animation_switch == 2) {
			gotoyx_clear();
			break;
		}
	}

	return 0;
}
HeadOrTail2(int* guess, GameObject* SystemMenu, GameObject* Coin, GameObject* Player){
	
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 2, C_GREEN);

	while (1) {

		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput(((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->cthis);
		if (*guess == ((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT))->random_number) {
			if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
				gotoyx_clear();
				return 1;
			}
		}
		else {
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 3, C_GREEN);

			if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
				gotoyx_clear();
				gotoyx_set_color(C_WHITE);
				return 0;
			}
		}
	}
}