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

		// 소비 아이템 목록
		std::cout << "=== 소비 아이템 목록 ===\n";
		int displayIndex = 1;
		for (const auto& item : consumableItems) {
			std::cout << displayIndex << ". " << item->name << " - " << item->price << "골드\n";
			std::cout << "   " << item->description << "\n";

			availableItems.push_back(item);
			displayIndex++;
		}

		// 장비 아이템 목록
		std::cout << "\n=== 장비 아이템 목록 ===\n";
		for (const auto& item : equipmentItems) {
			int idMod = (item->id - 10) % 3;
			if (idMod == jobIndex) {
				std::cout << displayIndex << ". " << item->name << " - " << item->price << "골드\n";
				std::cout << "   " << item->description << "\n";

				availableItems.push_back(item);
				displayIndex++;
			}
		}


		TypeWriter("\n현재 골드: " + std::to_string(player.GetGold()) + " 골드\n\n", 10);
		TypeWriter("\n메뉴로 돌아가시려면 0\n", 10);
		TypeWriter("구매할 아이템 번호를 입력하세요: \n", 10);
		TypeWriter("> ", 10);

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

		auto newItem = std::make_shared<Item>(*selectedItem);
		newItem->quantity = 1;

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

