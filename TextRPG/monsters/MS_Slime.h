#pragma once
#include "Monster.h"
#include <string>

class Slime : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 30)
	// - ���ݷ� : (���� �� 5)
	Slime(int level) {
		MonsterName = "�Ϳ������";
		MonsterHealth = level * 120;
		MonsterAttack = level * 5;
		Experience = (level * 3) / 2;
	}
};