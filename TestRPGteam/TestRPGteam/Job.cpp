#include "Job.h"
#include <iostream>

int classNumber = 0;

//직업 생성 함수
void createJob(int input) {
    classNumber = input;
    std::cout << "당신의 직업은 " << getJob() << "입니다." << std::endl;
}

//숫자 넣었을 때 직업명 반환 메서드
std::string getJob() {
    switch (classNumber)
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
        //gameManeger.inputReturn()
        return "";
    }
}

std::string returnInputJobName(int input) {
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
        //gameManeger.inputReturn();
        return "";
    }
}
