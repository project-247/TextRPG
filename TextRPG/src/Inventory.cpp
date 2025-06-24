#include "Inventory.h"
#include "WeaponMap.h"
#include <iostream>
#include "Item.h"

// 정적 멤버 정의
std::vector<std::pair<Item, int>> Inventory::UserItems;

// 기본 생성자 구현 추가
Inventory::Inventory() {
    AddFirst();
}

bool Inventory::IdentifyItem(const Item& item, std::string jobName)
{
    if (jobName == "무직") return false; // 무직은 모두 장착 가능

    auto& weaponData = WeaponMap::getWeaponData();

    // 직업 무기 목록 조회
    auto it = weaponData.find(jobName);
    if (it == weaponData.end()) return true; // 직업이 없으면 장착 불가 처리

    for (const auto& weapon : it->second) {
        if (weapon.getName() == item.getName()) {
            return false; // 직업 무기일 경우 장착 가능
        }
    }
    return true; // 직업 무기가 아닐 경우 장착 불가
}

int Inventory::ReturnItemNumber(const Item& item)
{
    int num = 0;
    for (const auto& it : UserItems) {
        if (it.first.getName() == item.getName()) {
            num += it.second;
        }
    }
    return num;
}

void Inventory::AddUserItem(const Item& item, std::string jobName)
{
    if (item.getType() == ItemType::WEAPON && IdentifyItem(item, jobName))
    {
        std::cout << "직업이 일치하지 않아 " << item.getName() << "을(를) 추가할 수 없습니다.\n";
        return;
    }

    // 이미 같은 아이템이 있으면 개수 증가
    for (auto& it : UserItems) {
        if (it.first.getName() == item.getName()) {
            it.second++;
            std::cout << item.getName() << "이(가) 인벤토리에 추가되었습니다. (개수 : " << it.second << "개)\n";
            if (item.getType() == ItemType::WEAPON) {
                SetTopWeapon();
            }
            return;
        }
    }

    // 없으면 새로 추가
    UserItems.push_back({ item, 1 });
    std::cout << item.getName() << "이(가) 인벤토리에 추가되었습니다. (개수 : 1개)\n";

    if (item.getType() == ItemType::WEAPON) {
        SetTopWeapon();
    }
}

void Inventory::ShowUserItems()
{
    if (UserItems.empty())
    {
        std::cout << "인벤토리가 비어 있습니다.\n";
        return;
    }
    std::cout << "\n[인벤토리 목록]\n";
    for (size_t i = 0; i < UserItems.size(); ++i)
    {
        if (UserItems[i].second > 0) {
            if (UserItems[i].first.getType() == ItemType::WEAPON) {
                std::cout << i + 1 << ". " << UserItems[i].first.getName() << " (무기)\n";
            }
            else {
                std::cout << i + 1 << ". " << UserItems[i].first.getName() << " " << UserItems[i].second << "개\n";
            }
        }
    }
}

void Inventory::DeleteItem(int index)
{
    if (index < 0 || index >= (int)UserItems.size()) {
        std::cout << "잘못된 인덱스 삭제 시도\n";
        return;
    }
    UserItems.erase(UserItems.begin() + index);
}

void Inventory::UseItem(int index)
{
    if (index < 1 || index >(int)UserItems.size())
    {
        std::cout << "잘못된 인덱스입니다.\n";
        return;
    }
    int idx = index - 1;

    if (UserItems[idx].second <= 0)
    {
        std::cout << UserItems[idx].first.getName() << "은 더이상 사용할 수 없습니다." << std::endl;
        return;
    }

    UserItems[idx].second--;
    std::cout << UserItems[idx].first.getName() << "을 사용하였습니다. 남은 개수 : " << UserItems[idx].second << "개" << std::endl;

    if (UserItems[idx].second <= 0) {
        DeleteItem(idx);
    }
}

void Inventory::SetTopWeapon() {
    for (size_t i = 0; i < UserItems.size(); ++i) {
        if (UserItems[i].first.getType() != ItemType::WEAPON)
        {
            continue;
        }
        else if (NowWeapon.getValue() < UserItems[i].first.getValue())
        {
            NowWeapon = UserItems[i].first;
        }
    }
}

Item Inventory::ReturnNowWeapon() {
    return NowWeapon;
}

int Inventory::NowWeaponAttack() {
    return NowWeapon.getValue();
}

void Inventory::AddFirst()
{
    NowWeapon = { "주먹", ItemType::WEAPON, 0, 0 };
    UserItems.push_back({ NowWeapon, 1 });
}
