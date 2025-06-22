#pragma once
#include "Monster.h"
#include <string>

class Mimic : public Monster {
public:
	Mimic(string name, int health, int attack) {
		getMosterName = "수상한 보물상자";
		getMosterHealth = 10;
		getMosterAttack = 5;
	}
};
