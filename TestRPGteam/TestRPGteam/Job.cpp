#include "Job.h"
#include <iostream>

int classNumber = 0;

//���� ���� �Լ�
void createJob(int input) {
    classNumber = input;
    std::cout << "����� ������ " << getJob() << "�Դϴ�." << std::endl;
}

//���� �־��� �� ������ ��ȯ �޼���
std::string getJob() {
    switch (classNumber)
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
        //gameManeger.inputReturn()
        return "";
    }
}

std::string returnInputJobName(int input) {
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
        //gameManeger.inputReturn();
        return "";
    }
}
