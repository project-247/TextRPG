#pragma once
#include <iostream>

extern int classNumber;

enum Character_Class {
	Jobless, //"����"
	Warrior, //"����"
	Archer,  //"�ü�"
	Assassin,  //"����"
};

//���������޼���
void createJob(int input);

//���� ��ȣ�� ���ڿ��� ��ȯ �޼���
std::string getJob();

//main()���� Job ���� �� Ȯ�� �޼���
std::string returnInputJobName(int input);
