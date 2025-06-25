
#include "Shop.h"
#include <iostream>

Shop::Shop() {
    // 기본 공용 아이템 초기화
    stock.push_back(Item("힐 포션", ItemType::HEAL, 50, 100));
    stock.push_back(Item("힘 포션", ItemType::BOOST, 10, 120));
    stock.push_back(Item("골드 상자", ItemType::GOLD, 500, 10));
}

void Shop::LoadItemsForJob(const std::string& job) {
    // 직업별 무기 데이터 로드 (WeaponMap 가정)
    const auto& weaponMap = WeaponMap::getWeaponData();
    auto it = weaponMap.find(job);
    if (it != weaponMap.end()) {
        stock = it->second;
    }

    // 공용 아이템 다시 추가
    stock.push_back(Item("힐 포션", ItemType::HEAL, 50, 100));
    stock.push_back(Item("힘 포션", ItemType::BOOST, 10, 120));
    stock.push_back(Item("골드 상자", ItemType::GOLD, 500, 100));
}

void Shop::DisplayItems() const {
    
    std::cout << "\n[판매 목록]\n\n";
    for (size_t i = 0; i < stock.size(); ++i) {
        std::cout << i + 1 << ". " << stock[i].getName()
            << " - 가격: " << stock[i].getPrice() << "G\n";
    }
}
// ---------------------------------------------------------------------------------------------------------------
bool Shop::BuyItem(int index, Character* player) {
    
    if (index < 1 || index >(int)stock.size()) {
        std::cout << "잘못된 번호입니다.\n";
        return false;
    }
    Item& item = stock[index - 1];
    int price = item.getPrice();

    if (player->GetGold() < price) {
        std::cout << "골드가 부족합니다!\n";
        return false;
    }

    player->SetGold(-price);  // 골드 차감
    std::cout << "\033[32m" << item.getName() << "\033[0m 를 구매했습니다!\n";
    std::cout << "\n\n \033[36m계속하려면 아무키나 누르세요...\033[0m";

    _getch();
    system("cls");
    //모코코 출력
    image.leaf();
    //전체 메뉴창 출력
    image.RenderSystemUI();
    //우측 메뉴창 출력 >>인자 안 받는 방식으로 수정 예정
    image.RenderMenu(60, 15);
    //Text RPG 이미지 출력 >> 창 아래로 커서 이동
    image.Loading2(60, 3);
    
// ---------------------------------------------------------------------------------------------------------------

    if (item.getType() == ItemType::HEAL || item.getType() == ItemType::BOOST || item.getType() == ItemType::GOLD) {
        item.use(player);  // 즉시 사용
    }
    else {
        // 무기나 기타 아이템은 인벤토리에 추가
        player->inventory->AddUserItem(item, player->GetChJob());
    }


    return true;
}
// ---------------------------------------------------------------------------------------------------------------
int Shop::GetStockSize() const {
    return static_cast<int>(stock.size());
}