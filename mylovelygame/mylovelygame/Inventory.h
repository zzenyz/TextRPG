#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Item.h"
#include "GameUtils.h"

struct Inventory {
    std::vector<Item> items;            // �Ϲ� ������ �κ��丮
    std::vector<Item> equippedItems = std::vector<Item>(3, Item(-1, "", ItemType::Consumable, 0, 0));

    int maxSlots = 5;

    int GetTotalQuantity() const;
    bool AddItem(const Item& newItem);
    bool RemoveItem(int itemId, int quantity);
    void SortItems();

    void EquipItem(int itemId);         // ��� ����
    void UnequipItem(ItemType type);    // ��� ����
    void ShowInventory() const;
    void ShowEquippedItems() const;     // ��� �κ��丮 ���

    void IncreaseMaxSlots(int amount) 
    {
        maxSlots += amount;
    }

};

