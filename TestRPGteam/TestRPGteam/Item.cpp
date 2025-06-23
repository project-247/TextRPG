#include "Item.h"
#include "Character.h"
#include "WeaponMap.h"
#include <iostream>

Item::Item(std::string name, ItemType type, int value)
    : name(std::move(name)), type(type), value(value) {
}

std::string Item::getName() const { return name; }
ItemType Item::getType() const { return type; }
int Item::getValue() const { return value; }

void Item::use(Character* player) {
    if (!player) {
        std::cerr << "Error: ĳ���Ͱ� �����ϴ�.\n";
        return;
    }

    switch (type) {
    case ItemType::HEAL:
        std::cout << name << " ���! ü�� +" << value << std::endl;
        player->ChHPUpDown(value);
        break;
    case ItemType::BOOST:
        std::cout << name << " ���! ���ݷ� +" << value << std::endl;
        player->ChAttackUpDown(value);
        break;
    case ItemType::GOLD:
        player->SetGold(value);
        std::cout << value << "��� ȹ��!\n";
        break;
    case ItemType::WEAPON: {
        auto weaponData = WeaponMap::getWeaponData();
        std::string job = player->GetJob();
        bool found = false;

        if (job == "����") {
            auto allWeapons = WeaponMap::getAllWeaponsForNoJob();
            for (auto& weapon : allWeapons) {
                if (weapon.getName() == name) {
                    player->equipWeapon(weapon.getName(), weapon.getValue());
                    found = true;
                    break;
                }
            }
        }
        else {
            if (weaponData.find(job) != weaponData.end()) {
                for (auto& weapon : weaponData[job]) {
                    if (weapon.getName() == name) {
                        player->equipWeapon(weapon.getName(), weapon.getValue());
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found) {
            std::cout << name << "��(��) ���� " << job << " ���� ��Ͽ� �����ϴ�.\n";
        }
        break;
    }
    }
}
