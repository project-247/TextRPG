#pragma once
#include "Monster.h"
#include <string>

class Bencie : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 30)
	// - ���ݷ� : (���� �� 35)
	Bencie(int level) {
		MosterName = "�뷡���ϴ� ����";
		MosterHealth = level * 30;
		MosterAttack = level * 35;
	}
};