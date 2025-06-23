#include "Shop.h"
#include "Character.h"
#include <iostream>

//Shop::Shop() {
//    // 상점에 판매할 아이템 미리 등록
//    stock.emplace_back("치유 물약", ItemType::HEAL, 50);
//    stock.emplace_back("공격의 반지", ItemType::BOOST, 10);
//    stock.emplace_back("황금 동전 더미", ItemType::GOLD, 100);
//}
//
//void Shop::showMenu() {
//    int choice;
//
//    Character* player = Character::NewCharacter();
//    Inventory playerInventory;  // 전달받을 수도 있음 (지금은 예시로 생성)
//
//    while (true) {
//        std::cout << "\n===== ?? 상점 =====\n";
//        std::cout << "1. 아이템 보기\n";
//        std::cout << "2. 아이템 구매\n";
//        std::cout << "3. 나가기\n";
//        std::cout << "선택: ";
//        std::cin >> choice;
//
//        if (choice == 1) {
//            showItems();
//        }
//        else if (choice == 2) {
//            showItems();
//            std::cout << "구매할 아이템 번호 입력: ";
//            int index;
//            std::cin >> index;
//            buyItem(index, playerInventory);
//        }
//        else if (choice == 3) {
//            std::cout << "상점을 나갑니다.\n";
//            break;
//        }
//        else {
//            std::cout << "잘못된 입력입니다.\n";
//        }
//    }
//}
//
//void Shop::showItems() {
//    std::cout << "\n[판매 목록]\n";
//    for (size_t i = 0; i < stock.size(); ++i) {
//        std::cout << i + 1 << ". " << stock[i].getName() << " - 가격: " << stock[i].getValue() << "G\n";
//    }
//}
//
//void Shop::buyItem(int index, Inventory& inventory) {
//    Character* player = Character::newCharacter();
//
//    if (index < 1 || index >(int)stock.size()) {
//        std::cout << "잘못된 번호입니다.\n";
//        return;
//    }
//
//    Item item = stock[index - 1];
//    long long price = item.getValue();
//
//    if (player->GetGold() < price) {
//        std::cout << "소지금이 부족합니다!\n";
//        return;
//    }
//
//    player->SetGold(-price);  // 골드 차감
//    inventory.addItem(item);  // 인벤토리에 아이템 추가
//    std::cout << item.getName() << "을(를) 구매했습니다!\n";
//}
