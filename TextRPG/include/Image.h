#pragma once

class Image {
public:
	//전체 창 네모 크기
	const int SCREEN_X = 150;
	const int SCREEN_Y = 30;

	//커서 이동 메서드
	void moveCursor(int, int);

	void Cat1();

	void cat2();
	

	void Slime();

	void Mimic();

	void Golem();

	void Bencie();

	//지연 있는 TEXT RPG
	void Loading1();
	//지연 없는 TEXT RPG
	void Loading2(int, int);

	// 테두리 네모 창 출력
	void RenderSystemUI();

	//우측 메뉴 출력
	void RenderMenu(int x, int y);

};

