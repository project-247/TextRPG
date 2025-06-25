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
    void DisplayItems() const;        // ���� showItems ��� ���
    bool BuyItem(int index, Character* player);  // ���� buyItem ��� ���
    int GetStockSize() const;

private:
    std::vector<Item> stock;
    Image image;
};