#include "Job.h"
#include <iostream>

int ClassNumber = 0;

//���� ���� �Լ�
void CreateJob(int input) {
    ClassNumber = input;
    std::cout << "����� ������ " << getJob() << "�Դϴ�." << std::endl;
}

//���� �־��� �� ������ ��ȯ �޼���
std::string getJob() {
    switch (ClassNumber)
    {
    case 1:
        return "����";
    case 2:
        return "�ü�";
    case 3:
        return "����";
    case 4:
        return "����";
    default:
        //gameManeger.InputReturn()
        return "";
    }
}

std::string ReturnInputJobName(int input) {
    bool a = 0;
    switch (input)
    {
    case 1:
        return "����";
    case 2:
        return "�ü�";
    case 3:
        return "����";
    case 4:
        return "����";
    default:
        //gameManeger.InputReturn();
        return "";
    }
}
