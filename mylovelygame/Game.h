#pragma once
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

#include "Player.h"
#include "GameUtils.h" 
#include "SaveManager.h"
#include "Inventory.h"
#include "Shop.h"
#include "Chapter1.h"
#include "Chapter2.h"
#include "miniGame.h"
#include "Ghost.h"

class Game {
public:
    void Start();

private:
    Player player;
    Chapter1 chapter1;
    Chapter2 chapter2;
    miniGame minigame;
    Ghost ghost;

    void ShowIntro();
    void ShowPlayerStatus();
    void ShowMainMenu();
    void ShowStoryMenu();
    void StartChapter(int chapterNumber);
    void PlayMiniGameAndBattle(int chapterNumber);
    void Battle(const Ghost& enemy);
    std::string GetStatusString(bool isFearful, bool isCursed) {
        std::string status;

        if (isFearful)
            status += "�η��� ";
        if (isCursed)
            status += "���� ";

        if (status.empty())
            status = "����";

        return status;
    }
    int CalculateDamage(int attackerAtk, int defenderDef) {
        int damage = attackerAtk - (defenderDef / 2);
        if (damage < 1) damage = 1; // �ּ� 1 ����� ����
        return damage;
    }

    // ������ ������ �Լ���
   /* void StartStory();
    void ShowInventory();
    void SaveGame();
    bool LoadGame();
    bool HasSavedGame();*/

};
