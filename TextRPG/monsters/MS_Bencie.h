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
		MonsterHealth = level * 60;
		MonsterAttack = level * 40;
		Experience = (level * 3) / 2;
	}
};