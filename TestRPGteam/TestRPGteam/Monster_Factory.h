#pragma once
#include "Monster.h"

class Slime : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 30)
	// - ���ݷ� : (���� �� 5)
	Slime(int level) {
		MonsterName = "�Ϳ������";
		MonsterHealth = level * 30;
		MonsterAttack = level * 5;
		Experience = (level * 3) / 2;
	}
};

class Golem : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 50)
	// - ���ݷ� : (���� �� 15)
	Golem(int level) {
		MonsterName = "��ġ�� ū ��";
		MonsterHealth = level * 50;
		MonsterAttack = level * 15;
		Experience = (level * 3) / 2;
	}
};

class Bencie : public Monster {
public:

	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� 30)
	// - ���ݷ� : (���� �� 35)
	Bencie(int level) {
		MonsterName = "�뷡���ϴ� ����";
		MonsterHealth = level * 30;
		MonsterAttack = level * 35;
		Experience = (level * 3) / 2;
	}
};

class Mimic : public Monster {
private:
	// �̹��� ü�°� ���ݽ����� �������� �����ϱ����� �����Ͽ���.

	//// GPT: ������� �õ� �ҽ�
	//static random_device rd;
	//// GPT: ���� ���� (rd()�� �õ� ����)
	//static mt19937 eng;
	//// GPT: 10���� 100������ �յ� ����
	//static uniform_int_distribution<> Stack(10,100);

public:
	// - �����ʿ��� '���� ������ �־�"��" �Դϴ�.'
	// - ü��: (���� �� ����)
	// - ���ݷ� : (���� �� ����)
	// - �̹��� ü�°� ���ݷ��� ���������� ����ġ�� �ٸ� ���Ϳ� 3�谡�� �� ����
	Mimic(int level) {
		MonsterName = "�����عڽ� �̹�";
		MonsterHealth = level * 50;
		MonsterAttack = level * 50;
		Experience = level * 3;
	}
};
