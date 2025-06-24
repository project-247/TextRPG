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
        stock.emplace_back("치유 물약", ItemType::HEAL, 50, 10);
        stock.emplace_back("공격의 반지", ItemType::BOOST, 10, 20);
        stock.emplace_back("왕폭탄", ItemType::BOOST, 100, 50);
    }  // 생성자

    void showMenu();
    void showItems();
    void buyItem(int index, Inventory& inventory);
    void LoadItemsForJob(const std::string&);
    void DisplayItems() const;
    bool BuyItem(int index, Character* player);  //
};
