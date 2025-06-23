#include "Job.h"
#include <iostream>

int ClassNumber = 0;

//직업 생성 함수
void CreateJob(int input) {
    ClassNumber = input;
    std::cout << "당신의 직업은 " << getJob() << "입니다." << std::endl;
}

//숫자 넣었을 때 직업명 반환 메서드
std::string getJob() {
    switch (ClassNumber)
    {
    case 1:
        return "전사";
    case 2:
        return "궁수";
    case 3:
        return "도적";
    case 4:
        return "무직";
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
        return "전사";
    case 2:
        return "궁수";
    case 3:
        return "도적";
    case 4:
        return "무직";
    default:
        //gameManeger.InputReturn();
        return "";
    }
}
