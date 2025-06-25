
#include "Shop.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>

Shop::Shop() {
    // 기본 공용 아이템 초기화
    stock.push_back(Item("힐 포션", ItemType::HEAL, 50, 100));
    stock.push_back(Item("힘 포션", ItemType::BOOST, 10, 120));
    stock.push_back(Item("골드 상자", ItemType::GOLD, 500, 10));
}

void Shop::LoadItemsForJob(const std::string& job) {
    stock.clear();
    const auto& weaponMap = WeaponMap::getWeaponData();
    if (job == "무직") {
        // 모든 직업 무기를 한데 모아서 랜덤 2개 선택
        std::vector<Item> allWeapons;
        for (const auto& pair : weaponMap) {
            allWeapons.insert(allWeapons.end(), pair.second.begin(), pair.second.end());
        }
        // 인덱스 벡터 생성 후 섞기
        std::vector<int> indices(allWeapons.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(indices.begin(), indices.end(), g);
        int pickCount = std::min(2, (int)allWeapons.size());
        for (int i = 0; i < pickCount; ++i) {
            stock.push_back(allWeapons[indices[i]]);
        }
    }
    else {
        auto it = weaponMap.find(job);
        if (it != weaponMap.end()) {
            stock = it->second; // 해당 직업 무기 전부 추가
        }
    }
    // 공용 아이템 추가
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
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
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

    system("cls");
    //모코코 출력
    image.leaf();
    //전체 메뉴창 출력
    image.RenderSystemUI();
    //우측 메뉴창 출력 >>인자 안 받는 방식으로 수정 예정
    image.RenderMenu();
    //Text RPG 이미지 출력 >> 창 아래로 커서 이동
    image.Loading2(60, 3);
    image.ShowCharacterUI(character->GetChName(), character->GetChLevel(), character->GetChJob(), character->GetChHP(), character->RetInventory().ReturnNowWeapon().getName(), character->GetChAttack(), character->GetGold());

    _getch();
// ---------------------------------------------------------------------------------------------------------------

    if (item.getType() == ItemType::HEAL || item.getType() == ItemType::BOOST || item.getType() == ItemType::GOLD) {
        item.use(player);  // 즉시 사용
        image.ShowCharacterUI(character->GetChName(), character->GetChLevel(), character->GetChJob(), character->GetChHP(), character->RetInventory().ReturnNowWeapon().getName(), character->GetChAttack(), character->GetGold());

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