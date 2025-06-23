#include "GameManager.h"
#include "Character.h"
#include "Job.h"
#include "NowUser.h"
#include "Image.h"
#include <iostream>
#include <limits>
#include <cstdlib>

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
