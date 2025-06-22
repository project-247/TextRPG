#include "MS_Slime.h"
#include <iostream>

using namespace std;

// 생성자에서 캐릭터 레벨에 따른 능력치를 계산하여 부모 Monster 생성자를 호출
Slime::Slime(int GetChLevel)
{
    cout << "// - 슬라임 생성 확인 (레벨: " << GetChLevel << ", 체력: " << getMosterHealth << ", 공격력: " << getMosterAttack << ")" << endl;
}