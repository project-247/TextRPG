#include <iostream>
#include "Character.h"
#include "Job.h"
#include "NowUser.h"
#include "Image.h"
#include "Monster.h"

void InputReturn() //정한 숫자 외 입력시 오류발생 메서드
{
    system("cls");
    std::cout << "---------------------------\n";
    std::cout << "다시 입력해주세요.\n";
    std::cout << "---------------------------\n\n";
    std::cin.clear();   // 상태 초기화
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력버퍼 비우기
}

int main()
{
    std::string Name;
    int Input = 1;
    int Input2 = 1;
    Character* Character = Character::NewCharacter();
    NowUser* NowUserStatus = new NowUser();
    Image Images;

    Images.Church();
    Images.Triforce();
    Images.Cat();

    // 이름 입력 및 확인 루프
    while (1)
    {
        std::cout << "당신의 이름을 입력하세요 : ";
        getline(std::cin, Name);
        std::cout << Name << ", 당신의 이름이 맞나요?\n1. 예 2. 아니오" << std::endl;
        std::cin >> Input;
        if (Input == 1) {
            Character->SetChName(Name);
            std::cin.ignore();
            system("cls");
            std::cout << "환영합니다. " << Character->GetChName() << "님!" << std::endl;
            break;
        }
        InputReturn();
    }

    // 직업 선택 루프 - 변경된 부분
    while (Character->GetJob() == "무직")  // 캐릭터 직업이 '무직'일 때만 반복
    {
        std::cout << "직업을 선택하세요\n1. 전사 2. 궁수 3. 도적 4. 무직" << std::endl;
        std::cin >> Input;

        if (Input > 0 && Input < 5)
        {
            std::cout << ReturnInputJobName(Input) << "(으)로 선택하시겠습니까 ? \n1.예 2. 아니오" << std::endl;
            std::cin >> Input2;
        }

        if (Input2 == 1) {
            system("cls");
            CreateJob(Input, Character);  // 캐릭터 객체를 인자로 넘겨 직업 및 무기 세팅
            break;
        }
        InputReturn();
    }

    NowUserStatus->ReturnUser();
    std::cout << std::endl;

    // 캐릭터 생성 완료 이후 진행
}
