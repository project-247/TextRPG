#include "Item.h"
#include "Character.h"
#include "WeaponMap.h"
#include <iostream>

//Item::Item(std::string name, ItemType type, int value,)
//    : name(std::move(name)), type(type), value(value) {
//}

std::string Item::getName() const { return name; }
ItemType Item::getType() const { return type; }
int Item::getValue() const { return value; }
int Item::getPrice() const { return price; }

void Item::use(Character* player) {
    if (!player) {
        std::cerr << "Error: 캐릭터가 없습니다.\n";
        return;
    }
    switch (type) {
    case ItemType::HEAL:
        std::cout << name << " 사용! 체력 +" << value << std::endl;
        player->ChHPUpDown(value);
        break;
    case ItemType::BOOST:
        std::cout << name << " 사용! 공격력 +" << value << std::endl;
        player->ChAttackUpDown(value);
        break;
    case ItemType::GOLD:
        player->SetGold(value);
        std::cout << value << "골드 획득!\n";
        break;
    }
}
