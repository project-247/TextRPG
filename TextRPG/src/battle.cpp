﻿#include "battle.h"
#include "Character.h"
#include "Image.h"
#include "MS_Golem.h"   // 일반 몬스터 헤더들
#include "MS_Slime.h"
#include "MS_Mimic.h"
#include "MS_Bencie.h"
#include "MS_BossDragon.h"  // 보스 몬스터 헤더
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

// 일반 몬스터와의 전투 함수
void battle() {
	// 매 전투마다 시드 설정 (랜덤 값 생성)
	srand((unsigned int)time(NULL));

	Character* player = Character::NewCharacter();
	int level = player->GetChLevel();  // 현재 레벨 확인
	Image* image = new Image();

	// 랜덤으로 일반 몬스터 선택 (4종류 중 선택)
	int monsterType = rand() % 4;
	Monster* monster = nullptr;

	if (monsterType == 0)
		monster = new Golem(level);
	else if (monsterType == 1)
		monster = new Slime(level);
	else if (monsterType == 2)
		monster = new Mimic(level);
	else
		monster = new Bencie(level);

	system("cls");
	image->ReturnInputImage(monster->ReturnMSName()); //몬스터에 맞는 이미지로 변경됨
	//전체 메뉴창 출력
	image->RenderSystemUI();
	//우측 메뉴창 출력
	image->RenderMenu();
	image->Loading2(60, 3);
	image->ShowNowUI("전투중입니다.", "화이팅 '~'");
	
	// 몬스터 등장 알림
	cout << "\n몬스터 등장! " << monster->getName()
		<< " (HP: " << monster->getHealth()
		<< ", 공격력: " << monster->getAttack() << ")\n";

	// 전투 루프 시작
	while (monster->getHealth() > 0 && player->GetChHP() > 0) {
		// 플레이어가 먼저 공격
		cout << "\n플레이어가 " << monster->getName() << " 를 공격합니다!" << endl;
		monster->takeDamage(player->GetChAttack());
		Sleep(700);
		// 몬스터 사망 체크
		if (monster->getHealth() <= 0) {
			cout << monster->getName() << "\033[32m 처치!\033[0m" << endl;

			// 전투 보상 지급 (경험치 + 골드)
			int gold = (rand() % 51) + 50;  // 50~100 골드 랜덤
			cout << "50 EXP와 " << gold << " 골드를 획득했습니다!" << endl;

			player->ChExpUp(50);
			player->SetGold(gold);

			image->moveCursor(0, 36);
			cout << "\n\033[33m  5초\033[33m후 자동으로 넘어갑니다.";
			Sleep(1000);
			image->moveCursor(0, 36);
			cout << "\n\033[33m  4초\033[33m후 자동으로 넘어갑니다.";
			Sleep(1000);
			image->moveCursor(0, 36);
			cout << "\n\033[33m  3초\033[33m후 자동으로 넘어갑니다.";
			Sleep(1000);
			image->moveCursor(0, 36);
			cout << "\n\033[33m  2초\033[33m후 자동으로 넘어갑니다.";
			Sleep(1000);
			image->moveCursor(0, 36);
			cout << "\n\033[33m  1초\033[33m후 자동으로 넘어갑니다.\033[0m";
			Sleep(1000);


			delete monster;  // 몬스터 메모리 해제
			return;  // 전투 종료
		}

		// 몬스터 반격
		cout <<"\n" << monster->getName() << " 이 반격합니다!" << endl;
		player->ChHPUpDown(-monster->getAttack());
		cout << "현재 HP: " << player->GetChHP() << endl;
		Sleep(700);
	}

	// 플레이어 사망 시 게임 오버 처리
	if (player->GetChHP() <= 0) {
		cout << "플레이어가 사망했습니다. 게임 오버!" << endl;
		cout << "\n3초후 자동으로 넘어갑니다.";
		Sleep(1000);
		cout << "...2";
		Sleep(1000);
		cout << "...1";
		Sleep(1000);
		delete monster;
	}

	delete image;
	image = nullptr;
}

// 보스전 전투 함수
void bossBattle() {
	Character* player = Character::NewCharacter();
	int level = player->GetChLevel();
	Image* image = new Image();

	// 보스 몬스터 생성
	Monster* boss = new BossDragon(level);

	system("cls");
	image->BossImage(); //몬스터에 맞는 이미지로 변경됨
	//전체 메뉴창 출력
	image->RenderSystemUI();
	//우측 메뉴창 출력
	image->RenderMenu();
	image->Loading2(60, 3);
	image->ShowNowUI("최종 보스와 전투중입니다.", "화이팅 '~')");
	image->BossImage(); //몬스터에 맞는 이미지로 변경됨


	// 보스 등장 알림
	cout << "\n보스 몬스터 등장! " << boss->getName()
		<< " (HP: " << boss->getHealth()
		<< ", 공격력: " << boss->getAttack() << ")\n";

	// 보스 전투 루프
	while (boss->getHealth() > 0 && player->GetChHP() > 0) {
		// 플레이어 공격
		cout << "\n플레이어가 " << boss->getName() << " 를 공격합니다!" << endl;
		boss->takeDamage(player->GetChAttack());
		Sleep(700);
		// 보스 사망 체크 → 엔딩
		if (boss->getHealth() <= 0) {
			image->BossImage(); //몬스터에 맞는 이미지로 변경됨
			Sleep(700);
		cout << "\n보스 클리어! 3초후 자동으로 넘어갑니다.";
		Sleep(1000);
		cout << "...2";
		Sleep(1000);
		cout << "...1";
		Sleep(1000);

			system("cls");
			image->Loading1();
			Sleep(700);
			image->BossImage2(); //몬스터에 맞는 이미지로 변경됨
			Sleep(700);
			cout << boss->getName() << " 처치!" << endl;
			Sleep(700);
			cout << "축하합니다! 보스 클리어! 게임 엔딩!!" << endl;
			image->moveCursor(0, 45);
			delete boss;

			// 게임 종료

			exit(0);
		}

		// 보스 반격
		cout << boss->getName() << " 이 반격합니다!" << endl;
		player->ChHPUpDown(-boss->getAttack());
		cout << "현재 HP: " << player->GetChHP() << endl;
		Sleep(700);
	}

	// 플레이어 사망 처리
	if (player->GetChHP() <= 0) {
		cout << "플레이어가 사망했습니다. 게임 오버!" << endl;
		cout << "\n3초후 자동으로 넘어갑니다.";
		Sleep(1000);
		cout << "...2";
		Sleep(1000);
		cout << "...1";
		Sleep(1000);
		delete boss;
	}

	delete image;
	image = nullptr;

}
