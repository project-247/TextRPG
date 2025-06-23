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
#include "battle.h" 

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