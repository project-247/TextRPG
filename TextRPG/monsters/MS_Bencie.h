#pragma once
#include "Monster.h"
#include <string>

class Bencie : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 60)
	// - 공격력 : (레벨 × 25)
	Bencie(int level) {
		MonsterName = "노래못하는 벤시";
		MonsterHealth = level * 60;
		MonsterAttack = level * 40;
		Experience = (level * 3) / 2;
	}
};