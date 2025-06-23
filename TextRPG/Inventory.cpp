#pragma once
#include "Inventory.h"
#include "WeaponMap.h"
#include <iostream>

//WeaponMap WP_Map;
//std::map<std::string, std::vector<Item>> weaponMap;
//weaponMap=WP_Map.getWeaponData();

bool Inventory::IdentifyItem(const Item& item, int classNum) {
    //classNum(���� enum)�� ItemMap ������ ��ġ�ϴ��� Ȯ��

    return true;//������ ����ġ�ϸ� True ��ġ�ϸ� False
}

void Inventory::AddUserItem(const Item& item, int classNum) {
    //item ������ Weapon�̰� ������ ��ġ�ϴ��� Ȯ���ϱ�
    if(3==static_cast<int>(item.getType()) && IdentifyItem(item, classNum)) {
        std::cout << "������ ��ġ���� �ʽ��ϴ�."<<std::endl;
    }
    UserItems.push_back(item);
    std::cout << item.getName() << "��(��) �κ��丮�� �߰��Ǿ����ϴ�.\n";
}

void Inventory::ShowUserItems() {
    if (UserItems.empty()) {
        std::cout << "�κ��丮�� ��� �ֽ��ϴ�.\n";
        return;
    }

    std::cout << "\n[�κ��丮 ���]\n";
    for (size_t i = 0; i < UserItems.size(); ++i) {
        std::cout << i + 1 << ". " << UserItems[i].getName() << "\n";
    }
}

void Inventory::UseItem(int index) {
    if (index < 1 || index >(int)UserItems.size()) {
        std::cout << "�߸��� �ε����Դϴ�.\n";
        return;
    }

    UserItems[index - 1].use();
    UserItems.erase(UserItems.begin() + (index - 1));
}
