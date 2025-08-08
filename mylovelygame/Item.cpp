#include "Item.h"

// 소비형 아이템 목록
static std::vector<std::shared_ptr<Item>> consumableItems = {
    std::make_shared<Item>(0, "생명초", ItemType::Consumable, 1, 40, "체력을 즉시 10% 회복합니다."),
    std::make_shared<Item>(1, "신묘한 힘", ItemType::Consumable, 1, 45, "3턴 동안 공격력이 10% 올라갑니다."),
    std::make_shared<Item>(2, "정신안정제", ItemType::Consumable, 1, 35, "이상 상태를 회복합니다."),
    std::make_shared<Item>(3, "혼령서", ItemType::Consumable, 1, 60, "장비를 강화할 수 있는 물건입니다.")
};

// 장비 아이템 목록
static std::vector<std::shared_ptr<Item>> equipmentItems = {
    std::make_shared<Item>(10, "신방울", ItemType::Weapon, 1, 300, "전용 무기입니다.", 10, 0, 0),
    std::make_shared<Item>(11, "나침반", ItemType::Weapon, 1, 300, "전용 무기입니다.", 10, 0, 0),
    std::make_shared<Item>(12, "성경책", ItemType::Weapon, 1, 300, "전용 무기입니다.", 10, 0, 0),

    std::make_shared<Item>(13, "구슬 목걸이", ItemType::Armor, 1, 100, "전용 방어구입니다.", 0, 10, 0),
    std::make_shared<Item>(14, "정기 두루마기", ItemType::Armor, 1, 100, "전용 방어구입니다.", 0, 10, 0),
    std::make_shared<Item>(15, "성수병", ItemType::Armor, 1, 100, "전용 방어구입니다.", 0, 10, 0),

    std::make_shared<Item>(16, "영적 비녀", ItemType::Accessory, 1, 200, "전용 악세사리입니다.", 0, 0, 15),
    std::make_shared<Item>(17, "풍령의 도포", ItemType::Accessory, 1, 200, "전용 악세사리입니다.", 0, 0, 15),
    std::make_shared<Item>(18, "성결의 망토", ItemType::Accessory, 1, 200, "전용 악세사리입니다.", 0, 0, 15)
};

std::vector<std::shared_ptr<Item>> GetConsumableItems()
{
    return consumableItems;
}

std::vector<std::shared_ptr<Item>> GetEquipmentItems()
{
    return equipmentItems;
}