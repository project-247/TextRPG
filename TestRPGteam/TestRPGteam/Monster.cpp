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
	cout << MosterName << "��(��)" << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << MosterHealth << endl;
	if (MosterHealth <= 0){
		cout << MosterName << "��(��) �׾����ϴ�.";
	}
}

int Monster::KillMonsterXP() {
	
}
// ������ , �� , ���� , �̹�
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// ���� : �𸮾����
// Boss : Unreal_Oger