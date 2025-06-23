#include "Job.h"

void CreateJob(int input, Character* character) {
    switch (input) {
    case 1:
        character->SetJob("����");
        break;
    case 2:
        character->SetJob("�ü�");
        break;
    case 3:
        character->SetJob("����");
        break;
    case 4:
    default:
        character->SetJob("����");
        break;
    }
}

std::string ReturnInputJobName(int input) {
    switch (input) {
    case 1: return "����";
    case 2: return "�ü�";
    case 3: return "����";
    case 4: return "����";
    default: return "����";
    }
}