#pragma once
#include "Monster.h"

class Bencie : public Monster {
public:
	Bencie() {}

	Bencie(string name, int health, int attack) {
		getMosterName = "����";
		getMosterHealth = 30;
		getMosterAttack = 10;
	}
};