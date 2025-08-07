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

	// clues 저장
	size_t clueCount = clues.size();
	ofs.write(reinterpret_cast<const char*>(&clueCount), sizeof(clueCount));
	for (const std::string& clue : clues) {
		ofs.write(clue.c_str(), clue.size() + 1);
	}

	// keepsakes 저장
	size_t keepsakeCount = keepsakes.size();
	ofs.write(reinterpret_cast<const char*>(&keepsakeCount), sizeof(keepsakeCount));
	for (const std::string& item : keepsakes) {
		ofs.write(item.c_str(), item.size() + 1);
	}

	// --- Inventory items 저장 ---
	size_t invItemCount = inventory.items.size();
	ofs.write(reinterpret_cast<const char*>(&invItemCount), sizeof(invItemCount));
	for (const auto& itemPtr : inventory.items) {
		if (itemPtr) {
			ofs.write(reinterpret_cast<const char*>(&itemPtr->id), sizeof(itemPtr->id));
			ofs.write(reinterpret_cast<const char*>(&itemPtr->quantity), sizeof(itemPtr->quantity));
			// 필요하다면 atkBonus, defBonus, hpBonus 등도 저장 가능
		}
		else {
			int invalidId = -1;
			int zeroQty = 0;
			ofs.write(reinterpret_cast<const char*>(&invalidId), sizeof(invalidId));
			ofs.write(reinterpret_cast<const char*>(&zeroQty), sizeof(zeroQty));
		}
	}

	// --- Equipped items 저장 ---
	size_t equippedCount = inventory.equippedItems.size();
	ofs.write(reinterpret_cast<const char*>(&equippedCount), sizeof(equippedCount));
	for (const auto& eqItemPtr : inventory.equippedItems) {
		if (eqItemPtr) {
			ofs.write(reinterpret_cast<const char*>(&eqItemPtr->id), sizeof(eqItemPtr->id));
			ofs.write(reinterpret_cast<const char*>(&eqItemPtr->quantity), sizeof(eqItemPtr->quantity));
			// 필요하다면 atkBonus, defBonus, hpBonus 저장 가능
		}
		else {
			int invalidId = -1;
			int zeroQty = 0;
			ofs.write(reinterpret_cast<const char*>(&invalidId), sizeof(invalidId));
			ofs.write(reinterpret_cast<const char*>(&zeroQty), sizeof(zeroQty));
		}
	}

	// --- Buff 저장 (필요시) ---
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

	// clues 복원
	size_t clueCount = 0;
	ifs.read(reinterpret_cast<char*>(&clueCount), sizeof(clueCount));
	clues.clear();
	for (size_t i = 0; i < clueCount; ++i) {
		std::string clue;
		std::getline(ifs, clue, '\0');
		clues.push_back(clue);
	}

	// keepsakes 복원
	size_t keepsakeCount = 0;
	ifs.read(reinterpret_cast<char*>(&keepsakeCount), sizeof(keepsakeCount));
	keepsakes.clear();
	for (size_t i = 0; i < keepsakeCount; ++i) {
		std::string item;
		std::getline(ifs, item, '\0');
		keepsakes.push_back(item);
	}

	// --- Inventory items 복원 ---
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
			// 아이템 ID에 맞는 아이템 정보를 가져와 quantity만 덮어쓰기 필요
			// 여기선 간단히 새 Item 생성, 실제론 아이템 테이블에서 복원하는 게 좋음
			auto newItem = std::make_shared<Item>(id, "", ItemType::Consumable, qty, 0);
			inventory.items.push_back(newItem);
		}
	}

	// --- Equipped items 복원 ---
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

	// --- Buff 복원 ---
	ifs.read(reinterpret_cast<char*>(&currentBuff.atkBoost), sizeof(currentBuff.atkBoost));
	ifs.read(reinterpret_cast<char*>(&currentBuff.defBoost), sizeof(currentBuff.defBoost));
	ifs.read(reinterpret_cast<char*>(&currentBuff.hpBoost), sizeof(currentBuff.hpBoost));
	ifs.read(reinterpret_cast<char*>(&currentBuff.atkBuffTurns), sizeof(currentBuff.atkBuffTurns));
	ifs.read(reinterpret_cast<char*>(&currentBuff.defBuffTurns), sizeof(currentBuff.defBuffTurns));
	ifs.read(reinterpret_cast<char*>(&currentBuff.hpBuffTurns), sizeof(currentBuff.hpBuffTurns));

	// 직업에 맞는 스킬 자동 재설정
	InitSkills();

	return !ifs.fail();
}

void Player::ShowMemoryStorage() const
{
	std::cout << "\n=== [기억 저장소] ===\n";

	std::cout << "\n[단서]\n";
	if (clues.empty())
	{
		std::cout << "아직 발견한 단서가 없습니다.\n";
	}
	else
	{
		for (size_t i = 0; i < clues.size(); ++i) {
			std::cout << i + 1 << ". " << clues[i] << "\n";
		}
	}

	std::cout << "\n[유품]\n";
	if (keepsakes.empty())
	{
		std::cout << "아직 발견한 유품이 없습니다.\n";
	}
	else
	{
		for (size_t i = 0; i < keepsakes.size(); ++i)
		{
			std::cout << i + 1 << ". " << keepsakes[i] << "\n";
		}
	}

	std::cout << "\n====================\n";
	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();
}

void Player::InitSkills() {
	skillSet.clear(); // 기존 스킬 비우고

	if (Job == 1) {
		skillSet.push_back({ "부적 투척", "기본 데미지" });
		// 필요 시 더 추가 가능
	}
	else if (Job == 2) {
		skillSet.push_back({ "지맥 붕괴", "기본 데미지" });
	}
	else if (Job == 3) {
		skillSet.push_back({ "성수 투척", "기본 데미지" });
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
	MaxEXP = static_cast<int>(MaxEXP * 1.35); // 최대 경험치 35% 증가
	level++;

	maxHp = static_cast<int>(maxHp * 1.10);   // 체력 10% 증가
	atk = static_cast<int>(atk * 1.10);       // 공격력 10% 증가
	def = static_cast<int>(def * 1.10);       // 방어력 10% 증가
	hp = maxHp; // 체력 회복

	std::cout << "레벨 업! 현재 레벨: " << level << "\n";
	std::cout << "체력, 공격력, 방어력이 증가했습니다!\n";

	if (level == 3)
	{
		if (Job == 1) {
			skillSet.push_back({ "강신의 춤", "약한 데미지 + 3턴 동안 지속 데미지" });
			// 필요 시 더 추가 가능
		}
		else if (Job == 2) {
			skillSet.push_back({ "풍수 봉인", "약한 데미지 + 1턴 동안 귀신 봉인" });
		}
		else if (Job == 3) {
			skillSet.push_back({ "은총의 일격", "약한 데미지 + 피해량 50% 회복" });
		}
		TypeWriter("새로운 스킬을 배웠습니다!\n", 30);
	}

	
	if (level == 3 || level == 6 || level == 10)
	{
		
	}

	if (level == 4 || level == 7 || level == 9)
	{
		inventory.IncreaseMaxSlots(5);
		TypeWriter("레벨 업! 현재 레벨: " + std::to_string(level) + "\n", 5);
		TypeWriter("인벤토리 최대 슬롯이 " + std::to_string(inventory.maxSlots) + "칸으로 늘어났습니다!\n", 5);
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
		TypeWriter("생명초를 사용해 체력을 회복했습니다.\n", 20);
		break;
	}
	case 1:
		ApplyAtkBuff(10, 3);
		TypeWriter("신묘한 힘으로 공격력이 상승했습니다.\n", 20);
		break;
	case 2:
		TypeWriter("정신안정제로 이상 상태를 회복했습니다.\n", 20);
		break;
	case 3:
	{
		TypeWriter("혼령서를 사용해 장비를 강화합니다.\n", 20);
		TypeWriter("\n강화할 장비 슬롯 번호를 선택하세요.\n", 20);
		TypeWriter("\n메뉴로 돌아가시려면 0\n", 10);
		TypeWriter("1. 무기  2. 방어구  3. 악세사리\n", 20);
		TypeWriter("> ");

		int choice = 0;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 0) break;

		int idx = choice - 1;
		if (idx < 0 || idx >= 3) {
			TypeWriter("잘못된 입력입니다.\n", 20);
			break;
		}

		auto& targetPtr = inventory.equippedItems[idx];
		if (!targetPtr || targetPtr->id == -1) {
			TypeWriter("해당 슬롯에 장착된 장비가 없습니다.\n", 20);
			break;
		}

		// dynamic_cast 제거, Item 클래스 멤버로 바로 접근
		targetPtr->atkBonus += 1;
		targetPtr->defBonus += 1;

		TypeWriter("[" + targetPtr->name + "] 이(가) 강화되었습니다!\n", 20);

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
