#pragma once
#include "Monster.h"
#include <string>

class Bencie : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 60)
	// - ���ݷ� : (���� �� 25)
	Bencie(int level) {
		MonsterName = "�뷡���ϴ� ����";
		MonsterHealth = level * 50;
		MonsterAttack = level * 10;
		Experience = (level * 3) / 2;
	}
};