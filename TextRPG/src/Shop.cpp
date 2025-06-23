#include "Shop.h"
#include "Character.h"
#include <iostream>

//Shop::Shop() {
//    // ������ �Ǹ��� ������ �̸� ���
//    stock.emplace_back("ġ�� ����", ItemType::HEAL, 50);
//    stock.emplace_back("������ ����", ItemType::BOOST, 10);
//    stock.emplace_back("Ȳ�� ���� ����", ItemType::GOLD, 100);
//}
//
//void Shop::showMenu() {
//    int choice;
//
//    Character* player = Character::NewCharacter();
//    Inventory playerInventory;  // ���޹��� ���� ���� (������ ���÷� ����)
//
//    while (true) {
//        std::cout << "\n===== ?? ���� =====\n";
//        std::cout << "1. ������ ����\n";
//        std::cout << "2. ������ ����\n";
//        std::cout << "3. ������\n";
//        std::cout << "����: ";
//        std::cin >> choice;
//
//        if (choice == 1) {
//            showItems();
//        }
//        else if (choice == 2) {
//            showItems();
//            std::cout << "������ ������ ��ȣ �Է�: ";
//            int index;
//            std::cin >> index;
//            buyItem(index, playerInventory);
//        }
//        else if (choice == 3) {
//            std::cout << "������ �����ϴ�.\n";
//            break;
//        }
//        else {
//            std::cout << "�߸��� �Է��Դϴ�.\n";
//        }
//    }
//}
//
//void Shop::showItems() {
//    std::cout << "\n[�Ǹ� ���]\n";
//    for (size_t i = 0; i < stock.size(); ++i) {
//        std::cout << i + 1 << ". " << stock[i].getName() << " - ����: " << stock[i].getValue() << "G\n";
//    }
//}
//
//void Shop::buyItem(int index, Inventory& inventory) {
//    Character* player = Character::newCharacter();
//
//    if (index < 1 || index >(int)stock.size()) {
//        std::cout << "�߸��� ��ȣ�Դϴ�.\n";
//        return;
//    }
//
//    Item item = stock[index - 1];
//    long long price = item.getValue();
//
//    if (player->GetGold() < price) {
//        std::cout << "�������� �����մϴ�!\n";
//        return;
//    }
//
//    player->SetGold(-price);  // ��� ����
//    inventory.addItem(item);  // �κ��丮�� ������ �߰�
//    std::cout << item.getName() << "��(��) �����߽��ϴ�!\n";
//}
