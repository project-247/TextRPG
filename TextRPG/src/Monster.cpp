#pragma once
#include "Monster.h"
#include "Image.h"
#include "Character.h"

string Monster::getName() {
	/*cout << "log1";*/
	return MonsterName;
}

int Monster::getHealth() {
	/*cout << "log2";*/
	return MonsterHealth;
}

int Monster::getAttack() {
	/*cout << "log3";*/
	return MonsterAttack;
}

void Monster::takeDamage(int damage)
{
	Character* character = Character::NewCharacter();//오류
	Image* image = new Image();
	MonsterHealth -= damage;
	
	if (MonsterHealth <= 0){
		system("cls");
		//system("cls"); 밑에 적어주세요
		image->ReturnInputImage(ReturnMSName()); //몬스터에 맞는 이미지로 변경됨
		//전체 메뉴창 출력
		image->RenderSystemUI();
		//우측 메뉴창 출력
		image->RenderMenu();
		image->Loading2(60, 3);
		//Text RPG 이미지 출력 >> 창 아래로 커서 이동
		image->ShowNowUI("전투중입니다.", "화이팅 '~' (임시 내용)");
		MonsterHealth = 0;
		cout << MonsterName << "이(가)" << damage << "의 피해를 입었습니다. 남은 체력: " << MonsterHealth << endl;
		cout << MonsterName << "을(를) 처리했습니다!";

	}
	else {
		cout << MonsterName << "에게" << damage << " 의 피해를 입혔습니다. 남은 체력: " << MonsterHealth << endl;
	}
}
// - KillMonsterXP 생성자 반환값?
int Monster::KillMonsterXP() {
	return Experience;
}

//이름(영어)을 받아서 이름(한글)을 반환하는 함수
string Monster::ReturnMSName()
{
	return MonsterName;
}
// 슬라임 , 골렘 , 벤시 , 미믹
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// 보스 : 언리얼오거
// Boss : Unreal_Oger