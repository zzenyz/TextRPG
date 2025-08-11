#pragma once
#include <string>
#include <fstream>

#include "Inventory.h"
#include "Item.h"
#include "Buff.h"
#include "Skills.h"

class Player
{
private:
	std::string name;
	std::string jobName;
	int Job = 0;

	int hp = 0;
	int maxHp = 0;
	int atk = 0;
	int def = 0;
	int level;
	int EXP = 0;
	int MaxEXP = 100;
	int karma;
	int cluePoints = 0;
	int unlockedChapter;
	int gold = 0;
	std::vector<Skill> skillSet;

	Inventory inventory;

	std::vector<std::string> clues;
	std::vector<std::string> keepsakes;

	Buff currentBuff;

public:
	Player()
		: level(1), karma(0), unlockedChapter(1)
	{
	}

	// 이름 & 직업
	void SetName(const std::string& newName) { name = newName; }
	std::string GetName() const { return name; }

	void reSetJob(int jobNumber) {

		Job = jobNumber;

		switch (jobNumber) {

		case 1:
			jobName = "무당";
			hp = maxHp = 45; atk = 63; def = 55;
			break;
		case 2:
			jobName = "풍수지리사";
			hp = maxHp = 55; atk = 55; def = 45;
			break;
		case 3:
			jobName = "신학생";
			hp = maxHp = 65; atk = 45; def = 45;
			break;
		default:
			jobName = "무당";
			hp = maxHp = 45; atk = 63; def = 55;
		}

		InitSkills();
	}

	std::string GetJobName() const { return jobName; }
	int GettJob() const { return Job; }

	void InitSkills();
	const std::vector<Skill>& GetSkillSet() const { return skillSet; }

	// 능력치
	int GetHp() const { return hp; }
	void SetHp(int newHp) { hp = newHp; }

	int GetMaxHp() const { return maxHp; }
	void SetMaxHp(int newMaxHp) { maxHp = newMaxHp; }

	int GetAtk() const { return atk; }
	void SetAtk(int newAtk) { atk = newAtk; }

	int GetDef() const { return def; }
	void SetDef(int newDef) { def = newDef; }

	int GetLevel() const { return level; }
	void SetLevel(int newLevel) { level = newLevel; }

	int GetEXP() const { return EXP; }
	void SetEXP(int newEXP) { EXP = newEXP; }

	int GetMaxEXP() const { return MaxEXP; }
	void SetMaxEXP(int newMaxEXP) { MaxEXP = newMaxEXP; }

	int GetKarma() const { return karma; }
	void AddKarma() { karma += 1; }

	int GetcluePoints() const { return cluePoints; }
	void AddcluePoints() { cluePoints += 1; }

	int GetUnlockedChapter() const { return unlockedChapter; }
	void UnlockNextChapter() { ++unlockedChapter; }

	int GetGold() const { return gold; }
	void AddGold(int amount) { gold += amount; }
	bool SpendGold(int amount) {
		if (gold >= amount) {
			gold -= amount;
			return true;
		}
		return false;
	}

	Inventory& GetInventory() { return inventory; }
	const Inventory& GetInventory() const { return inventory; }

	// 단서 추가
	void AddClue(const std::string& clue) {
		clues.push_back(clue);
	}

	// 유품 추가
	void AddKeepsake(const std::string& Artikel) {
		keepsakes.push_back(Artikel);
	}

	void ShowMemoryStorage() const;

	int GetTotalAtk() const
	{
		int totalAtkBonusPercent = 0;

		for (const auto& eqItemPtr : inventory.equippedItems)
		{
			if (eqItemPtr != nullptr && eqItemPtr->id != -1)
			{
				int bonus = eqItemPtr->GetAtkBonus();
				//std::cout << "[디버그] 장착 아이템 ID: " << eqItemPtr->id << ", 공격 보너스: " << bonus << "%\n";
				totalAtkBonusPercent += bonus;
			}
			//else
			//{
				//std::cout << "[디버그] 장착 아이템 없음 또는 nullptr\n";
			//}
		}

		//std::cout << "[디버그] 기본 공격력: " << atk << "\n";
		//std::cout << "[디버그] 버프 공격 보너스: " << currentBuff.atkBoost << "%\n";

		int weaponBonus = (atk * totalAtkBonusPercent) / 100;
		int buffBonus = (atk * currentBuff.atkBoost) / 100;
		int total = atk + weaponBonus + buffBonus;

		//std::cout << "[디버그] 아이템 공격 보너스 합산: " << weaponBonus << "\n";
		//std::cout << "[디버그] 버프 보너스 적용 후: " << buffBonus << "\n";
		//std::cout << "[디버그] 최종 공격력: " << total << "\n";

		return total;
	}


	void ApplyAtkBuff(int amountPercent, int turns)
	{
		currentBuff.atkBoost = amountPercent;
		currentBuff.atkBuffTurns = turns;
	}

	int GetTotalDef() const
	{
		int equipDefBonus = 0;
		if (inventory.equippedItems.size() > 1 && inventory.equippedItems[1] != nullptr && inventory.equippedItems[1]->id != -1) {
			equipDefBonus = inventory.equippedItems[1]->GetDefBonus();
		}

		int buffDefBonus = (def * currentBuff.defBoost) / 100;
		return def + equipDefBonus + buffDefBonus;
	}

	void ApplyDefBuff(int amountPercent, int turns)
	{
		currentBuff.defBoost = amountPercent;
		currentBuff.defBuffTurns = turns;
	}

	int GetTotalHp() const
	{
		int equipHpBonus = 0;
		if (inventory.equippedItems.size() > 2 && inventory.equippedItems[2] != nullptr && inventory.equippedItems[2]->id != -1) {
			equipHpBonus = inventory.equippedItems[2]->GetHpBonus();
		}

		int buffHpBonus = (maxHp * currentBuff.hpBoost) / 100;
		return hp + equipHpBonus + buffHpBonus;
	}

	void ApplyHpBuff(int amountPercent, int turns)
	{
		currentBuff.hpBoost = amountPercent;
		currentBuff.hpBuffTurns = turns;
	}

	// 즉시 체력 회복 함수 추가
	void HealHp(int amount)
	{
		hp += amount;
		if (hp > maxHp)
			hp = maxHp;
	}
	void UpdateBuff(Buff& buff) {
		if (buff.atkBuffTurns > 0) {
			buff.atkBuffTurns--;
			if (buff.atkBuffTurns == 0) buff.atkBoost = 0;
		}
		if (buff.defBuffTurns > 0) {
			buff.defBuffTurns--;
			if (buff.defBuffTurns == 0) buff.defBoost = 0;
		}
		if (buff.hpBuffTurns > 0) {
			buff.hpBuffTurns--;
			if (buff.hpBuffTurns == 0) buff.hpBoost = 0;
		}
	}


	//파일 세이브 로드
	bool Save(std::ofstream& ofs) const;
	bool Load(std::ifstream& ifs);

	int Attack(int skillChoice, int ghostDef, int skillweight);
	void LevelUp();

	bool UseItem(int itemId);

	void Reset();
};


