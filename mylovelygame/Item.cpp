#include "Item.h"

// �Һ��� ������ ���
static std::vector<std::shared_ptr<Item>> consumableItems = {
    std::make_shared<Item>(0, "������", ItemType::Consumable, 1, 40, "ü���� ��� 10% ȸ���մϴ�."),
    std::make_shared<Item>(1, "�Ź��� ��", ItemType::Consumable, 1, 45, "3�� ���� ���ݷ��� 10% �ö󰩴ϴ�."),
    std::make_shared<Item>(2, "���ž�����", ItemType::Consumable, 1, 35, "�̻� ���¸� ȸ���մϴ�."),
    std::make_shared<Item>(3, "ȥ�ɼ�", ItemType::Consumable, 1, 60, "��� ��ȭ�� �� �ִ� �����Դϴ�.")
};

// ��� ������ ���
static std::vector<std::shared_ptr<Item>> equipmentItems = {
    std::make_shared<Item>(10, "�Ź��", ItemType::Weapon, 1, 300, "���� �����Դϴ�.", 10, 0, 0),
    std::make_shared<Item>(11, "��ħ��", ItemType::Weapon, 1, 300, "���� �����Դϴ�.", 10, 0, 0),
    std::make_shared<Item>(12, "����å", ItemType::Weapon, 1, 300, "���� �����Դϴ�.", 10, 0, 0),

    std::make_shared<Item>(13, "���� �����", ItemType::Armor, 1, 100, "���� ���Դϴ�.", 0, 10, 0),
    std::make_shared<Item>(14, "���� �η縶��", ItemType::Armor, 1, 100, "���� ���Դϴ�.", 0, 10, 0),
    std::make_shared<Item>(15, "������", ItemType::Armor, 1, 100, "���� ���Դϴ�.", 0, 10, 0),

    std::make_shared<Item>(16, "���� ���", ItemType::Accessory, 1, 200, "���� �Ǽ��縮�Դϴ�.", 0, 0, 15),
    std::make_shared<Item>(17, "ǳ���� ����", ItemType::Accessory, 1, 200, "���� �Ǽ��縮�Դϴ�.", 0, 0, 15),
    std::make_shared<Item>(18, "������ ����", ItemType::Accessory, 1, 200, "���� �Ǽ��縮�Դϴ�.", 0, 0, 15)
};

std::vector<std::shared_ptr<Item>> GetConsumableItems()
{
    return consumableItems;
}

std::vector<std::shared_ptr<Item>> GetEquipmentItems()
{
    return equipmentItems;
}