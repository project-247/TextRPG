#include "Character.h"
#include <iostream>

Character* Character::Instance = nullptr;

Character* Character::NewCharacter() {
    if (!Instance)
        Instance = new Character();
    return Instance;
}

void Character::ChExpUp(int exp) {
    ChExperience += exp;
    if (ChExperience >= ChMax) {
        LevelUp();
    }
}

void Character::LevelUp() {
    if (ChLevel < 9) {
        ++ChLevel;
        std::cout << "축하합니다. 레벨이 " << ChLevel << "이 되었습니다!" << std::endl;
        MaxUp();
        UpdateLevelStats();
    }
    else if (ChLevel == 9) {
        ++ChLevel;
        UpdateLevelStats();
        std::cout << "축하합니다. 레벨이 " << ChLevel << "이 되었습니다! 만렙 ㅊㅊ" << std::endl;
    }
}

void Character::SetChName(std::string UName) {
    ChName = UName;
}

void Character::MaxUp() {
    int maxEXP[10] = { 0, 10, 30, 50, 70, 100, 150, 200, 250, 300 };
    if (ChLevel > 1 && ChLevel < 10) {
        ChMax = maxEXP[ChLevel];
    }
}

void Character::UpdateLevelStats() {
    MaxUp();
    ChHP = MaxHP + (ChLevel * 20);
    MaxHP = ChHP;
    // 공격력 = 기본 30 + 무기 공격력 + 레벨 보너스
    ChAttack = 30 + EquippedWeaponAttack + (ChLevel * 5);
}

void Character::ChHPUpDown(int changeHP) {
    ChHP += changeHP;
    if (ChHP <= 0) ChHP = 0;
}

void Character::ChAttackUpDown(int changeAt) {
    ChAttack += changeAt;
}

std::string Character::GetChName() {
    return ChName;
}

long long Character::GetGold() {
    return ChGold;
}

void Character::SetGold(long long a) {
    ChGold += a;
}

void Character::NowCharacter() {
    std::cout << "\n[현재 상태]" << std::endl;
    std::cout << "이름 : " << ChName << std::endl;
    std::cout << "레벨 : " << ChLevel << " (" << ChExperience << "/" << ChMax << ")" << std::endl;
    std::cout << "소지금 : " << ChGold << "G" << std::endl;
    std::cout << "직업 : " << JobName << std::endl;
    showEquippedWeapon();
    std::cout << "체력 : " << ChHP << std::endl;
    std::cout << "공격력 : " << ChAttack << std::endl;
}

int Character::GetChLevel() {
    return ChLevel;
}

void Character::SetJob(std::string job) {
    JobName = job;

    if (job == "전사") {
        equipWeapon("녹슨 검", 10);
    }
    else if (job == "궁수") {
        equipWeapon("나무활", 8);
    }
    else if (job == "도적") {
        equipWeapon("녹슨 단검", 9);
    }
    else {
        EquippedWeaponName = "";
        EquippedWeaponAttack = 0;
    }

    UpdateLevelStats(); // 직업 변경시 스탯 업데이트
}

std::string Character::GetJob() {
    return JobName;
}

void Character::equipWeapon(std::string weaponName, int weaponAttack) {
    EquippedWeaponName = weaponName;
    EquippedWeaponAttack = weaponAttack;
    std::cout << weaponName << " 무기 장착 완료! (공격력 +" << weaponAttack << ")\n";
    UpdateLevelStats();
}

void Character::showEquippedWeapon() {
    if (EquippedWeaponName.empty()) {
        std::cout << "장착된 무기 없음" << std::endl;
    }
    else {
        std::cout << "장착된 무기 : " << EquippedWeaponName << " (공격력 +" << EquippedWeaponAttack << ")" << std::endl;
    }
}
