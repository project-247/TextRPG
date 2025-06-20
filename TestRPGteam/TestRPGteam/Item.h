#ifndef ITEM_H
#define ITEM_H

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
    Item(std::string name, ItemType type, int value);

    std::string getName() const;
    ItemType getType() const;
    int getValue() const;

    void use();
};

#endif
