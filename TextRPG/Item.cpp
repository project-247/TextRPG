//#include "Item.h"
//#include "Character.h"
//#include "WeaponMap.h"
//#include <iostream>
//
//Item::Item(std::string name, ItemType type, int value)
//    : name(std::move(name)), type(type), value(value) {
//}

//std::string Item::getName() const { return name; }
//ItemType Item::getType() const { return type; }
//int Item::getValue() const { return value; }
//
//void Item::use(Character* player) {
//    if (!player) {
//        std::cerr << "Error: 아이템 사용 시 유효한 캐릭터 객체가 필요합니다.\n";
//        return;
//    }
//
//    switch (type) {
//    case ItemType::HEAL:
//        std::cout << name << " 사용! 체력 회복 " << value << " (랜덤 포함)\n";
//        player->heal(value);
//        break;
//
//    case ItemType::BOOST:
//        std::cout << name << " 사용! 공격력 + " << value << "\n";
//        player->boostAttack(value);
//        break;
//
//    case ItemType::GOLD:
//        player->addGold(value);
//        std::cout << "골드 획득: " << value << "G\n";
//        break;
//
//    case ItemType::WEAPON: {
//        auto weaponData = WeaponMap::getWeaponData();
//        std::string job = player->getJob();
//
//        bool found = false;
//        if (job == "무직") {
//            auto allWeapons = WeaponMap::getAllWeaponsForNoJob();
//            for (const auto& weapon : allWeapons) {
//                if (weapon.getName() == name) {
//                    player->equipWeapon(weapon);
//                    std::cout << name << " 무기 장착 완료! (공격력 +" << weapon.getValue() << ")\n";
//                    found = true;
//                    break;
//                }
//            }
//        }
//        else {
//            if (weaponData.find(job) != weaponData.end()) {
//                for (const auto& weapon : weaponData[job]) {
//                    if (weapon.getName() == name) {
//                        player->equipWeapon(weapon);
//                        std::cout << name << " 무기 장착 완료! (공격력 +" << weapon.getValue() << ")\n";
//                        found = true;
//                        break;
//                    }
//                }
//            }
//        }
//
//        if (!found) {
//            std::cout << name << "은(는) 직업 " << job << " 무기 목록에 없습니다.\n";
//        }
//        break;
//    }
//    }
//}
