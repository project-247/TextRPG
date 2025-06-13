#include "character.h"
#include <iostream>
using namespace std;

Character::Character(string inputName)
{
	name = inputName;
	level = 1;
	maxHealth = 200;
	health = maxHealth;
	attack = 30;
	experience = 0;
	gold = 0;
}

void Character::displayStatus()
{
	cout << "\n[캐릭터 상태]\n";
	cout << "이름: " << name << endl;
	cout << "레벨: " << level << endl;
	cout << "체력: " << health << " / " << maxHealth << endl;
	cout << "공격력: " << attack << endl;
	cout << "경험치: " << experience << " / 100" << endl;
	cout << "골드: " << gold << endl;
}