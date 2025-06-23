#include "GameManager.h"
#include <iostream>
#include <limits>

using namespace std;

// GameManager 생성자 (생성할 때 특별히 초기화할 내용 없음)
GameManager::GameManager() {}

// 게임 전체 시작 흐름 관리
void GameManager::StartGame() {
	CreateCharacter();  // 캐릭터 생성
	SelectJob();        // 직업 선택
	ShowCharacterStatus(); // 캐릭터 상태 확인

	// 메인 게임 루프: 메뉴 선택 반복
	while (true) {
		cout << "\n=== 메뉴 ===\n1. 전투 시작\n2. 상태 확인\n3. 종료\n선택: ";
		int menu;
		cin >> menu;

		if (menu == 1) {
			StartBattle();  // 전투 시작
		}
		else if (menu == 2) {
			ShowCharacterStatus();  // 현재 캐릭터 상태 출력
		}
		else if (menu == 3) {
			cout << "게임 종료" << endl;
			break;  // 프로그램 종료
		}
	}
}

// 캐릭터 생성 (이름 입력 받기)
void GameManager::CreateCharacter() {
	string name;
	int input;

	Character* character = Character::NewCharacter(); // 싱글톤 방식 캐릭터 생성
	Image images;
	images.Church();    // 배경 이미지 출력 (장식용)
	images.Triforce();
	images.Cat();

	while (true) {
		cout << "당신의 이름을 입력하세요: ";
		cin.ignore();   // 버퍼 초기화 (cin과 getline 혼용시 필수)
		getline(cin, name);
		cout << name << " 맞습니까? (1. 예 / 2. 아니오): ";
		cin >> input;

		if (input == 1) {
			character->SetChName(name);  // 이름 저장
			cout << "환영합니다, " << character->GetChName() << "님!" << endl;
			break;
		}
	}
}

// 직업 선택 시스템
void GameManager::SelectJob() {
	int input, input2;

	while (ClassNumber == 0) {  // 직업 미선택 상태일 때 반복
		cout << "직업을 선택하세요\n1. 전사 2. 궁수 3. 도적 4. 무직\n선택: ";
		cin >> input;

		if (input > 0 && input < 5) {
			cout << ReturnInputJobName(input) << " 선택? (1. 예 / 2. 아니오): ";
			cin >> input2;
			if (input2 == 1) {
				CreateJob(input);  // 직업 생성
				break;
			}
		}
	}
}

// 현재 캐릭터 상태 출력
void GameManager::ShowCharacterStatus() {
	NowUser nowUser;
	nowUser.ReturnUser();
}

// 전투 시작: 일반전투 or 보스전 자동 판별
void GameManager::StartBattle() {
	Character* player = Character::NewCharacter();

	if (player->GetChLevel() >= 10) {
		bossBattle();  // 레벨 10 이상 → 보스전 진입
	}
	else {
		battle();  // 일반 몬스터 전투
	}
}

// 보스전 따로 호출할 때 (현재는 사실상 안 쓰이지만 대비용으로 남겨둠)
void GameManager::StartBossBattle() {
	bossBattle();
}
