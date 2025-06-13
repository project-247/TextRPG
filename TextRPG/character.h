#pragma once
#include <string>
using namespace std;

class Character
{
public:
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;

	Character(string inputName);
	void displayStatus();
};