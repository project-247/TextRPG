#pragma once

#include <vector>
#include "Item.h"

class Inventory {
private:
    //
    std::vector<Item> UserItems;

public:
    Inventory(){}
    //입력 : item 객체 + 직업 번호
    void AddUserItem(const Item& item, int classNum);
    void ShowUserItems();
    void UseItem(int index);
    //무기가 캐릭터 직업과 일치하는지 확인하는 메서드
    bool IdentifyItem(const Item& item, int classNum);
};
