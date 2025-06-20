#pragma once

#include <map>
#include <vector>
#include <string>
#include "Item.h"

class WeaponMap {
public:
    // 직업별 무기 데이터 (무직 제외)
    static const std::map<std::string, std::vector<Item>>& getWeaponData() {
        static std::map<std::string, std::vector<Item>> weaponMap = {
            { "전사", {
                Item("강철검", ItemType::WEAPON, 30),
                Item("버그검", ItemType::WEAPON, 50)
            }},
            { "도적", {
                Item("단검", ItemType::WEAPON, 20),
                Item("디버깅단검", ItemType::WEAPON, 40)
            }},
            { "궁수", {
                Item("활", ItemType::WEAPON, 25),
                Item("헤더화살", ItemType::WEAPON, 45)
            }},
        };
        return weaponMap;
    }

    // 무직용 무기는 모든 직업 무기를 합쳐서 얻는 함수 (포션, 스크롤 제외)
    static std::vector<Item> getAllWeaponsForNoJob() {
        const auto& weaponMap = getWeaponData();
        std::vector<Item> allWeapons;
        for (const auto& pair : weaponMap) {
            allWeapons.insert(allWeapons.end(), pair.second.begin(), pair.second.end());
        }
        // 무직 무기 예시 아이템도 추가 가능
        allWeapons.push_back(Item("막대기", ItemType::WEAPON, 10));
        allWeapons.push_back(Item("방망이", ItemType::WEAPON, 35));
        return allWeapons;
    }
};

