#pragma once
#include "Monster.h"

class BossDragon : public Monster {
public:
	BossDragon(int level) {
		MonsterName = "보스 드래곤";
		//형변환 방지를 위해 1.5 >> 3/2로 변경
		MonsterHealth = level * 500 * 3 / 2;
		MonsterAttack = level * 50 * 3 / 2;
		Experience = 9999;
	}
};
