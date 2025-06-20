#pragma once
#include <string>

class Character {
private:

    //싱글톤 캐릭터 객체를 가리키는 static 포인터
    static Character* instance;

	//캐릭터 멤버변수
    std::string chName;   //캐릭터 이름. setName()함수로 설정. getChName()로 반환
    int chLevel = 1;          //캐릭터 레벨. setLevel()로 설정. getLevel()로 반환
    int chHP = 200;             //캐릭터 체력. setHP()로 설정. getHP()로 반환
    int chAttack = 30;         //캐릭터 공격력. setAttack()로 설정. getAttack()로 반환
    int chExperience = 0;        //캐릭터 레벨 경험치. setExp()로 설정. getExp()로 반환
    int chMax = 10;             //n레벨 경험치 // 근데 100고정해야되나?
    long long chGold = 100;       //초기 소지금액
    int maxHP = 200;

    //캐릭터 생성자 (싱글톤)
    Character() {}

public:

    //복사 생성자 delete
    Character(const Character&) = delete;
    //대입 생성자 delete
    Character& operator=(const Character&) = delete;
    //이동 생성자 delete
    Character(Character&&) = delete;
    //이동대입 생성자 delete
    Character& operator=(Character&&) = delete;
    //소멸자
    ~Character() = delete;

    //캐릭터 생성 메서드
    static Character* newCharacter();

    //캐릭터 경험치 습득 메서드
    void chExpUp(int exp);   //입력 : 몬스터 처치 경험치

    // (경험치 > max)일 때 레벨 상승하는 메서드
    void levelUp();

    //이름 변경 메서드
    void setChName(std::string uName);

    //levelUp()시 체력과 공격력 초기화 메서드
    void UpdateLevelStats();

    //HP 변경 메서드
    void chHPUpDown(int changeHP);

    //Attack 변경 메서드
    void chAttackUpDown(int changeAt);

    //levelUp()시 경험치 max 초기화 메서드
    void maxUp();

    //캐릭터 이름 반환 메서드
    std::string getChName();

    //소지금 반환 메서드
    long long getGold();

    //소지금 추가/감소 메서드
    void setGold(long long a);

    //현재 캐릭터 상태 확인 메서드
    void nowCharacter();

};
