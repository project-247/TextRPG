#pragma once
#include "Inventory.h"
#include <iostream>
//���Ŵ԰����մϴ� �� �ڵ�� ���� �� �̴ϴ�

//void Inventory::AddUserItem(const Item& item) {
//    items.push_back(item);
//    std::cout << item.getName() << "��(��) �κ��丮�� �߰��Ǿ����ϴ�.\n";
//}
//
//void Inventory::ShowUserItems() {
//    if (items.empty()) {
//        std::cout << "�κ��丮�� ��� �ֽ��ϴ�.\n";
//        return;
//    }
//
//    std::cout << "\n[�κ��丮 ���]\n";
//    for (size_t i = 0; i < items.size(); ++i) {
//        std::cout << i + 1 << ". " << items[i].getName() << "\n";
//    }
//}
//
//void Inventory::UseItem(int index) {
//    if (index < 1 || index >(int)items.size()) {
//        std::cout << "�߸��� �ε����Դϴ�.\n";
//        return;
//    }
//
//    items[index - 1].use();
//    items.erase(items.begin() + (index - 1));
//}
