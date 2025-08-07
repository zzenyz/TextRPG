#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Item.h"
#include "GameUtils.h"

struct Inventory {
    std::vector<std::shared_ptr<Item>> items;         // 일반 아이템 인벤토리
    std::vector<std::shared_ptr<Item>> equippedItems = std::vector<std::shared_ptr<Item>>(3, nullptr);


    int maxSlots = 5;

    int GetTotalQuantity() const;
    bool AddItem(std::shared_ptr<Item> newItem);
    bool RemoveItem(int itemId, int quantity);
    void SortItems();

    void EquipItem(int itemId);         // 장비 착용
    void UnequipItem(ItemType type);    // 장비 해제
    void ShowInventory() const;
    void ShowEquippedItems() const;     // 장비 인벤토리 출력

    void IncreaseMaxSlots(int amount) 
    {
        maxSlots += amount;
    }

};

