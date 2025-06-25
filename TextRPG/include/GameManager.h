#pragma once

#include "Character.h"
#include "Monster.h"
#include "Job.h"
#include "NowUser.h"
#include "Image.h"
#include "Inventory.h"
#include "Item.h"
#include "Shop.h"
#include "battle.h"  // 전투 함수가 전역 함수로 선언되어 있음



class GameManager {
public:
	GameManager();
	void StartGame();

private:
	//이미지 바로 출력 위해서 객체 생성
	Image image;

	void CreateCharacter();
	void SelectJob();
	void ShowCharacterStatus();
	void StartBattle();
	void OpenShop();
	void StartBossBattle();  // 보스 전투 호출만 담당
	void SetImageUI();
	std::string getValidName();
};
