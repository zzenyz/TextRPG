#include "Item.h"

// �Һ��� ������ ���
std::vector<std::shared_ptr<Item>> consumableItems = {
    std::make_shared<Item>(Item{0, "������", ItemType::Consumable, 1, 10, "ü���� ��� 10% ȸ���մϴ�."}),
    std::make_shared<Item>(Item{1, "�Ź��� ��", ItemType::Consumable, 1, 20, "3�� ���� ���ݷ��� 10% �ö󰩴ϴ�."}),
    std::make_shared<Item>(Item{2, "���ž�����", ItemType::Consumable, 1, 15, "�̻� ���¸� ȸ���մϴ�."})
};

// ��� ������ ���
std::vector<std::shared_ptr<Item>> equipmentItems = {
    std::make_shared<EquipmentItem>(EquipmentItem{10, "�Ź��", ItemType::Weapon, 1, 100, "���� �����Դϴ�.", 5, 0, 0}),
    std::make_shared<EquipmentItem>(EquipmentItem{11, "��ħ��", ItemType::Weapon, 1, 100, "���� �����Դϴ�.", 5, 0, 0}),
    std::make_shared<EquipmentItem>(EquipmentItem{12, "����å", ItemType::Weapon, 1, 100, "���� �����Դϴ�.", 5, 0, 0}),

    std::make_shared<EquipmentItem>(EquipmentItem{13, "���� �����", ItemType::Armor, 1, 120, "���� ���Դϴ�.", 0, 3, 20}),
    std::make_shared<EquipmentItem>(EquipmentItem{14, "���� �η縶��", ItemType::Armor, 1, 120, "���� ���Դϴ�.", 0, 3, 20}),
    std::make_shared<EquipmentItem>(EquipmentItem{15, "������", ItemType::Armor, 1, 120, "���� ���Դϴ�.", 0, 3, 20}),

    std::make_shared<EquipmentItem>(EquipmentItem{16, "���� ���", ItemType::Accessory, 1, 150, "���� �Ǽ��縮�Դϴ�.", 0, 5, 30}),
    std::make_shared<EquipmentItem>(EquipmentItem{17, "ǳ���� ����", ItemType::Accessory, 1, 150, "���� �Ǽ��縮�Դϴ�.", 0, 5, 30}),
    std::make_shared<EquipmentItem>(EquipmentItem{18, "������ ����", ItemType::Accessory, 1, 150, "���� �Ǽ��縮�Դϴ�.", 0, 5, 30})
};

std::vector<std::shared_ptr<Item>> GetConsumableItems() 
{
    return consumableItems;
}

std::vector<std::shared_ptr<Item>> GetEquipmentItems() 
{
    return equipmentItems;
}

//void OpShop(const Player& player) {
//    TypeWriter("\n=== [����] ===\n", 40);
//
//    TypeWriter("\n[�Һ� ������]\n", 30);
//    for (const auto& item : consumableItems) {
//        std::string line = "- " + item->name + " | " + item->description + " | " + std::to_string(item->price) + "���\n";
//        TypeWriter(line, 10);
//    }
//
//    TypeWriter("\n[��� ������]\n", 40);
//    std::string job = player.GetJobName();
//
//    for (const auto& item : equipmentItems) {
//        auto eqItem = std::dynamic_pointer_cast<EquipmentItem>(item);
//        if (!eqItem) continue;
//
//        int id = eqItem->id;
//        bool match = false;
//
//        if (job == "����") {
//            for (int i = 0; i < 3; ++i) {
//                if (id == 10 + i * 3) {
//                    match = true;
//                    break;
//                }
//            }
//        }
//        else if (job == "ǳ��������") {
//            for (int i = 0; i < 3; ++i) {
//                if (id == 11 + i * 3) {
//                    match = true;
//                    break;
//                }
//            }
//        }
//        else if (job == "���л�") {
//            for (int i = 0; i < 3; ++i) {
//                if (id == 12 + i * 3) {
//                    match = true;
//                    break;
//                }
//            }
//        }
//
//        if (match) {
//            std::string line = "- " + eqItem->name + " | " + eqItem->description + " | " + std::to_string(eqItem->price) + "���\n";
//            TypeWriter(line, 30);
//        }
//    }
//}
