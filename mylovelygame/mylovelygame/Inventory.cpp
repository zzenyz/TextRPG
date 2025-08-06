#include "Inventory.h"

int Inventory::GetTotalQuantity() const {
    int total = 0;
    for (const auto& item : items)
        total += item.quantity;
    return total;
}

// ������ �߰�
bool Inventory::AddItem(const Item& newItem) {
    int totalCurrentQuantity = GetTotalQuantity();

    // �̹� �ִ� �����ۿ� ������ �߰�
    for (auto& item : items) {
        if (item.id == newItem.id) {
            if (totalCurrentQuantity + newItem.quantity > maxSlots) {
                return false; // �ʰ��ϸ� �߰� �Ұ�
            }
            item.quantity += newItem.quantity;
            return true;
        }
    }

    // ���ο� �������̸� ���� ���� + ���� üũ
    if (totalCurrentQuantity + newItem.quantity > maxSlots) {
        return false; // �ʰ� �� ����
    }

    items.push_back(newItem);
    return true;
}
// ������ ����
bool Inventory::RemoveItem(int itemId, int quantity) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it).id == itemId) {
            if ((*it).quantity < quantity) return false;
            (*it).quantity -= quantity;
            if ((*it).quantity == 0) items.erase(it);
            return true;
        }
    }
    return false;
}

// ���� (Ÿ�� > ID)
void Inventory::SortItems() {
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        if (a.type == b.type) return a.id < b.id;
        return static_cast<int>(a.type) < static_cast<int>(b.type);
        });
}

void Inventory::EquipItem(int itemId) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->id == itemId) {
            ItemType type = it->type;
            if (type == ItemType::Weapon || type == ItemType::Armor || type == ItemType::Accessory) {
                // ���� ��� ����
                UnequipItem(type);

                int slotIndex = static_cast<int>(type) - 1;  // Consumable�� 0�̴ϱ� -1
                if (slotIndex >= 0 && slotIndex < 3) {
                    equippedItems[slotIndex] = *it;  // ���� ����
                }

                items.erase(it);
                return;
            }
        }
    }
}

void Inventory::UnequipItem(ItemType type) {
    int slotIndex = static_cast<int>(type) - 1;
    if (slotIndex >= 0 && slotIndex < 3) {
        // �� ���� (�⺻ ������)�� ���� �ƹ� �۾� �� ��
        if (equippedItems[slotIndex].id != -1) {
            items.push_back(equippedItems[slotIndex]);
            // �� ���� ���·� �ʱ�ȭ (id�� -1��)
            equippedItems[slotIndex] = Item(-1, "", ItemType::Consumable, 0, 0);
        }
    }
}

// �κ��丮 ���
void Inventory::ShowInventory() const {
    TypeWriter("=== [�κ��丮] ===\n", 10);
    if (items.empty()) {
        TypeWriter("�κ��丮�� ��� �ֽ��ϴ�.\n", 30);
        return;
    }

    int index = 1;

    for (const auto& item : items) {
        TypeWriter(std::to_string(index) + ". " + item.name + " x" + std::to_string(item.quantity) + " [", 20);

        switch (item.type) {
        case ItemType::Consumable:
            TypeWriter("�Һ�", 10);
            break;
        case ItemType::Weapon:
            TypeWriter("����", 10);
            break;
        case ItemType::Armor:
            TypeWriter("��", 10);
            break;
        case ItemType::Accessory:
            TypeWriter("�Ǽ��縮", 10);
            break;
        }

        TypeWriter("]\n", 20);
        ++index;
    }
}

void Inventory::ShowEquippedItems() const {
    TypeWriter("\n=== [���� ���] ===\n", 10);
    bool hasEquipped = false;

    for (const auto& item : equippedItems) {
        // ��� ������ ������� ���� ��츸 ���
        if (item.id != -1) {
            hasEquipped = true;
            TypeWriter(item.name + " [", 10);
            switch (item.type) {
            case ItemType::Weapon: TypeWriter("����"); break;
            case ItemType::Armor: TypeWriter("��"); break;
            case ItemType::Accessory: TypeWriter("�Ǽ��縮"); break;
            default: break;
            }
            TypeWriter("]\n", 10);
        }
    }

    if (!hasEquipped) {
        TypeWriter("������ ��� �����ϴ�.\n", 10);
    }
}

