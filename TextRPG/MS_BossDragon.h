#pragma once
#include "Monster.h"

class BossDragon : public Monster {
public:
	BossDragon(int level) {
		MonsterName = "보스 드래곤";
		MonsterHealth = level * 50 * 1.5;
		MonsterAttack = level * 15 * 1.5;
		Experience = 9999;
	}
};
