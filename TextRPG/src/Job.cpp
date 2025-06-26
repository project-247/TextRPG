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
    default:
        character->SetJob("무직");
        character->SetGold(-100);
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

std::string ReturnInputJobInfo(int input) {
    switch (input) {
    case 1: return "전사는 용맹한 전사입니다. 100G와 공격력 10의 녹슨 검을 들고 시작합니다.\n";
    case 2: return "궁수는 날렵한 궁수입니다. 100G와 공격력 8의 나무 활을 들고 시작합니다.\n";
    case 3: return "도적은 야비한 도적입니다. 100G와 공격력 9의 녹슨 단검을 들고 시작합니다.\n";
    case 4: return "무직은 모든 무기를 장착할 수 있습니다. 대신 0G를 소지하며 시작합니다.\n";
    default: return "무직은 모든 무기를 장착할 수 있습니다. 대신 0G를 소지하며 시작합니다.\n";
    }
}