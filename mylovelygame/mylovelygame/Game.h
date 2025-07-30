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

class Game {
public:
    void Start();

private:
    Player player;
    // Map currentMap;  // �ʿ��ϸ� Ȱ��ȭ

    void ShowIntro();
    void GameLoop();
    void ShowMainMenu();
    void ShowStoryMenu();
    //void StartChapter(int chapterNumber);

    // ������ ������ �Լ���
   /* void StartStory();
    void ShowInventory();
    void SaveGame();
    bool LoadGame();
    bool HasSavedGame();*/
};
