#include "Item.h"

// 소비형 아이템 목록
std::vector<std::shared_ptr<Item>> consumableItems = {
    std::make_shared<Item>(Item{0, "생명초", ItemType::Consumable, 1, 10, "체력을 즉시 10% 회복합니다."}),
    std::make_shared<Item>(Item{1, "신묘한 힘", ItemType::Consumable, 1, 20, "3턴 동안 공격력이 10% 올라갑니다."}),
    std::make_shared<Item>(Item{2, "정신안정제", ItemType::Consumable, 1, 15, "이상 상태를 회복합니다."})
};

// 장비 아이템 목록
std::vector<std::shared_ptr<Item>> equipmentItems = {
    std::make_shared<EquipmentItem>(EquipmentItem{10, "신방울", ItemType::Weapon, 1, 100, "전용 무기입니다.", 5, 0, 0}),
    std::make_shared<EquipmentItem>(EquipmentItem{11, "나침반", ItemType::Weapon, 1, 100, "전용 무기입니다.", 5, 0, 0}),
    std::make_shared<EquipmentItem>(EquipmentItem{12, "성경책", ItemType::Weapon, 1, 100, "전용 무기입니다.", 5, 0, 0}),

    std::make_shared<EquipmentItem>(EquipmentItem{13, "구슬 목걸이", ItemType::Armor, 1, 120, "전용 방어구입니다.", 0, 3, 20}),
    std::make_shared<EquipmentItem>(EquipmentItem{14, "정기 두루마기", ItemType::Armor, 1, 120, "전용 방어구입니다.", 0, 3, 20}),
    std::make_shared<EquipmentItem>(EquipmentItem{15, "성수병", ItemType::Armor, 1, 120, "전용 방어구입니다.", 0, 3, 20}),

    std::make_shared<EquipmentItem>(EquipmentItem{16, "영적 비녀", ItemType::Accessory, 1, 150, "전용 악세사리입니다.", 0, 5, 30}),
    std::make_shared<EquipmentItem>(EquipmentItem{17, "풍령의 도포", ItemType::Accessory, 1, 150, "전용 악세사리입니다.", 0, 5, 30}),
    std::make_shared<EquipmentItem>(EquipmentItem{18, "성결의 망토", ItemType::Accessory, 1, 150, "전용 악세사리입니다.", 0, 5, 30})
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
//    TypeWriter("\n=== [상점] ===\n", 40);
//
//    TypeWriter("\n[소비 아이템]\n", 30);
//    for (const auto& item : consumableItems) {
//        std::string line = "- " + item->name + " | " + item->description + " | " + std::to_string(item->price) + "골드\n";
//        TypeWriter(line, 10);
//    }
//
//    TypeWriter("\n[장비 아이템]\n", 40);
//    std::string job = player.GetJobName();
//
//    for (const auto& item : equipmentItems) {
//        auto eqItem = std::dynamic_pointer_cast<EquipmentItem>(item);
//        if (!eqItem) continue;
//
//        int id = eqItem->id;
//        bool match = false;
//
//        if (job == "무당") {
//            for (int i = 0; i < 3; ++i) {
//                if (id == 10 + i * 3) {
//                    match = true;
//                    break;
//                }
//            }
//        }
//        else if (job == "풍수지리사") {
//            for (int i = 0; i < 3; ++i) {
//                if (id == 11 + i * 3) {
//                    match = true;
//                    break;
//                }
//            }
//        }
//        else if (job == "신학생") {
//            for (int i = 0; i < 3; ++i) {
//                if (id == 12 + i * 3) {
//                    match = true;
//                    break;
//                }
//            }
//        }
//
//        if (match) {
//            std::string line = "- " + eqItem->name + " | " + eqItem->description + " | " + std::to_string(eqItem->price) + "골드\n";
//            TypeWriter(line, 30);
//        }
//    }
//}
