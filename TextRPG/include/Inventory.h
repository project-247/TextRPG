#pragma once
#include <vector>
#include "Item.h"


class Inventory {
private:
    static std::vector<std::pair<Item, int>> UserItems;
    Item NowWeapon;

public:
    Inventory() {
        AddFirst();//인벤토리 생성 시 기본 무기 - 주먹 추가
    }

    //UserItems에 아이템(힐포션, 버프포션, 골드, 무기) 추가
    void AddUserItem(const Item& item, std::string);
    //전체 아이템 목록 출력
    void ShowUserItems();
    //아이템 사용할 때 아이템 개수 감소
    void UseItem(int index);
    //아이템 개수가 0되면 삭제
    void DeleteItem(int);
    //무기가 들어오면 강한 무기로 변경하는 메서드
    void SetTopWeapon();
    //현재 무기 반환
    Item ReturnNowWeapon();
    //현재 무기의 공격력 반환
    int NowWeaponAttack();
    //장착할 수 있는 무기인지 확인하는 메서드
    bool IdentifyItem(const Item&, std::string);
    //아이템의 개수를 반환
    int ReturnItemNumber(const Item&);
    //Inventory 생성 시 무기(주먹) 추가하는 메서드
    void AddFirst();
};
