#pragma once
#include "Monster.h"
#include <string>

class Mimic : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 40)
	// - ���ݷ� : (���� �� 15)
	Mimic(int level) {
		MonsterName = "�����عڽ� �̹�";
		MonsterHealth = level * 40;
		MonsterAttack = level * 15;
		Experience = (level * 3) / 2;
	}
};
