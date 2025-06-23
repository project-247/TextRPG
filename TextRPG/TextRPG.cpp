#include "GameManager.h"
#include <iostream>

using namespace std;

int main() {
	GameManager game;
	game.StartGame();

	// 추후 여기서 전투/상점/보스 등 기능 확장 가능
	cout << "\n게임 시작 준비 완료!" << endl;

	return 0;
}