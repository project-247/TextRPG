#pragma once
#include "Monster.h"
#include <string>

class Mimic : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 30)
	// - ���ݷ� : (���� �� 35)
	Mimic(int level) {
		MosterName = "�����عڽ� �̹�";
		MosterHealth = level * 40;
		MosterAttack = level * 15;
	}
};
