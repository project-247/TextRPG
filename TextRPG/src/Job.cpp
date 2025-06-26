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
    default:
        character->SetJob("����");
        character->SetGold(-100);
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

std::string ReturnInputJobInfo(int input) {
    switch (input) {
    case 1: return "����� ����� �����Դϴ�. 100G�� ���ݷ� 10�� �콼 ���� ��� �����մϴ�.\n";
    case 2: return "�ü��� ������ �ü��Դϴ�. 100G�� ���ݷ� 8�� ���� Ȱ�� ��� �����մϴ�.\n";
    case 3: return "������ �ߺ��� �����Դϴ�. 100G�� ���ݷ� 9�� �콼 �ܰ��� ��� �����մϴ�.\n";
    case 4: return "������ ��� ���⸦ ������ �� �ֽ��ϴ�. ��� 0G�� �����ϸ� �����մϴ�.\n";
    default: return "������ ��� ���⸦ ������ �� �ֽ��ϴ�. ��� 0G�� �����ϸ� �����մϴ�.\n";
    }
}