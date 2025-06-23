#include "GameManager.h"
#include <iostream>
#include <limits>

using namespace std;

GameManager::GameManager() {}

void GameManager::StartGame() {
	CreateCharacter();
	SelectJob();
	ShowCharacterStatus();

	while (true) {
		cout << "\n=== 메뉴 ===\n1. 전투 시작\n2. 상태 확인\n3. 종료\n선택: ";
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
	}
}

void GameManager::CreateCharacter() {
	string name;
	int input;

	Character* character = Character::NewCharacter();
	Image images;
	images.Church();
	images.Triforce();
	images.Cat();

	while (true) {
		cout << "당신의 이름을 입력하세요: ";
		cin.ignore();
		getline(cin, name);
		cout << name << " 맞습니까? (1. 예 / 2. 아니오): ";
		cin >> input;

		if (input == 1) {
			character->SetChName(name);
			cout << "환영합니다, " << character->GetChName() << "님!" << endl;
			break;
		}
	}
}

void GameManager::SelectJob() {
	int input, input2;

	while (ClassNumber == 0) {
		cout << "직업을 선택하세요\n1. 전사 2. 궁수 3. 도적 4. 무직\n선택: ";
		cin >> input;

		if (input > 0 && input < 5) {
			cout << ReturnInputJobName(input) << " 선택? (1. 예 / 2. 아니오): ";
			cin >> input2;
			if (input2 == 1) {
				CreateJob(input);
				break;
			}
		}
	}
}

void GameManager::ShowCharacterStatus() {
	NowUser nowUser;
	nowUser.ReturnUser();
}

void GameManager::StartBattle() {
	Character* player = Character::NewCharacter();

	if (player->GetChLevel() >= 10) {
		bossBattle();  // 보스전으로 전환
	}
	else {
		battle();  // 일반전투
	}
}

void GameManager::StartBossBattle() {
	// 보스전도 battle.cpp에 따로 만들어서 연결 가능
	bossBattle();
}
