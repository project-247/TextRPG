#pragma once

#include <vector>
#include "Item.h"

//성신님감사합니다 이 코드는 이제 제 겁니다

class Inventory {
private:
    //std::vector<Item> Items;

public:
    Inventory(){}
    void AddUserItem(const Item& item);
    void ShowUserItems();
    void UseItem(int index);
};
