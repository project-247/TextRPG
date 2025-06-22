#pragma once
#include "Monster.h"
#include <string>

class Mimic : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 30)
	// - 공격력 : (레벨 × 35)
	Mimic(int level) {
		MosterName = "랜덤※박스 미믹";
		MosterHealth = level * 40;
		MosterAttack = level * 15;
	}
};
