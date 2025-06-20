#pragma once
#include <string>

class Character {
private:

    //�̱��� ĳ���� ��ü�� ����Ű�� static ������
    static Character* instance;

	//ĳ���� �������
    std::string chName;   //ĳ���� �̸�. setName()�Լ��� ����. getChName()�� ��ȯ
    int chLevel = 1;          //ĳ���� ����. setLevel()�� ����. getLevel()�� ��ȯ
    int chHP = 200;             //ĳ���� ü��. setHP()�� ����. getHP()�� ��ȯ
    int chAttack = 30;         //ĳ���� ���ݷ�. setAttack()�� ����. getAttack()�� ��ȯ
    int chExperience = 0;        //ĳ���� ���� ����ġ. setExp()�� ����. getExp()�� ��ȯ
    int chMax = 10;             //n���� ����ġ // �ٵ� 100�����ؾߵǳ�?
    long long chGold = 100;       //�ʱ� �����ݾ�
    int maxHP = 200;

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
    static Character* newCharacter();

    //ĳ���� ����ġ ���� �޼���
    void chExpUp(int exp);   //�Է� : ���� óġ ����ġ

    // (����ġ > max)�� �� ���� ����ϴ� �޼���
    void levelUp();

    //�̸� ���� �޼���
    void setChName(std::string uName);

    //levelUp()�� ü�°� ���ݷ� �ʱ�ȭ �޼���
    void UpdateLevelStats();

    //HP ���� �޼���
    void chHPUpDown(int changeHP);

    //Attack ���� �޼���
    void chAttackUpDown(int changeAt);

    //levelUp()�� ����ġ max �ʱ�ȭ �޼���
    void maxUp();

    //ĳ���� �̸� ��ȯ �޼���
    std::string getChName();

    //������ ��ȯ �޼���
    long long getGold();

    //������ �߰�/���� �޼���
    void setGold(long long a);

    //���� ĳ���� ���� Ȯ�� �޼���
    void nowCharacter();

};
