#include "Character.h"
#include <iostream>
#include <string>

//ĳ���� ���� ���� �ʱ�ȭ (�ܺο��� ����)
Character* Character::Instance = nullptr;

//ĳ���� ���� �޼���
Character* Character::NewCharacter() {
    //��ü�� ���ٸ� ����
    if (Instance == nullptr) {
        Instance = new Character();
    }
    //ĳ���� ��ü ��ȯ
    return Instance;
}

//ĳ���� ����ġ ���� �޼���
void Character::ChExpUp(int exp) {   //�Է� : ���� óġ ����ġ
    ChExperience += exp;
    if (ChExperience >= ChMax) {
        LevelUp();
    }
}

// (����ġ > max)�� �� ���� ����ϴ� �޼���
void Character::LevelUp() {
    if (ChLevel < 9) {
        ++ChLevel;
        std::cout << "�����մϴ�. ������ " << ChLevel << "�� �Ǿ����ϴ�!" << std::endl;
        //max �ʱ�ȭ
        MaxUp();
        UpdateLevelStats();
    }
    if (ChLevel == 9) {
        ++ChLevel;
        UpdateLevelStats();
        std::cout << "�����մϴ�. ������ " << ChLevel << "�� �Ǿ����ϴ�! ���� ����" << std::endl;
    }
}

//�̸� ���� �޼���
void Character::SetChName(std::string UName) {
    ChName = UName;
}

//LevelUp()�� ����ġ max �ʱ�ȭ �޼���
void Character::MaxUp() {
    int maxEXP[10] = { 0, 10, 30, 50, 70, 100, 150, 200, 250, 300 }; // now Level���� level+1������ �Ǳ� ���� ����ġ
    if (ChLevel > 1 && ChLevel < 10) {
        ChMax = maxEXP[ChLevel];
    }
}

//LevelUp()�� ü�°� ���ݷ� �ʱ�ȭ �޼���
void Character::UpdateLevelStats() {
    MaxUp(); //LevelUp()�� ����ġ max �ʱ�ȭ �޼��� > �����ȳ�����?..
    ChHP = MaxHP + (ChLevel * 20);          // **ü��**: `(���� ü�� + (���� �� 20))
    MaxHP = ChHP;                           // **���ݷ�**: `(���� ���ݷ� + (���� �� 5))
    ChAttack = ChAttack + (ChLevel * 5);    // ������ �� ü���� �ִ�ġ���� ������ ȸ��!
}

//ü�� ���� �޼���
void Character::ChHPUpDown(int changeHP) {
    ChHP += changeHP;
    if (ChHP <= 0) { ChHP = 0; }
}

//���ݷ� ���� �޼���
void Character::ChAttackUpDown(int changeAt) {
    ChAttack += changeAt;
}

//ĳ���� �̸� ��ȯ �޼���
std::string Character::GetChName() {
    return ChName;
}

//������ ��ȯ �޼���
long long Character::GetGold() {
    return ChGold;
}

//������ �߰�/���� �޼���
void Character::SetGold(long long a) {
    ChGold += a;
}

//���� ĳ���� ���� Ȯ�� �޼���
void Character::NowCharacter() {
    std::cout << "\n[���� ����]" << std::endl;
    std::cout << "�̸� : " << ChName << std::endl;
    std::cout << "���� : " << ChLevel << " (" << ChExperience << "/" << ChMax << ")" << std::endl;
    std::cout << "������ : " << ChGold << "G" << std::endl;
}

//ĳ���� ���� ��ȯ �޼���
int Character::GetChLevel() {
    return ChLevel;
}