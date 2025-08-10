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

		std::cout << "\n";

		Inventory& inv = player.GetInventory();
		inv.ShowInventory();


		TypeWriter("\n현재 골드: " + std::to_string(player.GetGold()) + " 골드\n", 10);
		TypeWriter("\n메뉴로 돌아가시려면 0\n", 10);
		TypeWriter("1. 구매하다 \n2. 판매하다 \n", 10);
		TypeWriter("> ", 10);

		int choice;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 0) {
			TypeWriter("상점에서 나갑니다.\n", 20);
			return;
		}
		if (choice == 1)
		{
			TypeWriter("\n메뉴로 돌아가시려면 0\n", 10);
			TypeWriter("구매할 아이템 번호를 입력하세요:\n", 10);
			TypeWriter("> ", 10);
			
			int buychoice;
			std::cin >> buychoice;
			std::cin.ignore();

			if (buychoice < 1 || buychoice >= displayIndex) {
				TypeWriter("잘못된 번호입니다. 다시 시도하세요.\n", 20);
				continue;
			}

			auto selectedItem = availableItems[buychoice - 1];

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
		else if (choice == 2)
		{
			Inventory& inv = player.GetInventory();
			if (inv.items.empty()) {
				TypeWriter("판매할 아이템이 없습니다.\n", 20);
				continue;
			}

			TypeWriter("\n메뉴로 돌아가시려면 0\n", 10);
			TypeWriter("판매할 아이템 번호를 입력하세요:\n", 10);
			TypeWriter("> ", 10);

			// 인벤토리에서 번호 출력할 때 1부터 시작한다고 가정
			int sellChoice;
			std::cin >> sellChoice;
			std::cin.ignore();

			if (sellChoice == 0) continue;

			if (sellChoice < 1 || sellChoice >(int)inv.items.size()) {
				TypeWriter("잘못된 번호입니다. 다시 시도하세요.\n", 20);
				continue;
			}

			auto& sellItemPtr = inv.items[sellChoice - 1];
			if (!sellItemPtr) {
				TypeWriter("빈 칸입니다. 다시 선택하세요.\n", 20);
				continue;
			}

			// 판매할 아이템 이름과 가격 미리 저장
			std::string itemName = sellItemPtr->name;
			int sellPrice = sellItemPtr->price * 80 / 100;

			bool removed = inv.RemoveItem(sellItemPtr->id, 1);
			if (!removed) {
				TypeWriter("판매할 아이템 수량이 부족합니다.\n", 20);
				continue;
			}

			player.AddGold(sellPrice);
			TypeWriter(itemName + " 아이템을 판매하여 " + std::to_string(sellPrice) + " 골드를 얻었습니다.\n", 20);
		}
		else
		{
			TypeWriter("잘못된 선택입니다. 다시 시도하세요.\n", 20);
		}
	}
}

