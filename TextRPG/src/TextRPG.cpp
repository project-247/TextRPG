#include "GameManager.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	GameManager game;

	Image image;
	image.Loading1();
	cout << "\n\033[47m 게임 시작 준비 완료! 　\033[0m" << endl;
	cout << "\033[47m \033[30m 게임 시작 준비 완료!　\033[0m" << endl;
	cout << "\033[47m 게임 시작 준비 완료! 　\033[0m\n\n" << endl;
	
	while (1) {
	cout << "전체화면으로 변경 후 아무 키나 눌러 계속하세요...";

		if (_getch()) {
			break;
		}
	}
	

	system("cls");
	game.StartGame();
	return 0;
}