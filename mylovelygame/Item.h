#pragma once
#include <vector>
#include <iostream>
#include <memory> // shared_ptr

#include "GameUtils.h"

// 아이템 타입 구분
enum class ItemType {
    Consumable,
    Weapon,
    Armor,
    Accessory
};

class Item {
public:
    int id;
    std::string name;
    ItemType type;
    int quantity;
    int price;
    std::string description;
    int atkBonus;
    int defBonus;
    int hpBonus;

    Item() : id(0), name(""), type(ItemType::Consumable), quantity(0), price(0),
        description(""), atkBonus(0), defBonus(0), hpBonus(0) {
    }

    Item(int id, std::string name, ItemType type, int quantity, int price,
        std::string desc = "", int atk = 0, int def = 0, int hp = 0)
        : id(id), name(name), type(type), quantity(quantity), price(price),
        description(desc), atkBonus(atk), defBonus(def), hpBonus(hp) {
    }

    int GetAtkBonus() const { return atkBonus; }
    int GetDefBonus() const { return defBonus; }
    int GetHpBonus() const { return hpBonus; }
};

std::vector<std::shared_ptr<Item>> GetConsumableItems();
std::vector<std::shared_ptr<Item>> GetEquipmentItems();
