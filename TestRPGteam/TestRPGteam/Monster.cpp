#include "Monster.h"

string Monster::getName() {
	cout << "log1";
	return MosterName;
}

int Monster::getHealth() {
	cout << "log2";
	return MosterHealth;
}

int Monster::getAttack() {
	cout << "log3";
	return MosterAttack;
}

void Monster::takeDamage(int damage)
{
	MosterHealth -= damage;
	cout << MosterName << "이(가)" << damage << "의 피해를 입었습니다. 남은 체력: " << MosterHealth << endl;
	if (MosterHealth <= 0){
		cout << MosterName << "이(가) 죽었습니다.";
	}
}

int Monster::KillMonsterXP() {
	
}
// 슬라임 , 골렘 , 벤시 , 미믹
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// 보스 : 언리얼오거
// Boss : Unreal_Oger