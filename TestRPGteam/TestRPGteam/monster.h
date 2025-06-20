#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// �̰��� �����ϴ� �����̴�.

class Monster
{
protected:
	string getMosterName; // ���� �̸�
	int getMosterHealth;// ���� ü��
	int getMosterAttack; // ���� ������

public:
	Monster() {
		getMosterName = "null";
		getMosterHealth = -1;
		getMosterAttack = -1;
	}
	Monster(string name, int health, int attack)
		: getMosterName(name), getMosterHealth(health), getMosterAttack(attack) {
		cout << "// - ���ͻ���Ȯ�ο�";
	}
	
	virtual string getName(); // ���Ϳ��� �̸��� �������ִ� �Ӽ�

	virtual int getHealth(); // ���Ϳ��� ü���� �������ִ� �Ӽ�
	
	virtual int getAttack(); // ���Ϳ��� ���·��� �������ִ� �Ӽ�
	
	void takeDamage(int damage); //���Ͱ� ���ظ� �޴� �޼���

	virtual ~Monster(){
		cout << "���Ͱ� ����Ͽ����ϴ�." << endl;
	}
};