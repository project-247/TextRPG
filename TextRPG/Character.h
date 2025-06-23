#pragma once
#include <string>

class Character {
private:

    //�̱��� ĳ���� ��ü�� ����Ű�� static ������
    static Character* Instance;

	//ĳ���� �������
    std::string ChName;   //ĳ���� �̸�. setName()�Լ��� ����. getChName()�� ��ȯ
    int ChLevel = 1;          //ĳ���� ����. setLevel()�� ����. getLevel()�� ��ȯ
    int ChHP = 200;             //ĳ���� ü��. setHP()�� ����. getHP()�� ��ȯ
    int ChAttack = 30;         //ĳ���� ���ݷ�. setAttack()�� ����. getAttack()�� ��ȯ
    int ChExperience = 0;        //ĳ���� ���� ����ġ. setExp()�� ����. getExp()�� ��ȯ
    int ChMax = 10;             //n���� ����ġ // ���������� ReadMe�� �ۼ��ϱ�
    long long ChGold = 100;       //�ʱ� �����ݾ�
    int MaxHP = 200;

    //ĳ���� ������ (�̱���)
    Character() {}

public:

    //���� ������ delete
    Character(const Character&) = delete;
    //���� ������ delete
    Character& operator=(const Character&) = delete;
    //�̵� ������ delete
    Character(Character&&) = delete;
    //�̵����� ������ delete
    Character& operator=(Character&&) = delete;
    //�Ҹ���
    ~Character() = delete;

    //ĳ���� ���� �޼���
    static Character* NewCharacter();

    //ĳ���� ����ġ ���� �޼���
    void ChExpUp(int);   //�Է� : ���� óġ ����ġ

    // (����ġ > max)�� �� ���� ����ϴ� �޼���
    void LevelUp();

    //�̸� ���� �޼���
    void SetChName(std::string);

    //LevelUp()�� ü�°� ���ݷ� �ʱ�ȭ �޼���
    void UpdateLevelStats();

    //HP ���� �޼���
    void ChHPUpDown(int);

    //Attack ���� �޼���
    void ChAttackUpDown(int);

    //LevelUp()�� ����ġ max �ʱ�ȭ �޼���
    void MaxUp();

    //ĳ���� �̸� ��ȯ �޼���
    std::string GetChName();

    //������ ��ȯ �޼���
    long long GetGold();

    //������ �߰�/���� �޼���
    void SetGold(long long);

    //���� ĳ���� ���� Ȯ�� �޼���
    void NowCharacter();
    
    //ĳ���� ���� ��ȯ �޼���
    int GetChLevel();

};
