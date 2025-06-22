#pragma once
#include "Monster.h"
#include <string>

class Bencie : public Monster {
public:

	// - 메인쪽에서 '레벨 정수값 넣어"줘" 입니다.'
	// - 체력: (레벨 × 30)
	// - 공격력 : (레벨 × 35)
	Bencie(int level) {
		MosterName = "노래못하는 벤시";
		MosterHealth = level * 30;
		MosterAttack = level * 35;
	}
};