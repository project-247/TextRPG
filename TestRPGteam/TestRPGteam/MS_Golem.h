#pragma once
#include "Monster.h"
#include <string>

class Golem : public Monster {
public:

	Golem(string name, int health, int attack) {
		getMosterName = "�Ŵ��Ѱ�";
		getMosterHealth = 50;
		getMosterAttack = 30;
	}
};
