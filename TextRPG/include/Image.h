#pragma once

class Image {
public:
	//��ü â �׸� ũ��
	const int SCREEN_X = 150;
	const int SCREEN_Y = 30;

	//Ŀ�� �̵� �޼���
	void moveCursor(int, int);

	void Cat1();

	void cat2();
	

	void Slime();

	void Mimic();

	void Golem();

	void Bencie();

	//���� �ִ� TEXT RPG
	void Loading1();
	//���� ���� TEXT RPG
	void Loading2(int, int);

	// �׵θ� �׸� â ���
	void RenderSystemUI();

	//���� �޴� ���
	void RenderMenu(int x, int y);

};

