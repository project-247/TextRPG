#pragma once
#include"monster.h"
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include <vector>

class Shop {
private:
    std::vector<Item> stock;
    std::vector<Item> items;

public:
    Shop() {
        stock.emplace_back("ġ�� ����", ItemType::HEAL, 50, 10);
        stock.emplace_back("������ ����", ItemType::BOOST, 10, 20);
        stock.emplace_back("����ź", ItemType::BOOST, 100, 50);
    }  // ������

    void showMenu();
    void showItems();
    void buyItem(int index, Inventory& inventory);
    void LoadItemsForJob(const std::string&);
    void DisplayItems() const;
    bool BuyItem(int index, Character* player);  //
};
