#pragma once
#include "Monster.h"
#include <string>

class Slime : public Monster {
public:
	// ĳ���� ���� ������ �޾ƿͼ� �������� ������ ������ ==

	// - ü��: (���� �� 30)
	// - ���ݷ� : (���� �� 10)
	Slime(int GetChLevel);
};