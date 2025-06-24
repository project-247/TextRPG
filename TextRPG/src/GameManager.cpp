#include "GameManager.h"
#include <iostream>
#include <limits>
using namespace std;

// GameManager 생성자
GameManager::GameManager() {}

// 이름 입력 유효성 검사
string getValidName() {
	string input;
	while (true) {
		cout << "캐릭터 이름을 입력하세요: ";
		getline(cin, input);

		string blank = "";
		for (int i = 0; i < input.length(); i++) {
			if (input[i] != ' ') {
				blank += input[i];
			}
		}

		if (blank == "") {
			cout << "[에러] 이름은 공백일 수 없습니다. 다시 입력해주세요.\n";
		}
		else {
			break;
		}
	}
	return input;
}

// 게임 시작 (메인 흐름 제어)
void GameManager::StartGame() {
	CreateCharacter();
	SelectJob();
	ShowCharacterStatus();

	while (true) {
		cout << "\n=== 메뉴 ===\n1. 전투 시작\n2. 상태 확인\n3. 종료\n 4. 상점 방문\n선택: ";
		int menu;
		cin >> menu;

		if (menu == 1) {
			StartBattle();
		}
		else if (menu == 2) {
			ShowCharacterStatus();
		}
		else if (menu == 3) {
			cout << "게임 종료" << endl;
			break;
		}
		else if (menu == 4) {
			OpenShop();
		}
	}
}

// 캐릭터 생성
void GameManager::CreateCharacter() {
	int input;
	Character* character = Character::NewCharacter();

	string name = getValidName();

	while (true) {
		cout << name << " 맞습니까? (1. 예 / 2. 아니오): ";
		cin >> input;

		if (input == 1) {
			character->SetChName(name);
			cout << "환영합니다, " << character->GetChName() << "님!" << endl;

			cout << "초기 상태 → 레벨: " << character->GetChLevel()
				<< ", 체력: " << character->GetChHP()
				<< ", 공격력: " << character->GetChAttack() << endl;
			break;
		}
	}
}

// 직업 선택
void GameManager::SelectJob() {
	int input, input2;
	Character* character = Character::NewCharacter();

	while (character->GetJob() == "무직") {
		cout << "직업을 선택하세요\n1. 전사 2. 궁수 3. 도적 4. 무직\n선택: ";
		cin >> input;

		if (input > 0 && input < 5) {
			cout << ReturnInputJobName(input) << " 선택? (1. 예 / 2. 아니오): "; //3. 설명 보기 ReturnInputJobInfo(input) 추가해주세용
			cin >> input2;
			if (input2 == 1) {
				CreateJob(input, character);
				break;
			}
			//else if ...
		}
	}
}

// 캐릭터 상태 출력
void GameManager::ShowCharacterStatus() {
	NowUser nowUser;
	//인벤토리 확인을 위한 임시 선언
	Character* character = Character::NewCharacter();
	nowUser.ReturnUser();
	//인벤토리 확인을 위한 임시 출력
	character->inventory->ShowUserItems();
}

// 전투 시작
void GameManager::StartBattle() {
	Character* player = Character::NewCharacter();

	if (player->GetChLevel() >= 10) {
		bossBattle();
	}
	else {
		battle();
	}
}

void GameManager::OpenShop() {
	Character* player = Character::NewCharacter();
	Shop shop;

	shop.LoadItemsForJob(player->GetJob());

	while (true) {
		cout << "\n=== 상점 ===" << endl;
		shop.DisplayItems();
		cout << player->GetGold() << " 골드 보유\n";
		cout << "구매할 아이템 번호를 입력하세요 (0: 나가기): ";

		int choice;
		cin >> choice;

		if (choice == 0) {
			cout << "상점 방문을 종료합니다.\n";
			break;
		}

		if (!shop.BuyItem(choice, player)) {
			cout << "구매에 실패했습니다.\n";
		}
		else {
			cout << "구매 완료!\n";
		}
	}
}
