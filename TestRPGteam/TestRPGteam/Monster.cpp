#pragma once
#include "Monster.h"

string Monster::getName() {
	cout << "log1";
	return MonsterName;
}

int Monster::getHealth() {
	cout << "log2";
	return MonsterHealth;
}

int Monster::getAttack() {
	cout << "log3";
	return MonsterAttack;
}

void Monster::takeDamage(int damage)
{
	MonsterHealth -= damage;
	
	if (MonsterHealth <= 0){
		cout << MonsterName << "��(��)" << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << MonsterHealth << endl;
		cout << MonsterName << "��(��) ó���߽��ϴ�!";

	}
	else {
		cout << MonsterName << "����" << damage << " �� ���ظ� �������ϴ�. ���� ü��: " << MonsterHealth << endl;
	}
}
// - KillMonsterXP ������ ��ȯ��?
int Monster::KillMonsterXP() {
	return Experience;
}
// ������ , �� , ���� , �̹�
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// ���� : �𸮾����
// Boss : Unreal_Oger