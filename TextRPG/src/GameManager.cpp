#include "GameManager.h"
#include "battle.h"  // ✅ 전투 함수가 전역 함수이므로 반드시 포함
#include <iostream>
#include <limits>
#include "Character.h"//헤더에 있는데 또 가져오나요?//오류
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
			//system("cls"); 밑에 반드시 작성
			image.leaf();
			SetImageUI();
			image.ShowNowUI("환영합니다 유저님", "캐릭터 생성중 (임시 내용)");

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

	//우측 메뉴창 출력
	image.RenderMenu();

	//Text RPG 이미지 출력 >> 창 아래로 커서 이동
	image.Loading2(60, 3);
}

void GameManager::CreateCharacter() {
	int input;
	//Character* character = Character::NewCharacter();
	std::string name = getValidName();

	while (true) {
		std::cout << "고민하신 닉네임이 " << "\033[33m" << name << " \033[0m 맞습니까? (1. 예 / 2. 아니오): ";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (input == 1) {
			character->SetChName(name);

			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf();
			SetImageUI();
			image.ShowCharacterUI(character->GetChName(), character->GetChLevel(), character->GetChJob(), character->GetChHP(), character->RetInventory().ReturnNowWeapon().getName(), character->GetChAttack(), character->GetGold());

			std::cout << "환영합니다, "<< "\033[33m" << character->GetChName() << "\033[0m님!\n\n" << std::endl;
			break;
		}
		else if (input == 2)
		{
			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf();
			SetImageUI();
			image.ShowNowUI("환영합니다 유저님", "캐릭터 생성중 (임시 내용)");

			name = getValidName();
		}
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf();
			SetImageUI();
			image.ShowNowUI("환영합니다 유저님", "캐릭터 생성중 (임시 내용)");

			std::cout << "\033[31m[ERROR] \033[0m잘못된 입력입니다. 다시 입력해주세요.\n";
		}
	}
}

void GameManager::StartGame() {
	image.leaf();
	SetImageUI();
	image.ShowNowUI("환영합니다 유저님", "캐릭터 생성중 (임시 내용)");
	CreateCharacter();
	SelectJob();
	//ShowCharacterStatus(); // 상태확인

	while (true) {
		system("cls");
		image.leaf();
		SetImageUI();
		image.ShowCharacterUI(character->GetChName(),
			character->GetChLevel(),
			character->GetChJob(),
			character->GetChHP(),
			character->RetInventory().ReturnNowWeapon().getName(),
			character->GetChAttack(),
			character->GetGold());
		
		//ShowCharacterStatus();

		std::cout << "\n=== 메뉴 ===\n1. 전투 시작\n2. 상태 확인\n3. 종료\n4. 상점 방문\n선택: ";
		int menu;
		std::cin >> menu;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (menu == 1) { // 전투시작
			StartBattle();
		}
		else if (menu == 2) { // 상태확인
			ShowCharacterStatus();
		}
		else if (menu == 3) { // 종료
			std::cout << "게임 종료" << std::endl;
			break;
		}
		else if (menu == 4) { // 상점이동
			system("cls");
			image.leaf();
			SetImageUI();
			image.ShowCharacterUI(
				character->GetChName(),
				character->GetChLevel(),
				character->GetChJob(),
				character->GetChHP(),
				character->RetInventory().ReturnNowWeapon().getName(),
				character->GetChAttack(), character->GetGold());
			OpenShop();
		}
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			/*system("cls");*/
			std::cout << "\033[31m[ERROR] \033[0m잘못된 입력입니다. 다시 입력해주세요.\n";
			continue;
		}
	}
}


void GameManager::SelectJob() {
	int input, input2;
	//Character* character = Character::NewCharacter();

	while (character->GetChJob() == "무직") {
		std::cout << "직업을 선택해주세요!\033[1m\n\n 1. 전사\n 2. 궁수\n 3. 도적\n 4. 무직\033[0m\n\n 내 선택: ";
		std::cin >> input;

		if (input > 0 && input < 5) {
			std::cout << ReturnInputJobName(input) << " 선택? (1. 예 / 2. 아니오): ";
			std::cin >> input2;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (input2 == 1) {
				CreateJob(input, character);
				break;
			}
			else if (input2 == 2) {
				system("cls");
				//system("cls"); 밑에 적어주세요
				image.leaf();
				SetImageUI();
				image.ShowCharacterUI(character->GetChName(), character->GetChLevel(), character->GetChJob(), character->GetChHP(), character->RetInventory().ReturnNowWeapon().getName(), character->GetChAttack(), character->GetGold());

				std::cout << "직업 선택을 다시 합니다.\n";
			}
			else {
				std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n";
			}
		}
		else {
			std::cout << "유효하지 않은 직업 번호입니다. 다시 선택해주세요.\n";
		}

		if (cin.fail()) {
			std::cin.clear();
			SetImageUI();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
			//system("cls"); 밑에 적어주세요
			image.leaf();
			SetImageUI();
			image.ShowCharacterUI(character->GetChName(), character->GetChLevel(), character->GetChJob(), character->GetChHP(), character->RetInventory().ReturnNowWeapon().getName(), character->GetChAttack(), character->GetGold());

			std::cout << "\033[31m[ERROR] \033[0m잘못된 입력입니다.\n\n";
			continue;
		}
	}
}

void GameManager::ShowCharacterStatus() {
	NowUser nowUser;
//	Character* character = Character::NewCharacter();
	nowUser.ReturnUser();

	if (character->inventory)
		character->inventory->ShowUserItems();
	else
		std::cout << "[오류] 인벤토리가 비어있습니다.\n";
}

void GameManager::StartBattle() {
	//Character* player = Character::NewCharacter();

	if (character->GetChLevel() >= 10) {
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
	//Character* player = Character::NewCharacter();
	Shop shop;

	shop.LoadItemsForJob(character->GetChJob());

	while (true) {
		/*ShowCharacterStatus();*/
		std::cout << "\n=== 상점 ==="<< " \033[33m" << character->GetGold() << "\033[0m 골드 보유\n\n";
		shop.DisplayItems();
		std::cout << "\n구매할 아이템 번호를 입력하세요 (7: 나가기): ";

		int choice;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (choice == 7) { // 번호 변경 요망
			std::cout << "상점 방문을 종료합니다.\n";
			break;
		}

		if (choice < 1 || choice > shop.GetStockSize()) {
			std::cin.fail();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "[ ERROR ] 잘못된 번호입니다.\n";
			std::cout << "\n\n \033[36m계속하려면 아무키나 누르세요...\033[0m";
			system("cls");
			//모코코 출력
			image.leaf();
			//전체 메뉴창 출력
			image.RenderSystemUI();
			//우측 메뉴창 출력 >>인자 안 받는 방식으로 수정 예정
			image.RenderMenu();
			//Text RPG 이미지 출력 >> 창 아래로 커서 이동
			image.Loading2(60, 3);
			continue;
		}

		shop.BuyItem(choice, character);
	}
}
