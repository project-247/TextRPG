#pragma once
#include "Monster.h"
#include "Item.h" // 필요 시 추가

class BossDragon : public Monster {
public:
    BossDragon(int level)
        : Monster("보스 드래곤", 500 + level * 50, 80 + level * 10, 200 + level * 50) {
    }

    Item DropCore() override {
        return Item("드래곤 코어", ItemType::CORE, 0, 1000);
    }
};
