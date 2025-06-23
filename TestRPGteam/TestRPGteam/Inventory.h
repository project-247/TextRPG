#pragma once

#include <vector>
#include "Item.h"

class Inventory {
private:
    //
    std::vector<Item> UserItems;

public:
    Inventory(){}
    //�Է� : item ��ü + ���� ��ȣ
    void AddUserItem(const Item& item, int classNum);
    void ShowUserItems();
    void UseItem(int index);
    //���Ⱑ ĳ���� ������ ��ġ�ϴ��� Ȯ���ϴ� �޼���
    bool IdentifyItem(const Item& item, int classNum);
};
