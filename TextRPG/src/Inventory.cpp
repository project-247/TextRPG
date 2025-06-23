//#include "Inventory.h"
//#include "WeaponMap.h"
//#include <iostream>
//
//bool Inventory::IdentifyItem(const Item& item, int classNum) {
//    // classNum: 1=전사, 2=궁수, 3=도적, 4=무직
//    // 무기 타입인지 확인
//    if (item.getType() != ItemType::WEAPON)
//        return false; // 무기가 아니면 패스
//
//    std::string jobName;
//    switch (classNum) {
//    case 1: jobName = "전사"; break;
//    case 2: jobName = "궁수"; break;
//    case 3: jobName = "도적"; break;
//    case 4: jobName = "무직"; break;
//    default: return true; // 직업 불명 => 불일치
//    }
//
//    auto weaponData = WeaponMap::getWeaponData();
//
//    if (jobName == "무직") return false; // 무직은 모두 장착 가능
//
//    if (weaponData.find(jobName) == weaponData.end()) return true; // 직업 무기 데이터 없음
//
//    // 직업 무기 목록에 있는지 확인
//    for (auto& w : weaponData[jobName]) {
//        if (w.getName() == item.getName()) {
//            return false; // 무기와 직업 일치
//        }
//    }
//
//    return true; // 불일치
//}
//
//void Inventory::AddUserItem(const Item& item, int classNum) {
//    if (item.getType() == ItemType::WEAPON && IdentifyItem(item, classNum)) {
//        std::cout << "직업이 일치하지 않아 " << item.getName() << "을(를) 추가할 수 없습니다.\n";
//        return;
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
//    std::cout << "\n[인벤토리 목록]\n";
//    for (size_t i = 0; i < UserItems.size(); ++i) {
//        std::cout << i + 1 << ". " << UserItems[i].getName() << "\n";
//    }
//}
//
//void Inventory::UseItem(int index, Character* player) {
//    if (index < 1 || index >(int)UserItems.size()) {
//        std::cout << "잘못된 인덱스입니다.\n";
//        return;
//    }
//
//    UserItems[index - 1].use(player);
//    UserItems.erase(UserItems.begin() + (index - 1));
//}