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
	cout << getMosterName << "��(��)" << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << getMosterHealth << endl;
	if (getMosterHealth <= 0){
		cout << getMosterName << "��(��) �׾����ϴ�.";
	}
}
// ������ , �� , ���� , �̹�
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// ���� : �𸮾����
// Boss : Unreal_Oger