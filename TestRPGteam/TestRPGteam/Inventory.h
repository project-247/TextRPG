#pragma once

#include <vector>
#include "Item.h"

//���Ŵ԰����մϴ� �� �ڵ�� ���� �� �̴ϴ�

class Inventory {
private:
    //std::vector<Item> Items;

public:
    Inventory(){}
    void AddUserItem(const Item& item);
    void ShowUserItems();
    void UseItem(int index);
};
