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
		MonsterHealth = level * 60;
		MonsterAttack = level * 4;
		Experience = (level * 3) / 2;
	}
};
