#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// �̰��� �����ϴ� �����̴�.

class Monster
{
protected:
	string MosterName; // ���� �̸�
	int MosterHealth;// ���� ü��
	int MosterAttack; // ���� ������
	/*int experience;*/ // ���� ó���� ��� ����ġ

public:
	// ���� �������� �θ��� �޼ҵ� ??�� ��ߵǴµ� �� ?�ƴѰ� - ����


	// ���� ���� �������� ������ Null ��(�̰� ��� �Ǵ°ǰ�?)
	Monster() {
		MosterName = "null";
		MosterHealth = -1;
		MosterAttack = -1;
	}
	// - ����? �̰� �³�?? �°���
	Monster(string name, int health, int attack)
		: MosterName(name), MosterHealth(health), MosterAttack(attack) {
		cout << "// - ���ͻ���Ȯ�ο�";
	}
	
	virtual string getName(); // ���Ϳ��� �̸��� �������ִ� �Ӽ�

	virtual int getHealth(); // ���Ϳ��� ü���� �������ִ� �Ӽ�
	
	virtual int getAttack(); // ���Ϳ��� ���·��� �������ִ� �Ӽ�
	
	void takeDamage(int damage); //���Ͱ� ���ظ� �޴� �޼���

	virtual int KillMonsterXP(); //���͸� ó�������� ������ ����ġ


	virtual ~Monster(){
		cout << "���Ͱ� ����Ͽ����ϴ�." << endl;
	}
};