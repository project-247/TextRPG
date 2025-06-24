#include "Item.h"
#include "Character.h"
#include <iostream>

// 생성자
Item::Item(std::string name, ItemType type, int value, int price)
    : name(std::move(name)), type(type), value(value), price(price) {
}

// Getter 구현
std::string Item::getName() const { return name; }
ItemType Item::getType() const { return type; }
int Item::getValue() const { return value; }
int Item::getPrice() const { return price; }

// 아이템 사용 구현
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
        srand(time(0));
        player->SetGold((rand() % 450 ) + 50 );
        std::cout << (rand() % 450) + 50 << "골드 획득!\n";
        break;

    default:
        std::cout << "알 수 없는 아이템 타입입니다.\n";
        break;
    }
}
