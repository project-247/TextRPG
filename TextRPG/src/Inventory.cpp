#include "Inventory.h"
#include "WeaponMap.h"
#include <iostream>

//클래스 밖에서 정적함수 정의
std::vector<std::pair<Item, int>> Inventory::UserItems;

bool Inventory::IdentifyItem(const Item& item, std::string jobName)
{
    if (jobName == "무직") return false; // 무직은 모두 장착

    auto& weaponData = WeaponMap::getWeaponData();

    //weaponData의 직업 무기 순회
    for (const auto& weapon : weaponData.at(jobName)) {
        // 입력된 item이름과 Weapon이름 비교
        if (weapon.getName() == item.getName()) {
            //이름이 일치
            return false;
        }
    }
    return true; // 불일치
}

//아이템 객체의 개수를 반환하는 함수
int Inventory::ReturnItemNumber(const Item& item)
{
    //for문이 아니라 find로 찾을 수 있을지도
    int num = 0;
    for (auto it : UserItems) {
        if (it.first.getName() == item.getName()) {
            num += it.second;
        }
    }
    return num;
}

void Inventory::AddUserItem(const Item& item, std::string jobName)
{
    //무기이며 직업과 일치하지 않을 때
    if (item.getType() == ItemType::WEAPON && IdentifyItem(item, jobName))
    {
        std::cout << "직업이 일치하지 않아 " << item.getName() << "을(를) 추가할 수 없습니다.\n";
        return;
    }
    //여기서 상점 구매하려면 return값을 줘야 하나
    UserItems.push_back({ item, 1 });
    std::cout << item.getName() << "이(가) 인벤토리에 추가되었습니다. (개수 : " << ReturnItemNumber(item) << "개)" << std::endl;
    //무기일 때 NowWeapon 변경
    if (item.getType() == ItemType::WEAPON) {
        SetTopWeapon();
    }
}

//모든 아이템을 출력하는 메서드
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
        //무기가 아닐 때
        if (UserItems[i].first.getType()!=ItemType::WEAPON && UserItems[i].second > 0)
        {
            std::cout << i + 1 << ". " << UserItems[i].first.getName() << UserItems[i].second << "개\n";
        }
        //무기일 때
        if (UserItems[i].first.getType() == ItemType::WEAPON && UserItems[i].second > 0)
        {
            std::cout << i + 1 << ". " << UserItems[i].first.getName() <<" (무기)" << "\n";
        }

    }
}

//이이템 개수가 0이면 UserItems에서 삭제 메서드
void Inventory::DeleteItem(int index)
{
    UserItems.erase(UserItems.begin() + index);
}

//아이템을 사용하여 개수를 감소시키는 메서드
void Inventory::UseItem(int index)
{
    if (index < 1 || index >UserItems.size())
    {
        std::cout << "잘못된 인덱스입니다.\n";
        return;
    }
    if (UserItems[index].second <= 0)
    {
        std::cout << UserItems[index].first.getName() << "은 더이상 사용할 수 없습니다." << std::endl;
        return;
    }
    std::cout << UserItems[index].first.getName() << "을 사용하였습니다. 남은 개수 : " << --UserItems[index].second << "개" << std::endl;
    //개수가 0이면 map에서 삭제하는 메서드
    DeleteItem(index);
}

//새 무기가 들어왔을 때 기본 무기와 비교 후 공격력이 강한 무기를 NowWeapon에 저장하는 메서드 > 반환은 ReturnNowWeapon()
void Inventory::SetTopWeapon() {
    for (size_t i = 0; i < UserItems.size(); ++i) {
        if (UserItems[i].first.getType() != ItemType::WEAPON)
        {
            ++i;
            continue;
        }
        else if (NowWeapon.getValue() < UserItems[i].first.getValue())
        {
            NowWeapon = (UserItems[i]).first;
        }
    }
}

//현재 무기 반환 메서드
Item Inventory::ReturnNowWeapon() {
    return NowWeapon;
}

//현재 무기 공격력 반환 > 재사용성을 위해 삭제 가능
int Inventory::NowWeaponAttack() {
    return NowWeapon.getValue();
}


void Inventory::AddFirst()
{
    NowWeapon = { "주먹",ItemType::WEAPON, 0 };
    UserItems.push_back({ NowWeapon,1 });
}