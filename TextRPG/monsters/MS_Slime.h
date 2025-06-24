#pragma once
#include "Monster.h"
#include <string>

class Slime : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 30)
	// - 공격력 : (레벨 × 5)
	Slime(int level) {
		MonsterName = "귀여운슬라임";
		MonsterHealth = level * 120;
		MonsterAttack = level * 5;
		Experience = (level * 3) / 2;
	}
};