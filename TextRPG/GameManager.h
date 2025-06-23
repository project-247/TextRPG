#pragma once

#include <string>

class GameManager {
public:
	GameManager();
	void StartGame();             // 전체 게임 시작
	void CreateCharacter();       // 캐릭터 생성 (이름 입력)
	void SelectJob();             // 직업 선택
	void ShowCharacterStatus();   // 캐릭터 상태 확인
};