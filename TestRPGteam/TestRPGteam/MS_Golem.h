#pragma once
#include "Monster.h"
#include <string>

class Golem : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 50)
	// - ���ݷ� : (���� �� 15)
	Golem(int level) {
		MosterName = "��ġ�� ū ��";
		MosterHealth = level * 50;
		MosterAttack = level * 15;
	}
};
