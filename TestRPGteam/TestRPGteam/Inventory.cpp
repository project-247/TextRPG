#include "Inventory.h"
#include "WeaponMap.h"
#include <iostream>

bool Inventory::IdentifyItem(const Item& item, int classNum) {
    // classNum: 1=����, 2=�ü�, 3=����, 4=����
    // ���� Ÿ������ Ȯ��
    if (item.getType() != ItemType::WEAPON)
        return false; // ���Ⱑ �ƴϸ� �н�

    std::string jobName;
    switch (classNum) {
    case 1: jobName = "����"; break;
    case 2: jobName = "�ü�"; break;
    case 3: jobName = "����"; break;
    case 4: jobName = "����"; break;
    default: return true; // ���� �Ҹ� => ����ġ
    }

    auto weaponData = WeaponMap::getWeaponData();

    if (jobName == "����") return false; // ������ ��� ���� ����

    if (weaponData.find(jobName) == weaponData.end()) return true; // ���� ���� ������ ����

    // ���� ���� ��Ͽ� �ִ��� Ȯ��
    for (auto& w : weaponData[jobName]) {
        if (w.getName() == item.getName()) {
            return false; // ����� ���� ��ġ
        }
    }

    return true; // ����ġ
}

void Inventory::AddUserItem(const Item& item, int classNum) {
    if (item.getType() == ItemType::WEAPON && IdentifyItem(item, classNum)) {
        std::cout << "������ ��ġ���� �ʾ� " << item.getName() << "��(��) �߰��� �� �����ϴ�.\n";
        return;
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

void Inventory::UseItem(int index, Character* player) {
    if (index < 1 || index >(int)UserItems.size()) {
        std::cout << "�߸��� �ε����Դϴ�.\n";
        return;
    }

    UserItems[index - 1].use(player);
    UserItems.erase(UserItems.begin() + (index - 1));
}
