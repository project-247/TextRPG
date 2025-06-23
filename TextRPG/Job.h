#pragma once
#include <iostream>

extern int ClassNumber;

enum Character_Class {
	Jobless, //"무직"
	Warrior, //"전사"
	Archer,  //"궁수"
	Assassin,  //"도적"
};

//직업생성메서드
void CreateJob(int input);

//직업 번호를 문자열로 반환 메서드
std::string getJob();

//main()에서 Job 선택 전 확인 메서드
std::string ReturnInputJobName(int input);
