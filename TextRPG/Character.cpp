#include "Character.h"
#include <iostream>
#include <string>

//캐릭터 정적 변수 초기화 (외부에서 정의)
Character* Character::Instance = nullptr;

//캐릭터 생성 메서드
Character* Character::NewCharacter() {
    //객체가 없다면 생성
    if (Instance == nullptr) {
        Instance = new Character();
    }
    //캐릭터 객체 반환
    return Instance;
}

//캐릭터 경험치 습득 메서드
void Character::ChExpUp(int exp) {   //입력 : 몬스터 처치 경험치
    ChExperience += exp;
    if (ChExperience >= ChMax) {
        LevelUp();
    }
}

// (경험치 > max)일 때 레벨 상승하는 메서드
void Character::LevelUp() {
    if (ChLevel < 9) {
        ++ChLevel;
        std::cout << "축하합니다. 레벨이 " << ChLevel << "이 되었습니다!" << std::endl;
        //max 초기화
        MaxUp();
        UpdateLevelStats();
    }
    if (ChLevel == 9) {
        ++ChLevel;
        UpdateLevelStats();
        std::cout << "축하합니다. 레벨이 " << ChLevel << "이 되었습니다! 만렙 ㅊㅊ" << std::endl;
    }
}

//이름 변경 메서드
void Character::SetChName(std::string UName) {
    ChName = UName;
}

//LevelUp()시 경험치 max 초기화 메서드
void Character::MaxUp() {
    int maxEXP[10] = { 0, 10, 30, 50, 70, 100, 150, 200, 250, 300 }; // now Level에서 level+1레벨이 되기 위한 경험치
    if (ChLevel > 1 && ChLevel < 10) {
        ChMax = maxEXP[ChLevel];
    }
}

//LevelUp()시 체력과 공격력 초기화 메서드
void Character::UpdateLevelStats() {
    MaxUp(); //LevelUp()시 경험치 max 초기화 메서드 > 오류안나겟지?..
    ChHP = MaxHP + (ChLevel * 20);          // **체력**: `(현재 체력 + (레벨 × 20))
    MaxHP = ChHP;                           // **공격력**: `(현재 공격력 + (레벨 × 5))
    ChAttack = ChAttack + (ChLevel * 5);    // 레벨업 시 체력은 최대치까지 완전히 회복!
}

//체력 변동 메서드
void Character::ChHPUpDown(int changeHP) {
    ChHP += changeHP;
    if (ChHP <= 0) { ChHP = 0; }
}

//공격력 변동 메서드
void Character::ChAttackUpDown(int changeAt) {
    ChAttack += changeAt;
}

//캐릭터 이름 반환 메서드
std::string Character::GetChName() {
    return ChName;
}

//소지금 반환 메서드
long long Character::GetGold() {
    return ChGold;
}

//소지금 추가/감소 메서드
void Character::SetGold(long long a) {
    ChGold += a;
}

//현재 캐릭터 상태 확인 메서드
void Character::NowCharacter() {
    std::cout << "\n[현재 상태]" << std::endl;
    std::cout << "이름 : " << ChName << std::endl;
    std::cout << "레벨 : " << ChLevel << " (" << ChExperience << "/" << ChMax << ")" << std::endl;
    std::cout << "소지금 : " << ChGold << "G" << std::endl;
}

//캐릭터 레벨 반환 메서드
int Character::GetChLevel() {
    return ChLevel;
}