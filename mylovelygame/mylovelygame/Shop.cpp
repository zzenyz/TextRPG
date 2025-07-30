#include "Shop.h"

void ShowShopItems(Player& player)
{
	auto consumableItems = GetConsumableItems();
	auto equipmentItems = GetEquipmentItems();

	std::string jobName = player.GetJobName();

	int jobIndex = 0;
	if (jobName == "Shaman") jobIndex = 0;
	else if (jobName == "Geomancer") jobIndex = 1;
	else if (jobName == "Exorcist") jobIndex = 2;

	std::vector<std::shared_ptr<Item>> availableItems;


	ClearScreen();
	TypeWriter("=== �Һ� ������ ��� ===\n", 10);
	int displayIndex = 1;

	for (const auto& item : consumableItems) {
		std::string line1 = std::to_string(displayIndex) + ". " + item->name + " - " + std::to_string(item->price) + "���\n";
		std::string line2 = "   " + item->description + "\n";
		TypeWriter(line1, 10);
		TypeWriter(line2, 10);

		availableItems.push_back(item);
		displayIndex++;
	}

	TypeWriter("\n=== ��� ������ ��� ===\n", 10);

	for (const auto& item : equipmentItems) {
		int idMod = (item->id - 10) % 3;
		if (idMod == jobIndex) {
			std::string line1 = std::to_string(displayIndex) + ". " + item->name + " - " + std::to_string(item->price) + "���\n";
			std::string line2 = "   " + item->description + "\n";
			TypeWriter(line1, 10);
			TypeWriter(line2, 10);

			availableItems.push_back(item);
			displayIndex++;
		}
	}

	while (true)
	{

		TypeWriter("\n���� ���: " + std::to_string(player.GetGold()) + " ���\n\n", 10);
		TypeWriter("������ ������ ��ȣ�� �Է��ϼ��� (0: ���ư���): \n", 10);

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

		Item newItem = *selectedItem;
		newItem.quantity = 1;

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

