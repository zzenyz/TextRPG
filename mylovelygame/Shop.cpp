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


		TypeWriter("\n���� ���: " + std::to_string(player.GetGold()) + " ���\n\n", 10);
		TypeWriter("\n�޴��� ���ư��÷��� 0\n", 10);
		TypeWriter("������ ������ ��ȣ�� �Է��ϼ���: \n", 10);
		TypeWriter("> ", 10);

		int choice;
		std::cin >> choice;

		if (choice == 0) {
			TypeWriter("�������� �����ϴ�.\n", 20);
			return;
		}

		if (choice < 1 || choice >= displayIndex) {
			TypeWriter("�߸��� ��ȣ�Դϴ�. �ٽ� �õ��ϼ���.\n", 20);
			continue;
		}

		auto selectedItem = availableItems[choice - 1];

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
}

