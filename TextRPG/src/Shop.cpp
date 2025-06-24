#include "Shop.h"
#include "Character.h"
#include "WeaponMap.h"
#include <iostream>

void Shop::showMenu() {
	int choice;

	Character* player = Character::NewCharacter();
	Inventory playerInventory;  // 전달받을 수도 있음 (지금은 예시로 생성)

	while (true) {
		std::cout << "\n===== ?? 상점 =====\n";
		std::cout << "1. 아이템 보기\n";
		std::cout << "2. 아이템 구매\n";
		std::cout << "3. 나가기\n";
		std::cout << "선택: ";
		std::cin >> choice;

		if (choice == 1) {
			showItems();
		}
		else if (choice == 2) {
			showItems();
			std::cout << "구매할 아이템 번호 입력: ";
			int index;
			std::cin >> index;
			buyItem(index, playerInventory);
		}
		else if (choice == 3) {
			std::cout << "상점을 나갑니다.\n";
			break;
		}
		else {
			std::cout << "잘못된 입력입니다.\n";
		}
	}
}

void Shop::showItems() {
	std::cout << "\n[판매 목록]\n";
	for (size_t i = 0; i < stock.size(); ++i) {
		std::cout << i + 1 << ". " << stock[i].getName() << " - 가격: " << stock[i].getValue() << "G\n";
	}
}

//직업에 해당하는 아이템 불러오기
void Shop::LoadItemsForJob(const std::string& job) {
	items.clear();
	const auto& weaponMap = WeaponMap::getWeaponData();
	auto it = weaponMap.find(job);
	if (it != weaponMap.end()) {
		items = it->second; //push_back 안 햇는데 되넹
	}
}

void Shop::buyItem(int index, Inventory& inventory) {
	Character* player = Character::NewCharacter();

	if (index < 1 || index >(int)stock.size()) {
		std::cout << "잘못된 번호입니다.\n";
		return;
	}

	Item item = stock[index - 1];
	long long price = item.getValue();

	if (player->GetGold() < price) {
		std::cout << "소지금이 부족합니다!\n";
		return;
	}

	player->SetGold(-price);  // 골드 차감
	inventory.AddUserItem(item, player->GetJob());  // 인벤토리에 아이템 추가
	std::cout << item.getName() << "을(를) 구매했습니다!\n";
}

void Shop::DisplayItems() const {
	std::cout << "=== 상점 아이템 목록 ===\n";
	for (size_t i = 0; i < items.size(); ++i) {
		std::cout << i + 1 << ". " << items[i].getName()
			<< " (공격력: " << items[i].getValue()
			<< ", 가격: " << items[i].getPrice() << "골드)\n";
	}
}

bool Shop::BuyItem(int index, Character* player) {
	if (index < 1 || index >(int)items.size()) {
		std::cout << "잘못된 아이템 번호입니다.\n";
		return false;
	}

	const Item& item = items[index - 1];

	if (player->GetGold() < item.getPrice()) {
		std::cout << "골드가 부족합니다.\n";
		return false;
	}

	player->SetGold(player->GetGold() - item.getPrice());
	player->inventory->AddUserItem(item, player->GetJob());  // 인벤토리에 아이템 추가 함수

	std::cout << item.getName() << " 아이템을 구매했습니다!\n";
	return true;
}