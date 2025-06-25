#pragma once
#include "Monster.h"
#include <string>

class Mimic : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 40)
	// - 공격력 : (레벨 × 15)
	Mimic(int level) {
		MonsterName = "랜덤※박스 미믹";
		MonsterHealth = level * 50;
		MonsterAttack = level * 6;
		Experience = (level * 3) / 2;
	}
};
