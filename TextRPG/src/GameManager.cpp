#include "GameManager.h"
#include "battle.h"  // ✅ 전투 함수가 전역 함수이므로 반드시 포함
#include <iostream>
#include <limits>
#include "Character.h"//헤더에 있는데 또 가져오나요?
#include "Shop.h"
#include "NowUser.h"
#define NOMINMAX
#include <windows.h> // 커서 위치 조작용

GameManager::GameManager() {}

std::string GameManager::getValidName() {
	std::string input;
	while (true) {
		std::cout << "================================" << endl;
		std::cout << "【  캐릭터 이름을 입력하세요  】 " << endl;
		std::cout << "================================" << endl;
		std::cout << "Name : ";
		std::getline(std::cin, input);

		std::string blank = "";
		for (size_t i = 0; i < input.length(); i++) {
			if (input[i] != ' ') {
				blank += input[i];
			}
		}

		if (blank == "") {
			system("cls");
			//system("cls"); 밑에 image.Slime();랑 SetImageUI(); 적어주세요
			image.leaf(); //상황에 맞는 이미지로 변경 예정
			SetImageUI();
			std::cout << "\033[31m[ERROR] \033[0m \033[1m이름은 공백일 수 없습니다. 다시 입력해주세요.\033[0m\n\n";
		}
		else {
			break;
		}
	}
	return input;
}

void GameManager::SetImageUI() {
	//전체 메뉴창 출력
	image.RenderSystemUI();

	//우측 메뉴창 출력 >>인자 안 받는 방식으로 수정 예정
	image.RenderMenu(60, 15);

	//Text RPG 이미지 출력 >> 창 아래로 커서 이동
	image.Loading2(60, 3);
}

void GameManager::CreateCharacter() {
	int input;
	Character* character = Character::NewCharacter();
	std::string name = getValidName();

	while (true) {
		std::cout<< "\n" << name << " 맞습니까? (1. 예 / 2. 아니오): ";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (input == 1) {
			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf(); //상황에 맞는 이미지로 변경 예정
			SetImageUI();
			character->SetChName(name);
			std::cout << "환영합니다, " << character->GetChName() << "님!\n\n" << std::endl;

			std::cout << "※초기 상태※\n" << endl;
			std::cout << "레　벨: "  << character->GetChLevel() << " Level" << std::endl;
			std::cout << "체　력: " << character->GetChHP() << " HP" << std::endl;
			std::cout << "공격력: " << character->GetChAttack() << " ATK" << std::endl;
			break;
		}
		else if (input == 2)
		{
			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf(); //상황에 맞는 이미지로 변경 예정
			SetImageUI();
			name = getValidName();
		}
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf(); //상황에 맞는 이미지로 변경 예정
			SetImageUI();
			std::cout << "\033[31m[ERROR] \033[0m잘못된 입력입니다. 다시 입력해주세요.\n";
		}
	}
}

void GameManager::StartGame() {
	image.leaf(); //새싹으로 변경 예정
	SetImageUI();
	CreateCharacter();
	SelectJob();
	ShowCharacterStatus();

	while (true) {
		std::cout << "\n=== 메뉴 ===\n1. 전투 시작\n2. 상태 확인\n3. 종료\n4. 상점 방문\n선택: ";
		int menu;
		std::cin >> menu;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (menu == 1) {
			StartBattle();
		}
		else if (menu == 2) {
			ShowCharacterStatus();
		}
		else if (menu == 3) {
			std::cout << "게임 종료" << std::endl;
			break;
		}
		else if (menu == 4) {
			OpenShop();
		}
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\033[31m[ERROR] \033[0m잘못된 입력입니다. 다시 입력해주세요.\n";
		}
	}
}


void GameManager::SelectJob() {
	int input, input2;
	Character* character = Character::NewCharacter();

	while (character->GetChJob() == "무직") {
		std::cout << "직업을 선택하세요\n1. 전사 2. 궁수 3. 도적 4. 무직\n선택: ";
		std::cin >> input;

		if (cin.fail()) {
			std::cin.clear();
			SetImageUI();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf(); //상황에 맞는 이미지로 변경 예정
			SetImageUI();
			
			continue;
		}

		if (input > 0 && input < 5) {
			std::cout << ReturnInputJobName(input) << " 선택? (1. 예 / 2. 아니오): ";
			std::cin >> input2;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (input2 == 1) {
				CreateJob(input, character);
				break;
			}
			else if (input2 == 2) {
				std::cout << "직업 선택을 다시 합니다.\n";
			}
			else {
				std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n";
			}
		}
		else {
			std::cout << "유효하지 않은 직업 번호입니다. 다시 선택해주세요.\n";
		}
	}
}

void GameManager::ShowCharacterStatus() {
	NowUser nowUser;
	Character* character = Character::NewCharacter();
	nowUser.ReturnUser();

	if (character->inventory)
		character->inventory->ShowUserItems();
	else
		std::cout << "[오류] 인벤토리가 비어있습니다.\n";
}

void GameManager::StartBattle() {
	Character* player = Character::NewCharacter();

	if (player->GetChLevel() >= 10) {
		StartBossBattle();  // ✅ GameManager 멤버 함수 호출
	}
	else {
		battle();  // ✅ 전역 함수 호출
	}
}

void GameManager::StartBossBattle() {
	bossBattle();  // ✅ 전역 보스전 함수 호출
}

void GameManager::OpenShop() {
	Character* player = Character::NewCharacter();
	Shop shop;

	shop.LoadItemsForJob(player->GetChJob());

	while (true) {
		std::cout << "\n=== 상점 ===" << std::endl;
		shop.DisplayItems();
		std::cout << player->GetGold() << " 골드 보유\n";
		std::cout << "구매할 아이템 번호를 입력하세요 (0: 나가기): ";

		int choice;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (choice == 0) {
			std::cout << "상점 방문을 종료합니다.\n";
			break;
		}

		if (choice < 1 || choice > shop.GetStockSize()) {
			std::cout << "잘못된 번호입니다.\n";
			continue;
		}

		shop.BuyItem(choice, player);
	}
}
