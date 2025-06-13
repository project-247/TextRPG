#include "utils.h"
#include <iostream>
using namespace std;

string getValidName()
{
	string inputName;

	while (true) {
		cout << "캐릭터 이름을 입력하세요: ";
		getline(cin, inputName);

		bool onlySpace = true;
		for (int i = 0; i < inputName.length(); i++) {
			if (inputName[i] != ' ') {
				onlySpace = false;
				break;
			}
		}

		if (inputName == "" || onlySpace) {
			cout << "[에러] 이름은 공백일 수 없습니다. 다시 입력해주세요.\n";
		}
		else {
			break;
		}
	}
	return inputName;
}