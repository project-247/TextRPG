#pragma once
#include <iostream>

extern int ClassNumber;

enum Character_Class {
	Jobless, //"����"
	Warrior, //"����"
	Archer,  //"�ü�"
	Assassin,  //"����"
};

//���������޼���
void CreateJob(int input);

//���� ��ȣ�� ���ڿ��� ��ȯ �޼���
std::string getJob();

//main()���� Job ���� �� Ȯ�� �޼���
std::string ReturnInputJobName(int input);
