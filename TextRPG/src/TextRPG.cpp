#include "GameManager.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
	GameManager game;

	Image image;
	image.Loading();
	cout << "\n\033[47m 게임 시작 준비 완료! 　\033[0m" << endl;
	cout << "\033[47m \033[30m 게임 시작 준비 완료!　\033[0m" << endl;
	cout << "\033[47m 게임 시작 준비 완료! 　\033[0m\n\n" << endl;

	cout << "아무 키나 눌러 계속하세요...";
	_getch();

	system("cls");
	game.StartGame();
	return 0;
}