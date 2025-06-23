#pragma once
#include "Monster.h"
#include <string>
#include <random>

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
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 40)
	// - 공격력 : (레벨 × 15)
	Mimic(int level) {
		MonsterName = "랜덤※박스 미믹";
		MonsterHealth = level * 40;
		MonsterAttack = level * 15;
		Experience = (level * 3) / 2;
	}
};
