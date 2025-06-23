#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// �̰��� �����ϴ� �����̴�.

class Monster
{
protected:
	string MonsterName; // ���� �̸�
	int MonsterHealth;// ���� ü��
	int MonsterAttack; // ���� ������
	int Experience = 20; // ���� ó���� ��� ����ġ //����

public:
	// ���� �������� �θ��� �޼ҵ� ??�� ��ߵǴµ� �� ?�ƴѰ� - ����
	// - ���Ŵ� �˼��ؿ� ���� �������� ��ȯ�ǰ� ���ο��� ��Ź�����..

	// ���� ���� �������� ������ Null ��(�̰� ��� �Ǵ°ǰ�?)
	Monster() {
		MonsterName = "null";
		MonsterHealth = -1;
		MonsterAttack = -1;
	}
	// - ����? �̰� �³�?? �°���
	Monster(string name, int health, int attack)
		: MonsterName(name), MonsterHealth(health), MonsterAttack(attack) {
		cout << "// - ���ͻ���Ȯ�ο�";
	}
	
	virtual string getName(); // ���Ϳ��� �̸��� �������ִ� �Ӽ�

	virtual int getHealth(); // ���Ϳ��� ü���� �������ִ� �Ӽ�
	
	virtual int getAttack(); // ���Ϳ��� ���·��� �������ִ� �Ӽ�
	
	void takeDamage(int damage); //���Ͱ� ���ظ� �޴� �޼���

	virtual int KillMonsterXP(); //���͸� ó�������� ������ ����ġ


	virtual ~Monster(){
	}
};