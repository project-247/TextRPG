#pragma once

#include <string>
#include "Monster.h"

class GameManager {
public:
	GameManager();
	void StartGame();             // 전체 게임 시작
	void CreateCharacter();       // 캐릭터 생성 (이름 입력)
	void SelectJob();             // 직업 선택
	void ShowCharacterStatus();   // 캐릭터 상태 확인
	void StartBattle();           // 일반 몬스터 전투
	void StartBossBattle();       // 보스 몬스터 전투

private:
	Monster* GenerateMonster();   // 몬스터 생성 함수
	Monster* GenerateBossMonster();

};