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
	Monster(string name, int health, int attack) : getMosterName(name), getMosterHealth(health), getMosterAttack(attack) {
		cout << "// - ���ͻ���Ȯ�ο�";
	}

	virtual string getName() { // ���Ϳ��� �̸��� �������ִ� �Ӽ�
		cout << "�̸����?";
		return getMosterName;
	}
	virtual int getHealth() { // ���Ϳ��� ü���� �������ִ� �Ӽ�
		cout << "ü�����?";
		return getMosterHealth;
	}
	virtual int getAttack() { // ���Ϳ��� ���·��� �������ִ� �Ӽ�
		cout << "���ݷ����?";
		return getMosterAttack;
	}
	void takeDamage(int damage) { //���Ͱ� ���ظ� �޴� �޼���
		getMosterHealth -= damage;
		cout << getMosterName << "��(��)" << damage << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << getMosterHealth << endl;
		if (getMosterHealth <= 0) {
			cout << getMosterName << "��(��) �׾����ϴ�.";
		}
	}
};