#pragma once
#include <iostream>

class Image {
public:
	//��ü â �׸� ũ��
	const int SCREEN_X = 150;
	const int SCREEN_Y = 30;

	//Ŀ�� �̵� �޼���
	static void moveCursor(int, int);

	void Cat1();

	void cat2();

	void leaf();

	void Slime();

	void Mimic();

	void Golem();

	void Bencie();

	void BossImage();
	void BossImage2();

	//���� �̸��� �Է¹޾� �Լ��� �����ϴ� �Լ�
	void ReturnInputImage(std::string);

	//���� �ִ� TEXT RPG
	void Loading1();
	//���� ���� TEXT RPG
	void Loading2(int, int);

	// �׵θ� �׸� â ���
	void RenderSystemUI();

	//���� �޴� ���
	void RenderMenu();

	//���� �޴��� ���� ���� ���(�ִ� 6��)
	void ShowCharacterUI(std::string name, int level, std::string job, int hp, std::string weapon, int attack, long long gold);

	//���� �޴��� ���� �ִ� �� �� ���ڿ�
	void ShowNowUI(std::string, std::string);
};

