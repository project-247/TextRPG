#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Monster
{
private:
	string getName; // 몬스터 이름
	int getHealth; // 몬스터 체력
	int getAttack; // 몬스터 데미지

public:
	Monster(string name, int health, int attack) : getName(name), getHealth(health), getAttack(attack) {
		cout << "// - 몬스터생성확인용";
	}

	virtual string getName() { // 몬스터에게 이름을 설정해주는 속성
		return getName;
		cout << "이름줬니?";
	}
	virtual int getHealth() { // 몬스터에게 체력을 설정해주는 속성
		return getHealth;
		cout << "체력줬니?";
	}
	virtual int getAttack() { // 몬스터에게 공력력을 설정해주는 속성
		return getAttack;
		cout << "공격력줬니?";
	}
	void takeDamage(int damage) { //몬스터가 피해를 받는 속성
		getHealth -= damage;
	}
};