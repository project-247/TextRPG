#pragma once
#include "Item.h"

class Core : public Item {
public:
    Core(std::string name) : Item(name, ItemType::CORE, 0, 200) {}
    Core() : Item() {}
};
