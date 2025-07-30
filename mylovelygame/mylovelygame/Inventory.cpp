#include "Inventory.h"

// 아이템 추가
bool Inventory::AddItem(const Item& newItem) {
    //std::cout << "[DEBUG] AddItem 시도: " << newItem.name << " (ID: " << newItem.id << ")\n";

    for (auto& item : items) {
        if (item.id == newItem.id) {
            item.quantity += newItem.quantity;
            //std::cout << "[DEBUG] 기존 아이템 수량 증가됨. 총 수량: " << item.quantity << "\n";
            return true;
        }
    }

    if ((int)items.size() < maxSlots) {
        items.push_back(newItem);
        //std::cout << "[DEBUG] 새 아이템 추가됨. 현재 인벤토리 크기: " << items.size() << "\n";
        return true;
    }

    //std::cout << "[DEBUG] 아이템 추가 실패: 인벤토리가 가득 찼습니다.\n";
    return false;
}
// 아이템 제거
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

// 정렬 (타입 > ID)
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
                // 기존 장비 해제
                UnequipItem(type);

                int slotIndex = static_cast<int>(type) - 1;  // Consumable이 0이니까 -1
                if (slotIndex >= 0 && slotIndex < 3) {
                    equippedItems[slotIndex] = *it;  // 복사 대입
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
        // 빈 슬롯 (기본 아이템)일 때는 아무 작업 안 함
        if (equippedItems[slotIndex].id != -1) {
            items.push_back(equippedItems[slotIndex]);
            // 빈 슬롯 상태로 초기화 (id를 -1로)
            equippedItems[slotIndex] = Item(-1, "", ItemType::Consumable, 0, 0);
        }
    }
}

// 인벤토리 출력
void Inventory::ShowInventory() const {
    TypeWriter("=== [인벤토리] ===\n", 10);
    if (items.empty()) {
        TypeWriter("인벤토리가 비어 있습니다.\n", 30);
        return;
    }

    int index = 1;

    for (const auto& item : items) {
        TypeWriter(std::to_string(index) + ". " + item.name + " x" + std::to_string(item.quantity) + " [", 20);

        switch (item.type) {
        case ItemType::Consumable:
            TypeWriter("소비", 10);
            break;
        case ItemType::Weapon:
            TypeWriter("무기", 10);
            break;
        case ItemType::Armor:
            TypeWriter("방어구", 10);
            break;
        case ItemType::Accessory:
            TypeWriter("악세사리", 10);
            break;
        }

        TypeWriter("]\n", 20);
        ++index;
    }
}

void Inventory::ShowEquippedItems() const {
    TypeWriter("\n=== [장착 장비] ===\n", 10);
    bool hasEquipped = false;

    for (const auto& item : equippedItems) {
        // 장비 슬롯이 비어있지 않은 경우만 출력
        if (item.id != -1) {
            hasEquipped = true;
            TypeWriter(item.name + " [", 10);
            switch (item.type) {
            case ItemType::Weapon: TypeWriter("무기"); break;
            case ItemType::Armor: TypeWriter("방어구"); break;
            case ItemType::Accessory: TypeWriter("악세사리"); break;
            default: break;
            }
            TypeWriter("]\n", 10);
        }
    }

    if (!hasEquipped) {
        TypeWriter("장착한 장비가 없습니다.\n", 10);
    }
}

