#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include <conio.h>
#include "Image.h"

class Shop {
public:
    Shop();

    void LoadItemsForJob(const std::string& job);
    void DisplayItems() const;        // 기존 showItems 대신 사용
    bool BuyItem(int index, Character* player);  // 기존 buyItem 대신 사용
    int GetStockSize() const;

private:
    std::vector<Item> stock;
    Image image;
};