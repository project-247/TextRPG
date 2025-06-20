#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Monster
{
private:
	string getMosterName; // 몬스터 이름
	int getMosterHealth; // 몬스터 체력
	int getMosterAttack; // 몬스터 데미지

public:
	Monster(string name, int health, int attack) : getMosterName(name), getMosterHealth(health), getMosterAttack(attack) {
		cout << "// - 몬스터생성확인용";
	}

	virtual string getName() { // 몬스터에게 이름을 설정해주는 속성
		cout << "이름줬니?";
		return getMosterName;
	}
	virtual int getHealth() { // 몬스터에게 체력을 설정해주는 속성
		cout << "체력줬니?";
		return getMosterHealth;
	}
	virtual int getAttack() { // 몬스터에게 공력력을 설정해주는 속성
		cout << "공격력줬니?";
		return getMosterAttack;
	}
	void takeDamage(int damage) { //몬스터가 피해를 받는 메서드
		getMosterHealth -= damage;
		cout << getMosterName << "이(가)" << damage << "의 피해를 입었습니다. 남은 체력: " << getMosterHealth << endl;
		if (getMosterHealth <= 0) {
			cout << getMosterName << "이(가) 죽었습니다.";
		}
	}
};