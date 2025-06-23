#include "GameManager.h"
#include "Character.h"
#include "Job.h"
#include "NowUser.h"
#include "Image.h"
#include "Monster.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>


using namespace std;

static void InputReturn() {
	system("cls");
	cout << "---------------------------\n";
	cout << "다시 입력해주세요.\n";
	cout << "---------------------------\n\n";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

GameManager::GameManager() {}

void GameManager::StartGame() {
	CreateCharacter();
	SelectJob();
	ShowCharacterStatus();

	while (true) {
		cout << "\n=== 메뉴 ===" << endl;
		cout << "1. 전투 시작" << endl;
		cout << "2. 상태 확인" << endl;
		cout << "3. 종료" << endl;
		cout << "선택: ";
		int menu;
		cin >> menu;

		if (menu == 1) {
			Character* player = Character::NewCharacter();
			if (player->GetChLevel() >= 10) {
				StartBossBattle();
				break;
			}
			StartBattle();
			if (player->ChHP <= 0) {
				cout << "플레이어 사망. 게임 오버!" << endl;
				break;
			}
		}
		else if (menu == 2) {
			ShowCharacterStatus();
		}
		else if (menu == 3) {
			cout << "게임 종료" << endl;
			break;
		}
		else {
			InputReturn();
		}
	}
}

void GameManager::CreateCharacter() {
	string name;
	int input = 1;

	Character* character = Character::NewCharacter();
	Image images;
	images.Church();
	images.Triforce();
	images.Cat();

	while (true) {
		cout << "당신의 이름을 입력하세요: ";
		getline(cin, name);
		cout << name << ", 당신의 이름이 맞나요?\n1. 예 2. 아니오" << endl;
		cin >> input;

		if (input == 1) {
			character->SetChName(name);
			cin.ignore();
			system("cls");
			cout << "환영합니다. " << character->GetChName() << "님!" << endl;
			break;
		}
		InputReturn();
	}
}

void GameManager::SelectJob() {
	int input = 1;
	int input2 = 1;

	while (ClassNumber == 0) {
		cout << "직업을 선택하세요\n1. 전사  2. 궁수  3. 도적  4. 무직" << endl;
		cin >> input;

		if (input > 0 && input < 5) {
			cout << ReturnInputJobName(input) << "(으)로 선택하시겠습니까? \n1. 예 2. 아니오" << endl;
			cin >> input2;
			if (input2 == 1) {
				system("cls");
				CreateJob(input);
				break;
			}
		}
		InputReturn();
	}
}

void GameManager::ShowCharacterStatus() {
	NowUser nowUserStatus;
	nowUserStatus.ReturnUser();
	cout << endl;
}

// ---- 몬스터 생성 ----

Monster* GameManager::GenerateMonster() {
	Character* player = Character::NewCharacter();
	int level = player->GetChLevel();

	int hp = (rand() % (level * 10 + 1)) + (level * 20); // (레벨×20 ~ 레벨×30)
	int attack = (rand() % (level * 6 + 1)) + (level * 5); // (레벨×5 ~ 레벨×10)

	string monsterNames[] = { "Goblin", "Orc", "Troll" };
	int index = rand() % 3;
	string name = monsterNames[index];

	cout << "\n몬스터 등장! " << name << " (HP: " << hp << ", 공격력: " << attack << ")" << endl;
	return new Monster(name, hp, attack);
}

Monster* GameManager::GenerateBossMonster() {
	Character* player = Character::NewCharacter();
	int level = player->GetChLevel();

	int hp = ((rand() % (level * 10 + 1)) + (level * 20)) * 1.5;
	int attack = ((rand() % (level * 6 + 1)) + (level * 5)) * 1.5;

	cout << "\n보스 몬스터 Dragon 등장! (HP: " << hp << ", 공격력: " << attack << ")" << endl;
	return new Monster("Dragon", hp, attack);
}

// ---- 일반 전투 ----

void GameManager::StartBattle() {
	Monster* monster = GenerateMonster();
	Character* player = Character::NewCharacter();

	while (monster->getHealth() > 0 && player->ChHP > 0) {
		cout << "플레이어가 " << monster->getName() << " 를 공격합니다!" << endl;
		monster->takeDamage(player->ChAttack);
		if (monster->getHealth() <= 0) {
			cout << monster->getName() << " 처치!" << endl;
			delete monster;

			int gold = (rand() % 11) + 10; // 10~20골드
			cout << "50 EXP와 " << gold << " 골드 획득!" << endl;

			player->ChExpUp(50);
			player->SetGold(gold);
			return;
		}

		cout << monster->getName() << " 이 반격합니다!" << endl;
		player->ChHPUpDown(-monster->getAttack());
		cout << "현재 HP: " << player->ChHP << endl;
	}
}

// ---- 보스 전투 ----

void GameManager::StartBossBattle() {
	Monster* boss = GenerateBossMonster();
	Character* player = Character::NewCharacter();

	while (boss->getHealth() > 0 && player->ChHP > 0) {
		cout << "플레이어가 보스를 공격합니다!" << endl;
		boss->takeDamage(player->ChAttack);
		if (boss->getHealth() <= 0) {
			cout << "보스 Dragon 처치!" << endl;
			cout << "축하합니다! 게임 클리어!" << endl;
			delete boss;
			return;
		}

		cout << "보스가 반격합니다!" << endl;
		player->ChHPUpDown(-boss->getAttack());
		cout << "현재 HP: " << player->ChHP << endl;
	}
}
