#include "Character.h"
#include <iostream>
#include <string>

//캐릭터 정적 변수 초기화 (외부에서 정의)
Character* Character::Instance = nullptr;

Inventory& Character::RetInventory()
{
	return *inventory;
}

//캐릭터 생성 메서드
Character* Character::NewCharacter() {
	//객체가 없다면 생성
	if (Instance == nullptr) {
		Instance = new Character();
	}
	//캐릭터 객체 반환
	return Instance;
}

//캐릭터 경험치 습득 메서드 > gameManager님은 이것 사용
void Character::ChExpUp(int exp) {   //입력 : 몬스터 처치 경험치
	ChExperience += exp;
	while (ChExperience >= ChMax) {
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
	int maxEXP[10] = { 0, 30, 70, 120, 170, 230, 290, 350, 410, 500 }; // now Level에서 level+1레벨이 되기 위한 경험치
	if (ChLevel > 1 && ChLevel < 10) {
		ChMax = maxEXP[ChLevel];
	}
}

//LevelUp()시 체력과 공격력 초기화 메서드
void Character::UpdateLevelStats() {
	MaxUp(); //LevelUp()시 경험치 max 초기화 메서드 > 오류안나겟지?..
	ChHP = MaxHP + 20;          // 체력 전체 회복 + 20상승
	MaxHP = ChHP;                           // **체력**: `(현재 체력 + (레벨 × 20))
	ChAttack = 30 + (ChLevel * 5);    // **캐릭터 공격력**: `(기본 공격력 + (레벨 × 5))
}

//체력 변동 메서드
void Character::ChHPUpDown(int changeHP) {
	ChHP += changeHP;
	if (ChHP <= 0) { ChHP = 0; }
}

//공격력 변동 메서드 > 아이템으로 오른 공격력은 1턴 지나면 다시 아이템 효과 없어져야 함 > 주의
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
	std::cout << "이　름 : " << ChName << std::endl;
	std::cout << "레　벨 : " << ChLevel << " (" << ChExperience << "/" << ChMax << ")" << std::endl;
	std::cout << "소지금 : " << ChGold << "G" << std::endl;
	std::cout << "직　업 : " << JobName << std::endl;
	showEquippedWeapon();
	std::cout << "체　력 : " << ChHP << std::endl;
	std::cout << "공격력 : " << GetChAttack() << std::endl;
}

//캐릭터 레벨 반환 메서드
int Character::GetChLevel() {
	return ChLevel;
}

int Character::GetChAttack() {
	return ChAttack + inventory->NowWeaponAttack(); //기본 공격력 : 무기 공격력
}

int Character::GetChHP() {
	return ChHP;
}

void Character::SetJob(std::string job) {
	JobName = job;
	if (job == "전사") {
		inventory->AddUserItem(weaponData.at(job)[0], JobName);
	}
	else if (job == "궁수") {
		inventory->AddUserItem(weaponData.at(job)[0], JobName);
	}
	else if (job == "도적") {
		inventory->AddUserItem(weaponData.at(job)[0], JobName);
	}
	else if (job == "무직") {
	}
}

std::string Character::GetChJob()
{
	return JobName;
}


void Character::equipWeapon()
{
	std::cout << inventory->ReturnNowWeapon().getName() << " 무기 장착 완료! (공격력 +" << inventory->NowWeaponAttack() << ")\n";
	//UpdateLevelStats();
}

void Character::showEquippedWeapon()
{
	std::cout << "무기 : " << inventory->ReturnNowWeapon().getName() << " (공격력 +" << inventory->NowWeaponAttack() << ")" << std::endl;
}

//void SetEquippedWeaponName() {
//
//}
//
//void ItemUse() {
//
//}