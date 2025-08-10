#include "Shop.h"

void ShowShopItems(Player& player)
{
	auto consumableItems = GetConsumableItems();
	auto equipmentItems = GetEquipmentItems();

	int jobIndex = player.GettJob() - 1;

	std::vector<std::shared_ptr<Item>> availableItems;

	while (true)
	{

		ClearScreen();

		// �Һ� ������ ���
		std::cout << "=== �Һ� ������ ��� ===\n";
		int displayIndex = 1;
		for (const auto& item : consumableItems) {
			std::cout << displayIndex << ". " << item->name << " - " << item->price << "���\n";
			std::cout << "   " << item->description << "\n";

			availableItems.push_back(item);
			displayIndex++;
		}

		// ��� ������ ���
		std::cout << "\n=== ��� ������ ��� ===\n";
		for (const auto& item : equipmentItems) {
			int idMod = (item->id - 10) % 3;
			if (idMod == jobIndex) {
				std::cout << displayIndex << ". " << item->name << " - " << item->price << "���\n";
				std::cout << "   " << item->description << "\n";

				availableItems.push_back(item);
				displayIndex++;
			}
		}

		std::cout << "\n";

		Inventory& inv = player.GetInventory();
		inv.ShowInventory();


		TypeWriter("\n���� ���: " + std::to_string(player.GetGold()) + " ���\n", 10);
		TypeWriter("\n�޴��� ���ư��÷��� 0\n", 10);
		TypeWriter("1. �����ϴ� \n2. �Ǹ��ϴ� \n", 10);
		TypeWriter("> ", 10);

		int choice;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 0) {
			TypeWriter("�������� �����ϴ�.\n", 20);
			return;
		}
		if (choice == 1)
		{
			TypeWriter("\n�޴��� ���ư��÷��� 0\n", 10);
			TypeWriter("������ ������ ��ȣ�� �Է��ϼ���:\n", 10);
			TypeWriter("> ", 10);
			
			int buychoice;
			std::cin >> buychoice;
			std::cin.ignore();

			if (buychoice < 1 || buychoice >= displayIndex) {
				TypeWriter("�߸��� ��ȣ�Դϴ�. �ٽ� �õ��ϼ���.\n", 20);
				continue;
			}

			auto selectedItem = availableItems[buychoice - 1];

			if (!player.SpendGold(selectedItem->price)) {
				TypeWriter("��尡 �����մϴ�.\n", 20);
				continue;
			}

			auto newItem = std::make_shared<Item>(*selectedItem);
			newItem->quantity = 1;

			bool added = player.GetInventory().AddItem(newItem);

			if (added) {
				TypeWriter(selectedItem->name + " �������� �����߽��ϴ�!\n", 20);
			}
			else {
				TypeWriter("�κ��丮�� ���� ���� �������� �߰��� �� �����ϴ�. ���Ű� ��ҵ˴ϴ�.\n", 20);
				player.AddGold(selectedItem->price); // ��� ȯ��
				continue;
			}
		}
		else if (choice == 2)
		{
			Inventory& inv = player.GetInventory();
			if (inv.items.empty()) {
				TypeWriter("�Ǹ��� �������� �����ϴ�.\n", 20);
				continue;
			}

			TypeWriter("\n�޴��� ���ư��÷��� 0\n", 10);
			TypeWriter("�Ǹ��� ������ ��ȣ�� �Է��ϼ���:\n", 10);
			TypeWriter("> ", 10);

			// �κ��丮���� ��ȣ ����� �� 1���� �����Ѵٰ� ����
			int sellChoice;
			std::cin >> sellChoice;
			std::cin.ignore();

			if (sellChoice == 0) continue;

			if (sellChoice < 1 || sellChoice >(int)inv.items.size()) {
				TypeWriter("�߸��� ��ȣ�Դϴ�. �ٽ� �õ��ϼ���.\n", 20);
				continue;
			}

			auto& sellItemPtr = inv.items[sellChoice - 1];
			if (!sellItemPtr) {
				TypeWriter("�� ĭ�Դϴ�. �ٽ� �����ϼ���.\n", 20);
				continue;
			}

			// �Ǹ��� ������ �̸��� ���� �̸� ����
			std::string itemName = sellItemPtr->name;
			int sellPrice = sellItemPtr->price * 80 / 100;

			bool removed = inv.RemoveItem(sellItemPtr->id, 1);
			if (!removed) {
				TypeWriter("�Ǹ��� ������ ������ �����մϴ�.\n", 20);
				continue;
			}

			player.AddGold(sellPrice);
			TypeWriter(itemName + " �������� �Ǹ��Ͽ� " + std::to_string(sellPrice) + " ��带 ������ϴ�.\n", 20);
		}
		else
		{
			TypeWriter("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n", 20);
		}
	}
}

