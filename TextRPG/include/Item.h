#pragma once
#include <string>

enum class ItemType {
    NONE,    // 기본값 추가
    HEAL,
    BOOST,
    GOLD,
    WEAPON,
};

class Character; // 전방 선언

class Item {
private:
    std::string name;
    ItemType type;
    int value;
    int price;

public:
    // 기본 생성자 추가 (초기화 리스트로 안전하게 초기화)
    Item() : name(""), type(ItemType::NONE), value(0), price(0) {}

    Item(std::string name, ItemType type, int value, int price);

    std::string getName() const;
    ItemType getType() const;
    int getValue() const;
    int getPrice() const;

    void use(Character* player);
};
