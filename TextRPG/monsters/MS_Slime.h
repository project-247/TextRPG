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
		MonsterHealth = level * 60;
		MonsterAttack = level * 4;
		Experience = (level * 3) / 2;
	}
};