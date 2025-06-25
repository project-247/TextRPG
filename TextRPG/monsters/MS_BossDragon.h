#pragma once
#include "Monster.h"

class BossDragon : public Monster {
public:
	BossDragon(int level) {
		// 체력: (레벨×20×1.5) ~ (레벨×30×1.5)More actions
		int minHP = level * 30;
		int maxHP = level * 45;
		MonsterHealth = rand() % (maxHP - minHP + 1) + minHP;

		// 공격력: (레벨×5×1.5) ~ (레벨×10×1.5)
		int minAttack = level * 7;
		int maxAttack = level * 15;
		MonsterAttack = rand() % (maxAttack - minAttack + 1) + minAttack;

		Experience = 9999;
	}
};
