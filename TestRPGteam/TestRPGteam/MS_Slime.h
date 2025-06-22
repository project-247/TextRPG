#pragma once
#include "Monster.h"
#include <string>

class Slime : public Monster {
public:
	// 캐릭터 에서 레벨을 받아와서 슬라임의 스펙이 오르는 ==

	// - 체력: (레벨 × 30)
	// - 공격력 : (레벨 × 10)
	Slime(int GetChLevel);
};