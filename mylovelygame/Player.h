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

	// �̸� & ����
	void SetName(const std::string& newName) { name = newName; }
	std::string GetName() const { return name; }

	void reSetJob(int jobNumber) {

		Job = jobNumber;

		switch (jobNumber) {

		case 1:
			jobName = "����";
			hp = maxHp = 45; atk = 63; def = 55;
			break;
		case 2:
			jobName = "ǳ��������";
			hp = maxHp = 55; atk = 55; def = 45;
			break;
		case 3:
			jobName = "���л�";
			hp = maxHp = 65; atk = 45; def = 45;
			break;
		default:
			jobName = "����";
			hp = maxHp = 45; atk = 63; def = 55;
		}

		InitSkills();
	}

	std::string GetJobName() const { return jobName; }
	int GettJob() const { return Job; }

	void InitSkills();
	const std::vector<Skill>& GetSkillSet() const { return skillSet; }

	// �ɷ�ġ
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

	// �ܼ� �߰�
	void AddClue(const std::string& clue) {
		clues.push_back(clue);
	}

	// ��ǰ �߰�
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
				//std::cout << "[�����] ���� ������ ID: " << eqItemPtr->id << ", ���� ���ʽ�: " << bonus << "%\n";
				totalAtkBonusPercent += bonus;
			}
			//else
			//{
				//std::cout << "[�����] ���� ������ ���� �Ǵ� nullptr\n";
			//}
		}

		//std::cout << "[�����] �⺻ ���ݷ�: " << atk << "\n";
		//std::cout << "[�����] ���� ���� ���ʽ�: " << currentBuff.atkBoost << "%\n";

		int weaponBonus = (atk * totalAtkBonusPercent) / 100;
		int buffBonus = (atk * currentBuff.atkBoost) / 100;
		int total = atk + weaponBonus + buffBonus;

		//std::cout << "[�����] ������ ���� ���ʽ� �ջ�: " << weaponBonus << "\n";
		//std::cout << "[�����] ���� ���ʽ� ���� ��: " << buffBonus << "\n";
		//std::cout << "[�����] ���� ���ݷ�: " << total << "\n";

		return total;
	}


	void ApplyAtkBuff(int amountPercent, int turns)
	{
		currentBuff.atkBoost = amountPercent;
		currentBuff.atkBuffTurns = turns;
	}

	int GetTotalDef() const
	{
		int totalDefBonus = 0;

		for (const auto& eqItemPtr : inventory.equippedItems)
		{
			if (eqItemPtr != nullptr && eqItemPtr->id != -1)
			{
				int defBonus = eqItemPtr->GetDefBonus();
				// std::cout << "[�����] ���� ������ ID: " << eqItemPtr->id << ", ��� ���ʽ�: " << defBonus << "\n";
				totalDefBonus += defBonus;
			}
			else
			{
				// std::cout << "[�����] ���� ������ ���� �Ǵ� nullptr\n";
			}
		}

		// std::cout << "[�����] �⺻ ����: " << def << "\n";
		// std::cout << "[�����] ���� ��� ���ʽ�: " << currentBuff.defBoost << "%\n";

		int buffDefBonus = (def * currentBuff.defBoost) / 100;
		int total = def + totalDefBonus + buffDefBonus;

		// std::cout << "[�����] ������ ��� ���ʽ� �ջ�: " << totalDefBonus << "\n";
		// std::cout << "[�����] ���� ���ʽ� ���� ��: " << buffDefBonus << "\n";
		// std::cout << "[�����] ���� ����: " << total << "\n";

		return total;
	}

	void ApplyDefBuff(int amountPercent, int turns)
	{
		currentBuff.defBoost = amountPercent;
		currentBuff.defBuffTurns = turns;
	}

	void EquipHp()
	{
		int totalEquipHpBonus = 0;

		for (const auto& eqItemPtr : inventory.equippedItems)
		{
			if (eqItemPtr != nullptr && eqItemPtr->id != -1)
			{
				totalEquipHpBonus += eqItemPtr->GetHpBonus();
				std::cout << "[��� ȿ��] ������ ID: " << eqItemPtr->id << " ü�� +" << totalEquipHpBonus << "\n";
			}
		}

		// ��� ���ʽ��� ������ �� ���� �־� ���� ����
		ApplyHpBuff(totalEquipHpBonus, 3);  // ��: 3�� ����
	}

	void ApplyHpBuff(int amountPercent, int turns)
	{
		currentBuff.hpBoost = amountPercent;
		currentBuff.hpBuffTurns = turns;
	}

	// ��� ü�� ȸ�� �Լ� �߰�
	void HealHp(int amount)
	{
		hp += amount;
		if (hp > maxHp)
			hp = maxHp;
	}
	void UpdateBuff()
	{
		if (currentBuff.atkBuffTurns > 0) {
			currentBuff.atkBuffTurns--;
			if (currentBuff.atkBuffTurns == 0) currentBuff.atkBoost = 0;
		}
		if (currentBuff.defBuffTurns > 0) {
			currentBuff.defBuffTurns--;
			if (currentBuff.defBuffTurns == 0) currentBuff.defBoost = 0;
		}
		if (currentBuff.hpBuffTurns > 0) {
			int healAmount = (maxHp * currentBuff.hpBoost) / 100;
			if (healAmount > 0) {
				HealHp(healAmount);
				std::cout << "[ȸ��] ü���� " << healAmount << "��ŭ ȸ���Ǿ����ϴ�.\n";
			}
			currentBuff.hpBuffTurns--;
			if (currentBuff.hpBuffTurns == 0) {
				currentBuff.hpBoost = 0;
			}
		}
	}



//���� ���̺� �ε�
bool Save(std::ofstream& ofs) const;
bool Load(std::ifstream& ifs);

int Attack(int skillChoice, int ghostDef, int skillweight);
void LevelUp();

bool UseItem(int itemId);

void Reset();
	};
