#pragma once
#include "Monster.h"
#include <string>

class Slime : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 30)
	// - ���ݷ� : (���� �� 5)
	Slime(int level) {
		MosterName = "�Ϳ������";
		MosterHealth = level * 30;
		MosterAttack = level * 5;
	}
};