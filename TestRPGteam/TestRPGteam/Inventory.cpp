#pragma once
#include "Inventory.h"
#include <iostream>
//성신님감사합니다 이 코드는 이제 제 겁니다

//void Inventory::AddUserItem(const Item& item) {
//    items.push_back(item);
//    std::cout << item.getName() << "이(가) 인벤토리에 추가되었습니다.\n";
//}
//
//void Inventory::ShowUserItems() {
//    if (items.empty()) {
//        std::cout << "인벤토리가 비어 있습니다.\n";
//        return;
//    }
//
//    std::cout << "\n[인벤토리 목록]\n";
//    for (size_t i = 0; i < items.size(); ++i) {
//        std::cout << i + 1 << ". " << items[i].getName() << "\n";
//    }
//}
//
//void Inventory::UseItem(int index) {
//    if (index < 1 || index >(int)items.size()) {
//        std::cout << "잘못된 인덱스입니다.\n";
//        return;
//    }
//
//    items[index - 1].use();
//    items.erase(items.begin() + (index - 1));
//}
