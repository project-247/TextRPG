#pragma once
#include <vector>
#include <utility> // std::pair
#include "Item.h"

class Inventory {
private:
    static std::vector<std::pair<Item, int>> UserItems;
    Item NowWeapon;

public:
    Inventory();

    void AddUserItem(const Item&, std::string);
    void ShowUserItems();
    void UseItem(int index);
    void DeleteItem(int);
    void SetTopWeapon();
    Item ReturnNowWeapon();
    int NowWeaponAttack();
    bool IdentifyItem(const Item&, std::string);
    int ReturnItemNumber(const Item&);
    void AddFirst();
};
