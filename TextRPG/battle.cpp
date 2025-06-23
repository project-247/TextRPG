#include "battle.h"
#include "Character.h"
#include "MS_Golem.h"   // 몬스터 헤더들 추가
#include "MS_Slime.h"
#include "MS_Mimic.h"
#include "MS_Bencie.h"
#include "MS_BossDragon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void battle() {
	srand((unsigned int)time(NULL));

	Character* player = Character::NewCharacter();
	int level = player->GetChLevel();

	// 랜덤으로 몬스터 선택
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

	cout << "\n몬스터 등장! " << monster->getName()
		<< " (HP: " << monster->getHealth()
		<< ", 공격력: " << monster->getAttack() << ")\n";

	// 전투 시작
	while (monster->getHealth() > 0 && player->GetChHP() > 0) {
		cout << "\n플레이어가 " << monster->getName() << " 를 공격합니다!" << endl;
		monster->takeDamage(player->GetChAttack());

		if (monster->getHealth() <= 0) {
			cout << monster->getName() << " 처치!" << endl;

			int gold = (rand() % 11) + 10;
			cout << "50 EXP와 " << gold << " 골드를 획득했습니다!" << endl;

			player->ChExpUp(50);
			player->SetGold(gold);
			delete monster;
			return;
		}

		cout << monster->getName() << " 이 반격합니다!" << endl;
		player->ChHPUpDown(-monster->getAttack());
		cout << "현재 HP: " << player->GetChHP() << endl;
	}

	// 죽으면 나가버림
	if (player->GetChHP() <= 0) {
		cout << "플레이어가 사망했습니다. 게임 오버!" << endl;
		delete monster;
	}
}

void bossBattle() {
	Character* player = Character::NewCharacter();
	int level = player->GetChLevel();

	Monster* boss = new BossDragon(level);

	cout << "\n보스 몬스터 등장! " << boss->getName()
		<< " (HP: " << boss->getHealth()
		<< ", 공격력: " << boss->getAttack() << ")\n";

	while (boss->getHealth() > 0 && player->GetChHP() > 0) {
		cout << "\n플레이어가 " << boss->getName() << " 를 공격합니다!" << endl;
		boss->takeDamage(player->GetChAttack());

		if (boss->getHealth() <= 0) {
			cout << boss->getName() << " 처치!" << endl;
			cout << "축하합니다! 보스 클리어! 게임 엔딩!!" << endl;
			delete boss;

			// 여기서 프로그램 종료
			exit(0);
		}

		cout << boss->getName() << " 이 반격합니다!" << endl;
		player->ChHPUpDown(-boss->getAttack());
		cout << "현재 HP: " << player->GetChHP() << endl;
	}

	if (player->GetChHP() <= 0) {
		cout << "플레이어가 사망했습니다. 게임 오버!" << endl;
		delete boss;
	}
}