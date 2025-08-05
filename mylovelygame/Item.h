#pragma once
#include <vector>
#include <iostream>

#include "GameUtils.h"


// 아이템 타입 구분
enum class ItemType {
    Consumable,  // 소비 아이템 (예: 생명초, 정신안정제)
    Weapon,      // 무기
    Armor,       // 방어구
    Accessory    // 악세사리
};

// 아이템 기본 구조체
class Item {
public:
    int id;
    std::string name;
    ItemType type;
    int quantity;
    int price;
    std::string description;  // 설명 추가

    Item() : id(0), name(""), type(ItemType::Consumable), quantity(0), price(0), description("") {}

    Item(int id, std::string name, ItemType type, int quantity, int price, std::string desc = "")
        : id(id), name(name), type(type), quantity(quantity), price(price), description(desc) {
    }

    virtual ~Item() = default;

    // 장비용 가상 함수들 (소비 아이템은 0 반환)
    virtual int GetAtkBonus() const { return 0; }
    virtual int GetDefBonus() const { return 0; }
    virtual int GetHpBonus() const { return 0; }
};

class EquipmentItem : public Item {
public:
    int atkBonus;
    int defBonus;
    int hpBonus;

    EquipmentItem(int id_, const std::string& name_, ItemType type_, int quantity_, int price_,
        const std::string& description_,
        int atkB, int defB, int hpB)
        : Item(id_, name_, type_, quantity_, price_, description_),  // 부모 생성자에 description도 넘김
        atkBonus(atkB), defBonus(defB), hpBonus(hpB) {
    }

    int GetAtkBonus() const override { return atkBonus; }
    int GetDefBonus() const override { return defBonus; }
    int GetHpBonus() const override { return hpBonus; }
};


std::vector<std::shared_ptr<Item>> GetConsumableItems();
std::vector<std::shared_ptr<Item>> GetEquipmentItems();
//void OpShop(const Player& player);