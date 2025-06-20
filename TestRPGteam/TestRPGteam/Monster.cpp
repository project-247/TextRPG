#include "Monster.h"

string Monster::getName() {
	cout << "log1";
	return getMosterName;
}

int Monster::getHealth() {
	cout << "log2";
	return getMosterHealth;
}

int Monster::getAttack() {
	cout << "log3";
	return getMosterAttack;
}

void Monster::takeDamage(int damage)
{
	getMosterHealth -= damage;
	cout << getMosterName << "이(가)" << damage << "의 피해를 입었습니다. 남은 체력: " << getMosterHealth << endl;
	if (getMosterHealth <= 0){
		cout << getMosterName << "이(가) 죽었습니다.";
	}
}
// 슬라임 , 골렘 , 벤시 , 미믹
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// 보스 : 언리얼오거
// Boss : Unreal_Oger