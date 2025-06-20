#pragma once
#ifndef SHOP_H
#define SHOP_H
#include"monster.h"
#include "Item.h"
#include "Inventory.h"
#include <vector>

class Shop {
private:
    std::vector<Item> stock;

public:
    Shop();  // ���� �ʱ�ȭ (�⺻ ������ ���)

    void showMenu();
    void showItems();
    void buyItem(int index, Inventory& inventory);
};

#endif
