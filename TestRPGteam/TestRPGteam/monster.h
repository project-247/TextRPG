#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Monster
{
private:
	string getMosterName; // ���� �̸�
	int getMosterHealth; // ���� ü��
	int getMosterAttack; // ���� ������

public:
	Monster(string name, int health, int attack)
		: getMosterName(name), getMosterHealth(health), getMosterAttack(attack) {
		cout << "// - ���ͻ���Ȯ�ο�";
	}
	// ���Ϳ��� �̸��� �������ִ� �Ӽ�
	virtual string getName();
	// ���Ϳ��� ü���� �������ִ� �Ӽ�
	virtual int getHealth();
	// ���Ϳ��� ���·��� �������ִ� �Ӽ�
	virtual int getAttack();
	//���Ͱ� ���ظ� �޴� �޼���
	void takeDamage(int damage);
};