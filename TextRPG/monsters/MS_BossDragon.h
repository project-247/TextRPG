#pragma once
#include "Monster.h"

class BossDragon : public Monster {
public:
	BossDragon(int level) {
		MonsterName = "보스 드래곤";

		// 체력: (레벨×20×1.5) ~ (레벨×30×1.5)
		int minHP = static_cast<int>(level * 20 * 1.5);
		int maxHP = static_cast<int>(level * 30 * 1.5);
		MonsterHealth = rand() % (maxHP - minHP + 1) + minHP;

		// 공격력: (레벨×5×1.5) ~ (레벨×10×1.5)
		int minAttack = static_cast<int>(level * 5 * 1.5);
		int maxAttack = static_cast<int>(level * 10 * 1.5);
		MonsterAttack = rand() % (maxAttack - minAttack + 1) + minAttack;
	};
