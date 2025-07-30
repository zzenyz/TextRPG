#pragma once
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "items.h"

void printInventory(Player* player);
int addItemToInventory(Player* player, const char* itemName);
void 상점(Player* player);

//==============인벤토리============

void initInventory(Inventory* inv);
void addItem(Inventory* inv, const char* name);
void showInventory(Player* player);

//=================아이템 사용============
void useItemMenu(Player* player);
void useItem(Player* player, Item* item);
