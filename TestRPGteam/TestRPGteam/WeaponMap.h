#pragma once

#include <map>
#include <vector>
#include <string>
#include "Item.h"

class WeaponMap {
public:
    // ������ ���� ������ (���� ����)
    static const std::map<std::string, std::vector<Item>>& getWeaponData() {
        static std::map<std::string, std::vector<Item>> weaponMap = {
            { "����", {
                Item("��ö��", ItemType::WEAPON, 30),
                Item("���װ�", ItemType::WEAPON, 50)
            }},
            { "����", {
                Item("�ܰ�", ItemType::WEAPON, 20),
                Item("�����ܰ�", ItemType::WEAPON, 40)
            }},
            { "�ü�", {
                Item("Ȱ", ItemType::WEAPON, 25),
                Item("���ȭ��", ItemType::WEAPON, 45)
            }},
        };
        return weaponMap;
    }

    // ������ ����� ��� ���� ���⸦ ���ļ� ��� �Լ� (����, ��ũ�� ����)
    static std::vector<Item> getAllWeaponsForNoJob() {
        const auto& weaponMap = getWeaponData();
        std::vector<Item> allWeapons;
        for (const auto& pair : weaponMap) {
            allWeapons.insert(allWeapons.end(), pair.second.begin(), pair.second.end());
        }
        // ���� ���� ���� �����۵� �߰� ����
        allWeapons.push_back(Item("�����", ItemType::WEAPON, 10));
        allWeapons.push_back(Item("�����", ItemType::WEAPON, 35));
        return allWeapons;
    }
};

