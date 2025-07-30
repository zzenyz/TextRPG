#include "items.h"

Shop gameShop = {
	.items = {
		{"생명초", 12, 6, "+20 HP"},
		{"정신안정제", 10, 5, "상태이상 회복"},
		{"신묘한 힘", 15, 7, "3턴 동안 공격력 강화"}
	},
	.numItems = 3
};

void 상점(Player* player) {
	int 선택;

	while (1) {
		printf("\n===== 🛒 상점 =====\n");
		for (int i = 0; i < gameShop.numItems; i++) {
			printf("%d. %s (%s) - %d골드\n", i + 1,
				gameShop.items[i].name,
				gameShop.items[i].desc,
				gameShop.items[i].price);
		}

		int tempjob = player->job;

		printf("%d. %s (%s) - %d골드\n", gameShop.numItems + 1,
			equipmentList[tempjob + 2].name,
			equipmentList[tempjob + 2].desc,
			equipmentList[tempjob + 2].price);

		printf("%d. 아이템 판매하기\n", gameShop.numItems + 2);

		printf("%d. 돌아가기\n", gameShop.numItems + 3);
		Sleep(500);

		printInventory(player);
		printf("\n소지 골드: %d\n", player->gold);
		Sleep(500);
		printf("선택: ");
		scanf_s("\n%d", &선택);

		if (선택 >= 1 && 선택 <= gameShop.numItems) {
			int index = 선택 - 1;
			if (player->gold >= gameShop.items[index].price) {
				if (addItemToInventory(player, gameShop.items[index].name)) {
					player->gold -= gameShop.items[index].price;
					printf("\n%s를 구입했습니다.\n", gameShop.items[index].name);
				}
			}
			else {
				printf("\n골드가 부족합니다!\n");
			}
		}
		else if (선택 == gameShop.numItems + 1) 
		{
			// 장비 구매 처리 (기존대로)
			if (player->gold >= equipmentList[player->job + 2].price) {
				player->equippedItems.accessory = &equipmentList[player->job + 2];
				player->gold -= equipmentList[player->job + 2].price;
				printf("\n%s를 장착했습니다!\n", equipmentList[player->job + 2].name);
			}
			else {
				printf("\n골드가 부족합니다!\n");
			}
		}
		else if (선택 == gameShop.numItems + 2) {
			if (player->inventory.count == 0) {
				printf("\n판매할 아이템이 없습니다!\n");
				Sleep(500);
				continue;
			}

			printf("\n===== 🧾 판매할 아이템 선택 =====\n");
			for (int i = 0; i < player->inventory.count; i++) {
				printf("%d. %s x%d\n", i + 1, player->inventory.items[i].name, player->inventory.items[i].quantity);
			}
			printf("0. 취소\n");
			printf("선택: ");
			int sellChoice;
			scanf_s("%d", &sellChoice);

			if (sellChoice == 0) {
				printf("판매를 취소했습니다.\n");
				continue;
			}
			else if (sellChoice >= 1 && sellChoice <= player->inventory.count) {
				int index = sellChoice - 1;
				const char* itemName = player->inventory.items[index].name;
				int sellPrice = 0;
				int found = 0;

				// shop items에서 가격 찾기
				for (int i = 0; i < gameShop.numItems; i++) {
					if (strcmp(itemName, gameShop.items[i].name) == 0) {
						sellPrice = gameShop.items[i].sellprice;
						found = 1;
						break;
					}
				}

				// equipmentList에서 가격 찾기 (못 찾으면)
				if (!found) {
					for (int i = 0; i < equipmentListCount; i++) {
						if (strcmp(itemName, equipmentList[i].name) == 0) {
							sellPrice = equipmentList[i].sellprice;
							found = 1;
							break;
						}
					}
				}

				// 못 찾으면 기본값
				if (!found) sellPrice = 10;

				// 골드 지급 및 인벤토리 수량 감소
				player->gold += sellPrice;
				player->inventory.items[index].quantity--;

				printf("\n%s를 %d골드에 판매했습니다!\n", itemName, sellPrice);

				// 수량 0이면 아이템 제거
				if (player->inventory.items[index].quantity == 0) {
					for (int j = index; j < player->inventory.count - 1; j++) {
						player->inventory.items[j] = player->inventory.items[j + 1];
					}
					player->inventory.count--;
				}
			}
			else {
				printf("잘못된 선택입니다.\n");
			}
		}
			
			Sleep(500);
			break;
		}
		else if (선택 == gameShop.numItems + 3) {
			printf("상점을 나갑니다.\n");
			Sleep(500);
			clearScreen();
			break;
		}
		else {
			printf("잘못된 입력입니다.\n");
		}

		Sleep(500);
	}
}

//===================인벤토리===================

void initInventory(Inventory* inv) {
	inv->count = 0;
	inv->maxSlots = MAX_INVENTORY;  // 수정: MAX_ITEM → MAX_INVENTORY
}

void printInventory(Player* player) {
	printf("\n[인벤토리] (%d / %d)\n", player->inventory.count, player->inventory.maxSlots);
	if (player->inventory.count == 0) {
		printf(" - 없음\n");
	}
	else {
		for (int i = 0; i < player->inventory.count; i++) {
			printf(" - %s x%d\n", player->inventory.items[i].name, player->inventory.items[i].quantity);
		}
	}
}

int addItemToInventory(Player* player, const char* itemName) {
	Inventory* inv = &player->inventory;

	if (inv->count >= inv->maxSlots) {
		printf("인벤토리가 가득 찼습니다!\n");
		return 0;
	}

	// 중복 검사 없이 그냥 새 슬롯에 아이템 추가
	strcpy_s(inv->items[inv->count].name, sizeof(inv->items[inv->count].name), itemName);
	inv->items[inv->count].quantity = 1;
	inv->count++;  // 슬롯 개수 증가
	return 1;
}

void showInventory(Player* player) {
	Inventory* inv = &player->inventory;
	int choice;

	while (1) {
		system("cls");  // 화면 정리
		printf("\n===== [인벤토리] =====\n");
		if (inv->count == 0) {
			printf("인벤토리가 비어있습니다.\n");
		}
		else {
			for (int i = 0; i < inv->count; i++) {
				printf("[%d] %s x%d\n", i + 1, inv->items[i].name, inv->items[i].quantity);
			}
		}

		printf("\n===== [착용 장비] =====\n");
		printf("1. 무기: %s\n", player->equippedItems.weapon ? player->equippedItems.weapon->name : "없음");
		printf("2. 방어구: %s\n", player->equippedItems.armor ? player->equippedItems.armor->name : "없음");
		printf("3. 액세서리: %s\n", player->equippedItems.accessory ? player->equippedItems.accessory->name : "없음");

		printf("\n[메뉴]\n");
		printf("1. 무기 해제\n");
		printf("2. 방어구 해제\n");
		printf("3. 액세서리 해제\n");
		printf("4. 돌아가기\n");
		printf("선택: ");
		scanf("%d", &choice);

		if (choice >= 1 && choice <= 3 && inv->count == inv->maxSlots) {
			printf("인벤토리에 빈 공간이 없어 장비를 해제할 수 없습니다!\n");
			Sleep(1000);
			clearScreen();
			continue;
		}

		switch (choice) {
		case 1: // 무기 해제
			if (player->equippedItems.weapon != NULL) {
				addItemToInventory(player, player->equippedItems.weapon->name);  // 인벤토리로 이동
				player->equippedItems.weapon = NULL;
				printf("무기를 해제했습니다.\n");
			}
			else printf("해제할 무기가 없습니다.\n");
			break;
		case 2: // 방어구 해제
			if (player->equippedItems.armor != NULL) {
				addItemToInventory(player, player->equippedItems.armor->name);
				player->equippedItems.armor = NULL;
				printf("방어구를 해제했습니다.\n");
			}
			else printf("해제할 방어구가 없습니다.\n");
			break;
		case 3: // 액세서리 해제
			if (player->equippedItems.accessory != NULL) {
				addItemToInventory(player, player->equippedItems.accessory->name);
				player->equippedItems.accessory = NULL;
				printf("액세서리를 해제했습니다.\n");
			}
			else printf("해제할 액세서리가 없습니다.\n");
			break;
		case 0:
			return; // 돌아가기
		default:
			printf("잘못된 선택입니다.\n");
		}
		Sleep(1000);
	}
}


//===============아이템 드랍===============

void tryDropItem(Player* player) {
	int dropChance = rand() % 100;
	if (dropChance < 50) {
		int itemIndex = rand() % gameShop.numItems;

		const char* dropItem = gameShop.items[itemIndex].name;

		if (addItemToInventory(player, dropItem)) {
			printf("🎁 아이템 드랍: %s\n", dropItem);
		}
		else {
			printf("인벤토리가 가득 차서 아이템을 획득하지 못했습니다.\n");
		}
	}
}


//=============아이템 사용===========

void useItemMenu(Player* player) {
	showInventory(player);

	if (player->inventory.count == 0) {
		printf("사용할 아이템이 없습니다.\n");
		return;
	}

	int choice;
	printf("사용할 아이템 번호를 입력하세요 (0: 취소): ");
	scanf_s("%d", &choice);

	if (choice == 0) {
		printf("아이템 사용을 취소합니다.\n");
		return;
	}

	if (choice < 1 || choice > player->inventory.count) {
		printf("잘못된 번호입니다.\n");
		return;
	}

	Item* selectedItem = &player->inventory.items[choice - 1];

	// 아이템 효과 적용 함수 호출
	useItem(player, selectedItem);
}

// 아이템 효과 적용 함수 
void useItem(Player* player, Item* item) {
	if (strcmp(item->name, "생명초") == 0) {
		player->hp += 20;
		if (player->hp > player->maxHp) player->hp = player->maxHp;
		printf("생명초를 사용하여 HP가 20 회복되었습니다! 현재 HP: %d\n", player->hp);
	}
	else if (strcmp(item->name, "정신안정제") == 0) {
		// 상태 이상 해제 예시
		player->playerStunTurn = 0;
		player->ghostAttackDebuffTurn = 0;
		printf("정신안정제를 사용하여 상태 이상이 해제되었습니다!\n");
	}
	else if (strcmp(item->name, "신묘한 힘") == 0) {
		// 공격력 강화 버프 적용 (3턴간)
		player->buffAttackTurn = 3;
		printf("신묘한 힘 사용! 3턴간 공격력이 강화됩니다!\n");
	}
	else {
		printf("이 아이템은 사용할 수 없습니다.\n");
		return;
	}

	// 아이템 수량 감소 및 인벤토리 정리
	item->quantity--;
	if (item->quantity <= 0) {
		Inventory* inv = &player->inventory;
		int index = -1;
		for (int i = 0; i < inv->count; i++) {
			if (&inv->items[i] == item) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			for (int i = index; i < inv->count - 1; i++) {
				inv->items[i] = inv->items[i + 1];
			}
			inv->count--;
		}
	}
}
