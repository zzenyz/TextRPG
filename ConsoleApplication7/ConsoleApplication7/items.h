#pragma once
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "items.h"

void printInventory(Player* player);
int addItemToInventory(Player* player, const char* itemName);
void ����(Player* player);

//==============�κ��丮============

void initInventory(Inventory* inv);
void addItem(Inventory* inv, const char* name);
void showInventory(Player* player);

//=================������ ���============
void useItemMenu(Player* player);
void useItem(Player* player, Item* item);
