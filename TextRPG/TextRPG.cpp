#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character
{
public:
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;

	Character(string inputName)
	{
		name = inputName;
		level = 1;
		maxHealth = 200;
		health = maxHealth;
		attack = 30;
		experience = 0;
		gold = 0;
	}

	void displayStatus()
	{
		cout << "\n[캐릭터 상태]\n";
		cout << "이름: " << name << endl;
		cout << "레벨: " << level << endl;
		cout << "체력: " << health << " / " << maxHealth << endl;
		cout << "공격력: " << attack << endl;
		cout << "경험치: " << experience << " / 100" << endl;
		cout << "골드: " << gold << endl;
	}
};

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

int main()
{
	string name = getValidName();
	Character player(name);
	cout << "\n캐릭터 [" << name << "] 생성 완료!\n";
	player.displayStatus();
}