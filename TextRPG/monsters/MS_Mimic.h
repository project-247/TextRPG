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
		MonsterHealth = level * 50;
		MonsterAttack = level * 6;
		Experience = (level * 3) / 2;
	}
};
