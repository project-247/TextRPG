#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Monster
{
private:
	string getName; // ���� �̸�
	int getHealth; // ���� ü��
	int getAttack; // ���� ������

public:
	Monster(string name, int health, int attack) : getName(name), getHealth(health), getAttack(attack) {
		cout << "// - ���ͻ���Ȯ�ο�";
	}

	virtual string getName() { // ���Ϳ��� �̸��� �������ִ� �Ӽ�
		return getName;
		cout << "�̸����?";
	}
	virtual int getHealth() { // ���Ϳ��� ü���� �������ִ� �Ӽ�
		return getHealth;
		cout << "ü�����?";
	}
	virtual int getAttack() { // ���Ϳ��� ���·��� �������ִ� �Ӽ�
		return getAttack;
		cout << "���ݷ����?";
	}
	void takeDamage(int damage) { //���Ͱ� ���ظ� �޴� �Ӽ�
		getHealth -= damage;
	}
};