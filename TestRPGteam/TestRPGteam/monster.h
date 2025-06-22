#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 이곳은 선언하는 공간이다.

class Monster
{
protected:
	string MonsterName; // 몬스터 이름
	int MonsterHealth;// 몬스터 체력
	int MonsterAttack; // 몬스터 데미지
	int Experience = 20; // 몬스터 처리시 얻는 경험치 //히히

public:
	// 몬스터 랜덤으로 부르는 메소드 ??를 써야되는데 음 ?아닌가 - 보류
	// - 성신님 죄송해요 몬스터 랜덤으로 소환되게 메인에서 부탁드려요..

	// 뭐가 문제 생겼을때 나오는 Null 값(이거 없어도 되는건가?)
	Monster() {
		MonsterName = "null";
		MonsterHealth = -1;
		MonsterAttack = -1;
	}
	// - ㅇㅇ? 이게 맞나?? 맞겠지
	Monster(string name, int health, int attack)
		: MonsterName(name), MonsterHealth(health), MonsterAttack(attack) {
		cout << "// - 몬스터생성확인용";
	}
	
	virtual string getName(); // 몬스터에게 이름을 설정해주는 속성

	virtual int getHealth(); // 몬스터에게 체력을 설정해주는 속성
	
	virtual int getAttack(); // 몬스터에게 공력력을 설정해주는 속성
	
	void takeDamage(int damage); //몬스터가 피해를 받는 메서드

	virtual int KillMonsterXP(); //몬스터를 처리했을때 나오는 경험치


	virtual ~Monster(){
	}
};