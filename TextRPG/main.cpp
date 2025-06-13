#include <iostream>
#include "character.h"
#include "utils.h"

int main()
{
	string name = getValidName();
	Character player(name);
	cout << "\n캐릭터 [" << name << "] 생성 완료!\n";
	player.displayStatus();
}