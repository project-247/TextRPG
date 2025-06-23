#pragma once
#include "Monster.h"

class Slime : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 30)
	// - 공격력 : (레벨 × 5)
	Slime(int level) {
		MonsterName = "귀여운슬라임";
		MonsterHealth = level * 30;
		MonsterAttack = level * 5;
		Experience = (level * 3) / 2;
	}
};

class Golem : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 50)
	// - 공격력 : (레벨 × 15)
	Golem(int level) {
		MonsterName = "덩치만 큰 골렘";
		MonsterHealth = level * 50;
		MonsterAttack = level * 15;
		Experience = (level * 3) / 2;
	}
};

class Bencie : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 30)
	// - 공격력 : (레벨 × 35)
	Bencie(int level) {
		MonsterName = "노래못하는 벤시";
		MonsterHealth = level * 30;
		MonsterAttack = level * 35;
		Experience = (level * 3) / 2;
	}
};

class Mimic : public Monster {
private:
	// 미믹의 체력과 공격스탯을 랜덤으로 설정하기위해 선언하였다.

	//// GPT: 비결정적 시드 소스
	//static random_device rd;
	//// GPT: 난수 엔진 (rd()로 시드 설정)
	//static mt19937 eng;
	//// GPT: 10부터 100까지의 균등 분포
	//static uniform_int_distribution<> Stack(10,100);

public:
	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 랜덤)
	// - 공격력 : (레벨 × 랜덤)
	// - 미믹은 체력과 공격력이 랜덤이지만 경험치는 다른 몬스터에 3배가량 더 많다
	Mimic(int level) {
		MonsterName = "랜덤※박스 미믹";
		MonsterHealth = level * 50;
		MonsterAttack = level * 50;
		Experience = level * 3;
	}
};
