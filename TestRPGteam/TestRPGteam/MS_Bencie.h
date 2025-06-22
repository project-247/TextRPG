#pragma once
#include "Monster.h"
#include <string>

class Bencie : public Monster {
public:

	Bencie(string name, int health, int attack) {
		getMosterName = "º¥½Ã";
		getMosterHealth = 30;
		getMosterAttack = 25;
	}
};