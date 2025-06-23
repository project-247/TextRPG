#pragma once
#include <string>
#include <iostream>

class Character {
private:
    static Character* Instance;

    std::string ChName;
    int ChLevel = 1;
    int ChHP = 200;
    int ChAttack = 30;
    int ChExperience = 0;
    int ChMax = 10;
    long long ChGold = 100;
    int MaxHP = 200;

    std::string JobName = "무직";  // 직업 저장용
    std::string EquippedWeaponName = "";
    int EquippedWeaponAttack = 0;

    Character() {}

public:
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    Character(Character&&) = delete;
    Character& operator=(Character&&) = delete;
    ~Character() = delete;

    static Character* NewCharacter();

    void ChExpUp(int);
    void LevelUp();
    void SetChName(std::string);
    void UpdateLevelStats();
    void ChHPUpDown(int);
    void ChAttackUpDown(int);
    void MaxUp();

    std::string GetChName();
    long long GetGold();
    void SetGold(long long);

    void NowCharacter();
    int GetChLevel();

    void SetJob(std::string job);
    std::string GetJob();

    // 무기 장착 함수 (무기 이름, 공격력 받아서 장착)
    void equipWeapon(std::string weaponName, int weaponAttack);
    void showEquippedWeapon();
};
