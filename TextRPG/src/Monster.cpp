#pragma once
#include "Monster.h"
#include "Image.h"
#include "Character.h"

string Monster::getName() {
	/*cout << "log1";*/
	return MonsterName;
}

int Monster::getHealth() {
	/*cout << "log2";*/
	return MonsterHealth;
}

int Monster::getAttack() {
	/*cout << "log3";*/
	return MonsterAttack;
}

void Monster::takeDamage(int damage)
{
	Character* character = Character::NewCharacter();//����
	Image* image = new Image();
	MonsterHealth -= damage;
	
	if (MonsterHealth <= 0){
		system("cls");
		//system("cls"); �ؿ� �����ּ���
		image->ReturnInputImage(ReturnMSName()); //���Ϳ� �´� �̹����� �����
		//��ü �޴�â ���
		image->RenderSystemUI();
		//���� �޴�â ���
		image->RenderMenu();
		image->Loading2(60, 3);
		//Text RPG �̹��� ��� >> â �Ʒ��� Ŀ�� �̵�
		image->ShowNowUI("�������Դϴ�.", "ȭ���� '~' (�ӽ� ����)");
		MonsterHealth = 0;
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

//�̸�(����)�� �޾Ƽ� �̸�(�ѱ�)�� ��ȯ�ϴ� �Լ�
string Monster::ReturnMSName()
{
	return MonsterName;
}
// ������ , �� , ���� , �̹�
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// ���� : �𸮾����
// Boss : Unreal_Oger