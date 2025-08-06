#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Item.h"
#include "GameUtils.h"

struct Inventory {
    std::vector<Item> items;            // 일반 아이템 인벤토리
    std::vector<Item> equippedItems = std::vector<Item>(3, Item(-1, "", ItemType::Consumable, 0, 0));

    int maxSlots = 5;

    int GetTotalQuantity() const;
    bool AddItem(const Item& newItem);
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

