#include <iostream>
#include "Character.h"
#include "NowUser.h"
#include "Image.h"

int main()
{
    //정경주 코드 시작 - 캐릭터 이름 설정
    std::string name;
    int input = 1;
    Character* character = Character::newCharacter();
    NowUser* nowUser = new NowUser();
    Image image;

    image.church();
    image.triforce();
    image.cat();

    while (1) {
        std::cout << "\n당신의 이름을 입력하세요 : ";
        getline(std::cin, name);
        std::cout << name << ", 당신의 이름이 맞나요?\n1. 예 2. 아니오" << std::endl;
        std::cin >> input;
        if (input == 1) {
            //캐릭터 생성
            character->setChName(name);
            std::cin.ignore();
            system("cls"); //콘솔 초기화
            std::cout << "환영합니다. " << character->getChName() << "님!";
            break;
        }

        // - '예, 아니오' 단계에서 숫자 외 입력시 오류발생
        if (std::cin.fail()) { // - 고장 감지: cin의 상태를 확인
            system("cls");
            std::cout << "---------------------------\n";
            std::cout << "올바른 번호를 입력해주세요.\n";
            std::cout << "---------------------------\n\n";
            std::cin.clear();   // - 상태 초기화
            // - 입력버퍼에 남아있는 찌꺼기를 '\n' 값 전까지 제거
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore();
        system("cls"); //콘솔 초기화
    }
    nowUser->returnUser();
    std::cout << std::endl;

    //정경주 코드 종료 - 캐릭터 이름 설정
    /*---캐릭터 생성 완료---*/

}