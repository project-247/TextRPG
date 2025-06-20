#include "Character.h"
#include <iostream>
#include <string>

//ĳ���� ���� ���� �ʱ�ȭ (�ܺο��� ����)
Character* Character::instance = nullptr;

//ĳ���� ���� �޼���
Character* Character::newCharacter() {
    //��ü�� ���ٸ� ����
    if (instance == nullptr) {
        instance = new Character();
    }
    //ĳ���� ��ü ��ȯ
    return instance;
}

//ĳ���� ����ġ ���� �޼���
void Character::chExpUp(int exp) {   //�Է� : ���� óġ ����ġ
    chExperience += exp;
    if (chExperience >= chMax) {
        levelUp();
    }
}

// (����ġ > max)�� �� ���� ����ϴ� �޼���
void Character::levelUp() {
    if (chLevel < 9) {
        ++chLevel;
        std::cout << "�����մϴ�. ������ " << chLevel << "�� �Ǿ����ϴ�!" << std::endl;
        //max �ʱ�ȭ
        maxUp();
        UpdateLevelStats();
    }
    if (chLevel == 9) {
        ++chLevel;
        UpdateLevelStats();
        std::cout << "�����մϴ�. ������ " << chLevel << "�� �Ǿ����ϴ�! ���� ����" << std::endl;
    }
}

//�̸� ���� �޼���
void Character::setChName(std::string uName) {
    chName = uName;
}

//levelUp()�� ü�°� ���ݷ� �ʱ�ȭ �޼���
void Character::UpdateLevelStats() {
    chHP = maxHP + (chLevel * 20);          // **ü��**: `(���� ü�� + (���� �� 20))
    maxHP = chHP;                           // **���ݷ�**: `(���� ���ݷ� + (���� �� 5))
    chAttack = chAttack + (chLevel * 5);    // ������ �� ü���� �ִ�ġ���� ������ ȸ��!
}

//ü�� ���� �޼���
void Character::chHPUpDown(int changeHP) {
    chHP += changeHP;
    if (chHP <= 0) { chHP = 0; }
}

//���ݷ� ���� �޼���
void Character::chAttackUpDown(int changeAt) {
    chAttack += changeAt;
}

//levelUp()�� ����ġ max �ʱ�ȭ �޼���
void Character::maxUp() {
    int maxEXP[10] = { 0, 10, 30, 50, 70, 100, 150, 200, 250, 300 }; // now Level���� level+1������ �Ǳ� ���� ����ġ
    if (chLevel > 1 && chLevel < 10) {
        chMax = maxEXP[chLevel];
    }
}

//ĳ���� �̸� ��ȯ �޼���
std::string Character::getChName() {
    return chName;
}

//������ ��ȯ �޼���
long long Character::getGold() {
    return chGold;
}

//������ �߰�/���� �޼���
void Character::setGold(long long a) {
    chGold += a;
}

//���� ĳ���� ���� Ȯ�� �޼���
void Character::nowCharacter() {
    std::cout << "\n[���� ����]" << std::endl;
    std::cout << "�̸� : " << chName << std::endl;
    std::cout << "���� : " << chLevel << " (" << chExperience << "/" << chMax << ")" << std::endl;
    std::cout << "������ : " << chGold << "G" << std::endl;
}