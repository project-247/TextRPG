#pragma once
#include <string>

enum class ItemType {
    HEAL,
    BOOST,
    GOLD,
    WEAPON
};

class Item {
private:
    std::string name;
    ItemType type;
    int value;

public:
    //인벤토리 작업을 위한 기본 생성자 추가
    Item() {}
    Item(std::string name, ItemType type, int value);

    std::string getName() const;
    ItemType getType() const;
    int getValue() const;

    void use(class Character* player); // 캐릭터 포인터 받음
};
