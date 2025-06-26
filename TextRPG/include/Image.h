#pragma once
#include <iostream>

class Image {
public:
	//전체 창 네모 크기
	const int SCREEN_X = 150;
	const int SCREEN_Y = 30;

	//커서 이동 메서드
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

	//몬스터 이름을 입력받아 함수를 실행하는 함수
	void ReturnInputImage(std::string);

	//지연 있는 TEXT RPG
	void Loading1();
	//지연 없는 TEXT RPG
	void Loading2(int, int);

	// 테두리 네모 창 출력
	void RenderSystemUI();

	//우측 메뉴 출력
	void RenderMenu();

	//우측 메뉴에 넣을 내용 출력(최대 6줄)
	void ShowCharacterUI(std::string name, int level, std::string job, int hp, std::string weapon, int attack, long long gold);

	//우측 메뉴에 넣을 최대 두 줄 문자열
	void ShowNowUI(std::string, std::string);
};

