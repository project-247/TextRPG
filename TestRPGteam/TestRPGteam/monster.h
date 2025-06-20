#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 이곳은 선언하는 공간이다.

class Monster
{
protected:
	string getMosterName; // 몬스터 이름
	int getMosterHealth;// 몬스터 체력
	int getMosterAttack; // 몬스터 데미지

public:
	Monster() {
		getMosterName = "null";
		getMosterHealth = -1;
		getMosterAttack = -1;
	}
	Monster(string name, int health, int attack)
		: getMosterName(name), getMosterHealth(health), getMosterAttack(attack) {
		cout << "// - 몬스터생성확인용";
	}
	
	virtual string getName(); // 몬스터에게 이름을 설정해주는 속성

	virtual int getHealth(); // 몬스터에게 체력을 설정해주는 속성
	
	virtual int getAttack(); // 몬스터에게 공력력을 설정해주는 속성
	
	void takeDamage(int damage); //몬스터가 피해를 받는 메서드

	virtual ~Monster(){
		cout << "몬스터가 사망하였습니다." << endl;
	}
};