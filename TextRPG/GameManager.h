#pragma once

#pragma once
#include "Character.h"
#include "Monster.h"
#include "Job.h"
#include "NowUser.h"
#include "Image.h"
#include "Inventory.h"
#include "Item.h"
#include "Shop.h"
#include "battle.h"  // <-- 전투 시스템 연결

class GameManager {
public:
	GameManager();
	void StartGame();

private:
	void CreateCharacter();
	void SelectJob();
	void ShowCharacterStatus();
	void StartBattle();
	void StartBossBattle();
};