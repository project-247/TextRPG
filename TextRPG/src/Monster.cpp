#pragma once
#include "Monster.h"
#include "Image.h"


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
	Image* image = new Image();
	MonsterHealth -= damage;
	
	if (MonsterHealth <= 0){
		system("cls");
		//system("cls"); 밑에 적어주세요
		image->Slime(); //상황에 맞는 이미지로 변경 예정
		//전체 메뉴창 출력
		image->RenderSystemUI();
		//우측 메뉴창 출력 >>인자 안 받는 방식으로 수정 예정
		image->RenderMenu(60, 15);
		//Text RPG 이미지 출력 >> 창 아래로 커서 이동
		image->Loading2(60, 3);
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
// 슬라임 , 골렘 , 벤시 , 미믹
// Slime_Core, Golem_Core, Bencie_Core, Mimic_Core


// 보스 : 언리얼오거
// Boss : Unreal_Oger