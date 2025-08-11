#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Item.h"
#include "GameUtils.h"

struct Inventory {
    std::vector<std::shared_ptr<Item>> items;         // �Ϲ� ������ �κ��丮
    std::vector<std::shared_ptr<Item>> equippedItems = std::vector<std::shared_ptr<Item>>(3, nullptr);


    int maxSlots = 5;

    int GetTotalQuantity() const;
    bool AddItem(std::shared_ptr<Item> newItem);
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

