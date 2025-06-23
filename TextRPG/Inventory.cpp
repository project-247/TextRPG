//#pragma once
//#include "Inventory.h"
//#include "WeaponMap.h"
//#include <iostream>
//
////WeaponMap WP_Map;
////std::map<std::string, std::vector<Item>> weaponMap;
////weaponMap=WP_Map.getWeaponData();
//
//bool Inventory::IdentifyItem(const Item& item, int classNum) {
//    //classNum(직업 enum)과 ItemMap 직업과 일치하는지 확인
//
//    return true;//직업과 불일치하면 True 일치하면 False
//}
//
//void Inventory::AddUserItem(const Item& item, int classNum) {
//    //item 종류가 Weapon이고 직업과 일치하는지 확인하기
//    if(3==static_cast<int>(item.getType()) && IdentifyItem(item, classNum)) {
//        std::cout << "직업이 일치하지 않습니다."<<std::endl;
//    }
//    UserItems.push_back(item);
//    std::cout << item.getName() << "이(가) 인벤토리에 추가되었습니다.\n";
//}
//
//void Inventory::ShowUserItems() {
//    if (UserItems.empty()) {
//        std::cout << "인벤토리가 비어 있습니다.\n";
//        return;
//    }
//
//    std::cout << "\n[인벤토리 목록]\n";
//    for (size_t i = 0; i < UserItems.size(); ++i) {
//        std::cout << i + 1 << ". " << UserItems[i].getName() << "\n";
//    }
//}
//
//void Inventory::UseItem(int index) {
//    if (index < 1 || index >(int)UserItems.size()) {
//        std::cout << "잘못된 인덱스입니다.\n";
//        return;
//    }
//
//    UserItems[index - 1].use();
//    UserItems.erase(UserItems.begin() + (index - 1));
//}
