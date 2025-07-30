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
	TypeWriter("=== 소비 아이템 목록 ===\n", 10);
	int displayIndex = 1;

	for (const auto& item : consumableItems) {
		std::string line1 = std::to_string(displayIndex) + ". " + item->name + " - " + std::to_string(item->price) + "골드\n";
		std::string line2 = "   " + item->description + "\n";
		TypeWriter(line1, 10);
		TypeWriter(line2, 10);

		availableItems.push_back(item);
		displayIndex++;
	}

	TypeWriter("\n=== 장비 아이템 목록 ===\n", 10);

	for (const auto& item : equipmentItems) {
		int idMod = (item->id - 10) % 3;
		if (idMod == jobIndex) {
			std::string line1 = std::to_string(displayIndex) + ". " + item->name + " - " + std::to_string(item->price) + "골드\n";
			std::string line2 = "   " + item->description + "\n";
			TypeWriter(line1, 10);
			TypeWriter(line2, 10);

			availableItems.push_back(item);
			displayIndex++;
		}
	}

	while (true)
	{

		TypeWriter("\n현재 골드: " + std::to_string(player.GetGold()) + " 골드\n\n", 10);
		TypeWriter("구매할 아이템 번호를 입력하세요 (0: 돌아가기): \n", 10);

		int choice;
		std::cin >> choice;

		if (choice == 0) {
			TypeWriter("상점에서 나갑니다.\n", 20);
			return;
		}

		if (choice < 1 || choice >= displayIndex) {
			TypeWriter("잘못된 번호입니다. 다시 시도하세요.\n", 20);
			continue;
		}

		auto selectedItem = availableItems[choice - 1];

		if (!player.SpendGold(selectedItem->price)) {
			TypeWriter("골드가 부족합니다.\n", 20);
			continue;
		}

		Item newItem = *selectedItem;
		newItem.quantity = 1;

		bool added = player.GetInventory().AddItem(newItem);

		if (added) {
			TypeWriter(selectedItem->name + " 아이템을 구매했습니다!\n", 20);
		}
		else {
			TypeWriter("인벤토리가 가득 차서 아이템을 추가할 수 없습니다. 구매가 취소됩니다.\n", 20);
			player.AddGold(selectedItem->price); // 골드 환불
			continue;
		}
	}



}

