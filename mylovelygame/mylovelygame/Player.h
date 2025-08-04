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
	int unlockedChapter;
	int gold = 100000;
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
	void AddKarma(int amount) { karma += amount; }

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

	//전투 시 버프 효과 함수 
	int GetTotalAtk() const
	{
		int equipAtkBonus = 0;
		const Item& weapon = inventory.equippedItems[0];  // 무기 슬롯

		// 빈 슬롯이 아니면 공격 보너스 가져오기 (EquipmentItem이면 dynamic_cast 가능하면 더 좋음)
		if (weapon.id != -1) {
			equipAtkBonus = weapon.GetAtkBonus();
		}

		return atk + equipAtkBonus + currentBuff.atkBoost;
	}

	void ApplyAtkBuff(int amount, int turns)
	{
		currentBuff.atkBoost = (atk * amount) / 100;
		currentBuff.atkBuffTurns = turns;
	}
	int GetTotalDef() const
	{
		int equipAtkBonus = 0;
		const Item& Armor = inventory.equippedItems[1];  // 무기 슬롯

		// 빈 슬롯이 아니면 공격 보너스 가져오기 (EquipmentItem이면 dynamic_cast 가능하면 더 좋음)
		if (Armor.id != -1) {
			equipAtkBonus = Armor.GetDefBonus();
		}

		return def + equipAtkBonus + currentBuff.defBoost;
	}
	void ApplyDefBuff(int amount, int turns)
	{
		currentBuff.defBoost = (def * amount) / 100;
		currentBuff.defBuffTurns = turns;
	}
	int GetTotalHp() const
	{
		int equipAtkBonus = 0;
		const Item& Accessory = inventory.equippedItems[2];  // 무기 슬롯

		// 빈 슬롯이 아니면 공격 보너스 가져오기 (EquipmentItem이면 dynamic_cast 가능하면 더 좋음)
		if (Accessory.id != -1) {
			equipAtkBonus = Accessory.GetDefBonus();
		}

		return hp + equipAtkBonus + currentBuff.hpBoost;
	}
	void ApplyHpBuff(int amount, int turns)
	{
		currentBuff.hpBoost = (hp * amount) / 100;
		currentBuff.hpBuffTurns = turns;
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
};
