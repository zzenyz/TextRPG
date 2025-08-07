#include "Player.h"


bool Player::Save(std::ofstream& ofs) const {
	if (!ofs) return false;

	ofs.write(name.c_str(), name.size() + 1);
	ofs.write(jobName.c_str(), jobName.size() + 1);

	ofs.write(reinterpret_cast<const char*>(&Job), sizeof(Job));
	ofs.write(reinterpret_cast<const char*>(&hp), sizeof(hp));
	ofs.write(reinterpret_cast<const char*>(&maxHp), sizeof(maxHp));
	ofs.write(reinterpret_cast<const char*>(&atk), sizeof(atk));
	ofs.write(reinterpret_cast<const char*>(&def), sizeof(def));
	ofs.write(reinterpret_cast<const char*>(&level), sizeof(level));
	ofs.write(reinterpret_cast<const char*>(&EXP), sizeof(EXP));
	ofs.write(reinterpret_cast<const char*>(&MaxEXP), sizeof(MaxEXP));
	ofs.write(reinterpret_cast<const char*>(&karma), sizeof(karma));
	ofs.write(reinterpret_cast<const char*>(&unlockedChapter), sizeof(unlockedChapter));
	ofs.write(reinterpret_cast<const char*>(&gold), sizeof(gold));

	// clues ����
	size_t clueCount = clues.size();
	ofs.write(reinterpret_cast<const char*>(&clueCount), sizeof(clueCount));
	for (const std::string& clue : clues) {
		ofs.write(clue.c_str(), clue.size() + 1);
	}

	// keepsakes ����
	size_t keepsakeCount = keepsakes.size();
	ofs.write(reinterpret_cast<const char*>(&keepsakeCount), sizeof(keepsakeCount));
	for (const std::string& item : keepsakes) {
		ofs.write(item.c_str(), item.size() + 1);
	}

	// --- Inventory items ���� ---
	size_t invItemCount = inventory.items.size();
	ofs.write(reinterpret_cast<const char*>(&invItemCount), sizeof(invItemCount));
	for (const auto& itemPtr : inventory.items) {
		if (itemPtr) {
			ofs.write(reinterpret_cast<const char*>(&itemPtr->id), sizeof(itemPtr->id));
			ofs.write(reinterpret_cast<const char*>(&itemPtr->quantity), sizeof(itemPtr->quantity));
			// �ʿ��ϴٸ� atkBonus, defBonus, hpBonus � ���� ����
		}
		else {
			int invalidId = -1;
			int zeroQty = 0;
			ofs.write(reinterpret_cast<const char*>(&invalidId), sizeof(invalidId));
			ofs.write(reinterpret_cast<const char*>(&zeroQty), sizeof(zeroQty));
		}
	}

	// --- Equipped items ���� ---
	size_t equippedCount = inventory.equippedItems.size();
	ofs.write(reinterpret_cast<const char*>(&equippedCount), sizeof(equippedCount));
	for (const auto& eqItemPtr : inventory.equippedItems) {
		if (eqItemPtr) {
			ofs.write(reinterpret_cast<const char*>(&eqItemPtr->id), sizeof(eqItemPtr->id));
			ofs.write(reinterpret_cast<const char*>(&eqItemPtr->quantity), sizeof(eqItemPtr->quantity));
			// �ʿ��ϴٸ� atkBonus, defBonus, hpBonus ���� ����
		}
		else {
			int invalidId = -1;
			int zeroQty = 0;
			ofs.write(reinterpret_cast<const char*>(&invalidId), sizeof(invalidId));
			ofs.write(reinterpret_cast<const char*>(&zeroQty), sizeof(zeroQty));
		}
	}

	// --- Buff ���� (�ʿ��) ---
	ofs.write(reinterpret_cast<const char*>(&currentBuff.atkBoost), sizeof(currentBuff.atkBoost));
	ofs.write(reinterpret_cast<const char*>(&currentBuff.defBoost), sizeof(currentBuff.defBoost));
	ofs.write(reinterpret_cast<const char*>(&currentBuff.hpBoost), sizeof(currentBuff.hpBoost));
	ofs.write(reinterpret_cast<const char*>(&currentBuff.atkBuffTurns), sizeof(currentBuff.atkBuffTurns));
	ofs.write(reinterpret_cast<const char*>(&currentBuff.defBuffTurns), sizeof(currentBuff.defBuffTurns));
	ofs.write(reinterpret_cast<const char*>(&currentBuff.hpBuffTurns), sizeof(currentBuff.hpBuffTurns));

	return !ofs.fail();
}

bool Player::Load(std::ifstream& ifs) {
	if (!ifs) return false;

	std::getline(ifs, name, '\0');
	std::getline(ifs, jobName, '\0');

	ifs.read(reinterpret_cast<char*>(&Job), sizeof(Job));
	ifs.read(reinterpret_cast<char*>(&hp), sizeof(hp));
	ifs.read(reinterpret_cast<char*>(&maxHp), sizeof(maxHp));
	ifs.read(reinterpret_cast<char*>(&atk), sizeof(atk));
	ifs.read(reinterpret_cast<char*>(&def), sizeof(def));
	ifs.read(reinterpret_cast<char*>(&level), sizeof(level));
	ifs.read(reinterpret_cast<char*>(&EXP), sizeof(EXP));
	ifs.read(reinterpret_cast<char*>(&MaxEXP), sizeof(MaxEXP));
	ifs.read(reinterpret_cast<char*>(&karma), sizeof(karma));
	ifs.read(reinterpret_cast<char*>(&unlockedChapter), sizeof(unlockedChapter));
	ifs.read(reinterpret_cast<char*>(&gold), sizeof(gold));

	// clues ����
	size_t clueCount = 0;
	ifs.read(reinterpret_cast<char*>(&clueCount), sizeof(clueCount));
	clues.clear();
	for (size_t i = 0; i < clueCount; ++i) {
		std::string clue;
		std::getline(ifs, clue, '\0');
		clues.push_back(clue);
	}

	// keepsakes ����
	size_t keepsakeCount = 0;
	ifs.read(reinterpret_cast<char*>(&keepsakeCount), sizeof(keepsakeCount));
	keepsakes.clear();
	for (size_t i = 0; i < keepsakeCount; ++i) {
		std::string item;
		std::getline(ifs, item, '\0');
		keepsakes.push_back(item);
	}

	// --- Inventory items ���� ---
	size_t invItemCount = 0;
	ifs.read(reinterpret_cast<char*>(&invItemCount), sizeof(invItemCount));
	inventory.items.clear();
	for (size_t i = 0; i < invItemCount; ++i) {
		int id = 0;
		int qty = 0;
		ifs.read(reinterpret_cast<char*>(&id), sizeof(id));
		ifs.read(reinterpret_cast<char*>(&qty), sizeof(qty));

		if (id == -1 || qty == 0) {
			inventory.items.push_back(nullptr);
		}
		else {
			// ������ ID�� �´� ������ ������ ������ quantity�� ����� �ʿ�
			// ���⼱ ������ �� Item ����, ������ ������ ���̺��� �����ϴ� �� ����
			auto newItem = std::make_shared<Item>(id, "", ItemType::Consumable, qty, 0);
			inventory.items.push_back(newItem);
		}
	}

	// --- Equipped items ���� ---
	size_t equippedCount = 0;
	ifs.read(reinterpret_cast<char*>(&equippedCount), sizeof(equippedCount));
	inventory.equippedItems.clear();
	for (size_t i = 0; i < equippedCount; ++i) {
		int id = 0;
		int qty = 0;
		ifs.read(reinterpret_cast<char*>(&id), sizeof(id));
		ifs.read(reinterpret_cast<char*>(&qty), sizeof(qty));

		if (id == -1 || qty == 0) {
			inventory.equippedItems.push_back(nullptr);
		}
		else {
			auto newEqItem = std::make_shared<Item>(id, "", ItemType::Consumable, qty, 0);
			inventory.equippedItems.push_back(newEqItem);
		}
	}

	// --- Buff ���� ---
	ifs.read(reinterpret_cast<char*>(&currentBuff.atkBoost), sizeof(currentBuff.atkBoost));
	ifs.read(reinterpret_cast<char*>(&currentBuff.defBoost), sizeof(currentBuff.defBoost));
	ifs.read(reinterpret_cast<char*>(&currentBuff.hpBoost), sizeof(currentBuff.hpBoost));
	ifs.read(reinterpret_cast<char*>(&currentBuff.atkBuffTurns), sizeof(currentBuff.atkBuffTurns));
	ifs.read(reinterpret_cast<char*>(&currentBuff.defBuffTurns), sizeof(currentBuff.defBuffTurns));
	ifs.read(reinterpret_cast<char*>(&currentBuff.hpBuffTurns), sizeof(currentBuff.hpBuffTurns));

	// ������ �´� ��ų �ڵ� �缳��
	InitSkills();

	return !ifs.fail();
}

void Player::ShowMemoryStorage() const
{
	std::cout << "\n=== [��� �����] ===\n";

	std::cout << "\n[�ܼ�]\n";
	if (clues.empty())
	{
		std::cout << "���� �߰��� �ܼ��� �����ϴ�.\n";
	}
	else
	{
		for (size_t i = 0; i < clues.size(); ++i) {
			std::cout << i + 1 << ". " << clues[i] << "\n";
		}
	}

	std::cout << "\n[��ǰ]\n";
	if (keepsakes.empty())
	{
		std::cout << "���� �߰��� ��ǰ�� �����ϴ�.\n";
	}
	else
	{
		for (size_t i = 0; i < keepsakes.size(); ++i)
		{
			std::cout << i + 1 << ". " << keepsakes[i] << "\n";
		}
	}

	std::cout << "\n====================\n";
	TypeWriter("\n--- [����Ϸ��� Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();
}

void Player::InitSkills() {
	skillSet.clear(); // ���� ��ų ����

	if (Job == 1) {
		skillSet.push_back({ "���� ��ô", "�⺻ ������" });
		// �ʿ� �� �� �߰� ����
	}
	else if (Job == 2) {
		skillSet.push_back({ "���� �ر�", "�⺻ ������" });
	}
	else if (Job == 3) {
		skillSet.push_back({ "���� ��ô", "�⺻ ������" });
	}
}

int Player::Attack(int skillChoice, int ghostDef, int skillweight)
{
	int currentAtk = GetTotalAtk();
	int Damage = 0;

	Damage = (currentAtk - (ghostDef / 2)) * skillweight / 100;

	return Damage;
}

void Player::LevelUp()
{
	EXP -= MaxEXP;
	MaxEXP = static_cast<int>(MaxEXP * 1.35); // �ִ� ����ġ 35% ����
	level++;

	maxHp = static_cast<int>(maxHp * 1.10);   // ü�� 10% ����
	atk = static_cast<int>(atk * 1.10);       // ���ݷ� 10% ����
	def = static_cast<int>(def * 1.10);       // ���� 10% ����
	hp = maxHp; // ü�� ȸ��

	std::cout << "���� ��! ���� ����: " << level << "\n";
	std::cout << "ü��, ���ݷ�, ������ �����߽��ϴ�!\n";

	if (level == 3)
	{
		if (Job == 1) {
			skillSet.push_back({ "������ ��", "���� ������ + 3�� ���� ���� ������" });
			// �ʿ� �� �� �߰� ����
		}
		else if (Job == 2) {
			skillSet.push_back({ "ǳ�� ����", "���� ������ + 1�� ���� �ͽ� ����" });
		}
		else if (Job == 3) {
			skillSet.push_back({ "������ �ϰ�", "���� ������ + ���ط� 50% ȸ��" });
		}
		TypeWriter("���ο� ��ų�� ������ϴ�!\n", 30);
	}

	
	if (level == 3 || level == 6 || level == 10)
	{
		
	}

	if (level == 4 || level == 7 || level == 9)
	{
		inventory.IncreaseMaxSlots(5);
		TypeWriter("���� ��! ���� ����: " + std::to_string(level) + "\n", 5);
		TypeWriter("�κ��丮 �ִ� ������ " + std::to_string(inventory.maxSlots) + "ĭ���� �þ���ϴ�!\n", 5);
	}
}

bool Player::UseItem(int itemId)
{
	Inventory& inv = this->inventory;

	switch (itemId) {
	case 0:
	{
		int healAmount = 10;
		hp += healAmount;
		TypeWriter("�����ʸ� ����� ü���� ȸ���߽��ϴ�.\n", 20);
		break;
	}
	case 1:
		ApplyAtkBuff(10, 3);
		TypeWriter("�Ź��� ������ ���ݷ��� ����߽��ϴ�.\n", 20);
		break;
	case 2:
		TypeWriter("���ž������� �̻� ���¸� ȸ���߽��ϴ�.\n", 20);
		break;
	case 3:
	{
		TypeWriter("ȥ�ɼ��� ����� ��� ��ȭ�մϴ�.\n", 20);
		TypeWriter("\n��ȭ�� ��� ���� ��ȣ�� �����ϼ���.\n", 20);
		TypeWriter("\n�޴��� ���ư��÷��� 0\n", 10);
		TypeWriter("1. ����  2. ��  3. �Ǽ��縮\n", 20);
		TypeWriter("> ");

		int choice = 0;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 0) break;

		int idx = choice - 1;
		if (idx < 0 || idx >= 3) {
			TypeWriter("�߸��� �Է��Դϴ�.\n", 20);
			break;
		}

		auto& targetPtr = inventory.equippedItems[idx];
		if (!targetPtr || targetPtr->id == -1) {
			TypeWriter("�ش� ���Կ� ������ ��� �����ϴ�.\n", 20);
			break;
		}

		// dynamic_cast ����, Item Ŭ���� ����� �ٷ� ����
		targetPtr->atkBonus += 1;
		targetPtr->defBonus += 1;

		TypeWriter("[" + targetPtr->name + "] ��(��) ��ȭ�Ǿ����ϴ�!\n", 20);

		break;
	}
	default:
		return false;
	}

	if (!inv.RemoveItem(itemId, 1)) {
		return false;
	}

	return true;
}
