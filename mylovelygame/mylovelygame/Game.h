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
#include "miniGame.h"
#include "Ghost.h"

class Game {
public:
    void Start();

private:
    Player player;
    Chapter1 chapter1;
    miniGame minigame;
    Ghost ghost;

       // Map currentMap;  // �ʿ��ϸ� Ȱ��ȭ

    void ShowIntro();
    void GameLoop();
    void ShowMainMenu();
    void ShowStoryMenu();
    void StartChapter(int chapterNumber);
    void Battle();
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
