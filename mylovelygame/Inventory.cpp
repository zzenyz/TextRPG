#include "Inventory.h"

int Inventory::GetTotalQuantity() const {
    int total = 0;
    for (const auto& item : items)
        total += item->quantity;
    return total;
}

// ������ �߰� (shared_ptr<Item> ���)
bool Inventory::AddItem(std::shared_ptr<Item> newItem) 
{
    int totalCurrentQuantity = GetTotalQuantity();

    for (auto& item : items) {
        if (item->id == newItem->id) {
            if (totalCurrentQuantity + newItem->quantity > maxSlots) {
                return false;
            }
            item->quantity += newItem->quantity;
            return true;
        }
    }

    if (totalCurrentQuantity + newItem->quantity > maxSlots) {
        return false;
    }

    items.push_back(newItem);
    return true;
}

// ������ ����
bool Inventory::RemoveItem(int itemId, int quantity) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->id == itemId) {
            if ((*it)->quantity < quantity) return false;
            (*it)->quantity -= quantity;
            if ((*it)->quantity == 0) items.erase(it);
            return true;
        }
    }
    return false;
}

// ���� (Ÿ�� > ID)
void Inventory::SortItems() {
    std::sort(items.begin(), items.end(), [](const std::shared_ptr<Item>& a, const std::shared_ptr<Item>& b) {
        if (a->type == b->type) return a->id < b->id;
        return static_cast<int>(a->type) < static_cast<int>(b->type);
        });
}

// ������ ����
void Inventory::EquipItem(int itemId) {
    // equippedItems ���Ͱ� 3 ũ�� �ƴ� ��� ���� resize
    if (equippedItems.size() < 3) {
        equippedItems.resize(3);
    }

    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->id == itemId) {
            ItemType type = (*it)->type;
            int slotIndex = static_cast<int>(type) - 1;

            if (slotIndex < 0 || slotIndex >= 3) {
                TypeWriter("�߸��� ��� �����Դϴ�.\n", 20);
                return;
            }

            UnequipItem(type);

            equippedItems[slotIndex] = *it;
            items.erase(it);

            TypeWriter("�������� �����Ǿ����ϴ�.\n", 20);
            return;
        }
    }

    TypeWriter("�ش� �������� ã�� �� �����ϴ�.\n", 20);
}


void Inventory::UnequipItem(ItemType type) {
    // �Ҹ�ǰ�� ������ ��� �ƴ�
    if (type == ItemType::Consumable) {
        return;
    }

    int slotIndex = static_cast<int>(type) - 1;
    if (slotIndex >= 0 && slotIndex < (int)equippedItems.size()) {
        auto& equippedPtr = equippedItems[slotIndex];
        if (equippedPtr && equippedPtr->id != -1) {
            items.push_back(equippedPtr);
            equippedItems[slotIndex] = nullptr;
        }
    }
}

// �κ��丮 ���
void Inventory::ShowInventory() const {
    std::cout << "=== [�κ��丮] ===\n";

    if (items.empty()) {
        std::cout << "�κ��丮�� ��� �ֽ��ϴ�.\n";
        return;
    }

    int index = 1;
    for (const auto& item : items) {
        std::cout << index << ". " << item->name << " x" << item->quantity << " [";

        switch (item->type) {
        case ItemType::Consumable: std::cout << "�Һ�"; break;
        case ItemType::Weapon: std::cout << "����"; break;
        case ItemType::Armor: std::cout << "��"; break;
        case ItemType::Accessory: std::cout << "�Ǽ��縮"; break;
        }

        std::cout << "]\n";
        ++index;
    }
}

// ���� ��� ���
void Inventory::ShowEquippedItems() const {
    std::cout << "\n=== [���� ���] ===\n";
    bool hasEquipped = false;

    for (const auto& itemPtr : equippedItems) {
        if (itemPtr && itemPtr->id != -1) {
            hasEquipped = true;
            std::cout << itemPtr->name << " [";

            switch (itemPtr->type) {
            case ItemType::Weapon: std::cout << "����"; break;
            case ItemType::Armor: std::cout << "��"; break;
            case ItemType::Accessory: std::cout << "�Ǽ��縮"; break;
            default: std::cout << "�� �� ����"; break;
            }

            std::cout << "]\n";
        }
    }

    if (!hasEquipped) {
        std::cout << "������ ��� �����ϴ�.\n";
    }
}