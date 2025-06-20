#include "Character.h"
#include <iostream>
#include <string>

//캐릭터 정적 변수 초기화 (외부에서 정의)
Character* Character::instance = nullptr;

//캐릭터 생성 메서드
Character* Character::newCharacter() {
    //객체가 없다면 생성
    if (instance == nullptr) {
        instance = new Character();
    }
    //캐릭터 객체 반환
    return instance;
}

//캐릭터 경험치 습득 메서드
void Character::chExpUp(int exp) {   //입력 : 몬스터 처치 경험치
    chExperience += exp;
    if (chExperience >= chMax) {
        levelUp();
    }
}

// (경험치 > max)일 때 레벨 상승하는 메서드
void Character::levelUp() {
    if (chLevel < 9) {
        ++chLevel;
        std::cout << "축하합니다. 레벨이 " << chLevel << "이 되었습니다!" << std::endl;
        //max 초기화
        maxUp();
        UpdateLevelStats();
    }
    if (chLevel == 9) {
        ++chLevel;
        UpdateLevelStats();
        std::cout << "축하합니다. 레벨이 " << chLevel << "이 되었습니다! 만렙 ㅊㅊ" << std::endl;
    }
}

//이름 변경 메서드
void Character::setChName(std::string uName) {
    chName = uName;
}

//levelUp()시 체력과 공격력 초기화 메서드
void Character::UpdateLevelStats() {
    chHP = maxHP + (chLevel * 20);          // **체력**: `(현재 체력 + (레벨 × 20))
    maxHP = chHP;                           // **공격력**: `(현재 공격력 + (레벨 × 5))
    chAttack = chAttack + (chLevel * 5);    // 레벨업 시 체력은 최대치까지 완전히 회복!
}

//체력 변동 메서드
void Character::chHPUpDown(int changeHP) {
    chHP += changeHP;
    if (chHP <= 0) { chHP = 0; }
}

//공격력 변동 메서드
void Character::chAttackUpDown(int changeAt) {
    chAttack += changeAt;
}

//levelUp()시 경험치 max 초기화 메서드
void Character::maxUp() {
    int maxEXP[10] = { 0, 10, 30, 50, 70, 100, 150, 200, 250, 300 }; // now Level에서 level+1레벨이 되기 위한 경험치
    if (chLevel > 1 && chLevel < 10) {
        chMax = maxEXP[chLevel];
    }
}

//캐릭터 이름 반환 메서드
std::string Character::getChName() {
    return chName;
}

//소지금 반환 메서드
long long Character::getGold() {
    return chGold;
}

//소지금 추가/감소 메서드
void Character::setGold(long long a) {
    chGold += a;
}

//현재 캐릭터 상태 확인 메서드
void Character::nowCharacter() {
    std::cout << "\n[현재 상태]" << std::endl;
    std::cout << "이름 : " << chName << std::endl;
    std::cout << "레벨 : " << chLevel << " (" << chExperience << "/" << chMax << ")" << std::endl;
    std::cout << "소지금 : " << chGold << "G" << std::endl;
}