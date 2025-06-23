#include "Item.h"
#include "Character.h"
#include "WeaponMap.h"
#include <iostream>

Item::Item(std::string name, ItemType type, int value)
    : name(std::move(name)), type(type), value(value) {
}

//std::string Item::getName() const { return name; }
//ItemType Item::getType() const { return type; }
//int Item::getValue() const { return value; }
//
//void Item::use(Character* player) {
//    if (!player) {
//        std::cerr << "Error: ������ ��� �� ��ȿ�� ĳ���� ��ü�� �ʿ��մϴ�.\n";
//        return;
//    }
//
//    switch (type) {
//    case ItemType::HEAL:
//        std::cout << name << " ���! ü�� ȸ�� " << value << " (���� ����)\n";
//        player->heal(value);
//        break;
//
//    case ItemType::BOOST:
//        std::cout << name << " ���! ���ݷ� + " << value << "\n";
//        player->boostAttack(value);
//        break;
//
//    case ItemType::GOLD:
//        player->addGold(value);
//        std::cout << "��� ȹ��: " << value << "G\n";
//        break;
//
//    case ItemType::WEAPON: {
//        auto weaponData = WeaponMap::getWeaponData();
//        std::string job = player->getJob();
//
//        bool found = false;
//        if (job == "����") {
//            auto allWeapons = WeaponMap::getAllWeaponsForNoJob();
//            for (const auto& weapon : allWeapons) {
//                if (weapon.getName() == name) {
//                    player->equipWeapon(weapon);
//                    std::cout << name << " ���� ���� �Ϸ�! (���ݷ� +" << weapon.getValue() << ")\n";
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
//                        std::cout << name << " ���� ���� �Ϸ�! (���ݷ� +" << weapon.getValue() << ")\n";
//                        found = true;
//                        break;
//                    }
//                }
//            }
//        }
//
//        if (!found) {
//            std::cout << name << "��(��) ���� " << job << " ���� ��Ͽ� �����ϴ�.\n";
//        }
//        break;
//    }
//    }
//}
