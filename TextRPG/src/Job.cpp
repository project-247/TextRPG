#include "Job.h"

void CreateJob(int input, Character* character) {
    switch (input) {
    case 1:
        character->SetJob("전사");
        break;
    case 2:
        character->SetJob("궁수");
        break;
    case 3:
        character->SetJob("도적");
        break;
    case 4:
    default:
        character->SetJob("무직");
        break;
    }
}

std::string ReturnInputJobName(int input) {
    switch (input) {
    case 1: return "전사";
    case 2: return "궁수";
    case 3: return "도적";
    case 4: return "무직";
    default: return "무직";
    }
}