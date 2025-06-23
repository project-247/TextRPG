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
        std::cout << "�����մϴ�. ������ " << ChLevel << "�� �Ǿ����ϴ�!" << std::endl;
        MaxUp();
        UpdateLevelStats();
    }
    else if (ChLevel == 9) {
        ++ChLevel;
        UpdateLevelStats();
        std::cout << "�����մϴ�. ������ " << ChLevel << "�� �Ǿ����ϴ�! ���� ����" << std::endl;
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
    // ���ݷ� = �⺻ 30 + ���� ���ݷ� + ���� ���ʽ�
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
    std::cout << "\n[���� ����]" << std::endl;
    std::cout << "�̸� : " << ChName << std::endl;
    std::cout << "���� : " << ChLevel << " (" << ChExperience << "/" << ChMax << ")" << std::endl;
    std::cout << "������ : " << ChGold << "G" << std::endl;
    std::cout << "���� : " << JobName << std::endl;
    showEquippedWeapon();
    std::cout << "ü�� : " << ChHP << std::endl;
    std::cout << "���ݷ� : " << ChAttack << std::endl;
}

int Character::GetChLevel() {
    return ChLevel;
}

void Character::SetJob(std::string job) {
    JobName = job;

    if (job == "����") {
        equipWeapon("�콼 ��", 10);
    }
    else if (job == "�ü�") {
        equipWeapon("����Ȱ", 8);
    }
    else if (job == "����") {
        equipWeapon("�콼 �ܰ�", 9);
    }
    else {
        EquippedWeaponName = "";
        EquippedWeaponAttack = 0;
    }

    UpdateLevelStats(); // ���� ����� ���� ������Ʈ
}

std::string Character::GetJob() {
    return JobName;
}

void Character::equipWeapon(std::string weaponName, int weaponAttack) {
    EquippedWeaponName = weaponName;
    EquippedWeaponAttack = weaponAttack;
    std::cout << weaponName << " ���� ���� �Ϸ�! (���ݷ� +" << weaponAttack << ")\n";
    UpdateLevelStats();
}

void Character::showEquippedWeapon() {
    if (EquippedWeaponName.empty()) {
        std::cout << "������ ���� ����" << std::endl;
    }
    else {
        std::cout << "������ ���� : " << EquippedWeaponName << " (���ݷ� +" << EquippedWeaponAttack << ")" << std::endl;
    }
}
