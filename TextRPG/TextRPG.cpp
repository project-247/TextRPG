#include <iostream>
#include <limits>
#include "Character.h"
#include "Job.h"
#include "NowUser.h"
#include "Image.h"
#include "Monster.h"

using namespace std;

// 예외 입력 처리 함수
void InputReturn() {
	system("cls");
	cout << "---------------------------\n";
	cout << "다시 입력해주세요.\n";
	cout << "---------------------------\n\n";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
	string Name;
	int Input = 1;
	int Input2 = 1;

	Character* character = Character::NewCharacter();
	NowUser* nowUserStatus = new NowUser();
	Image images;

	images.Church();
	images.Triforce();
	images.Cat();

	// 캐릭터 이름 설정
	while (true) {
		cout << "당신의 이름을 입력하세요 : ";
		getline(cin, Name);
		cout << Name << ", 당신의 이름이 맞나요?\n1. 예  2. 아니오" << endl;
		cin >> Input;

		if (Input == 1) {
			character->SetChName(Name);
			cin.ignore();
			system("cls");
			cout << "환영합니다. " << character->GetChName() << "님!" << endl;
			break;
		}
		InputReturn();
	}

	// 직업 선택
	while (ClassNumber == 0) {
		cout << "직업을 선택하세요\n1. 전사  2. 궁수  3. 도적  4. 무직" << endl;
		cin >> Input;

		if (Input > 0 && Input < 5) {
			cout << ReturnInputJobName(Input) << "(으)로 선택하시겠습니까? \n1. 예  2. 아니오" << endl;
			cin >> Input2;
			if (Input2 == 1) {
				system("cls");
				CreateJob(Input);
				break;
			}
		}
		InputReturn();
	}

	nowUserStatus->ReturnUser();
	cout << endl;

	// 추가 게임 시스템은 이후 여기에 이어서 연결하면 됩니다.
}
