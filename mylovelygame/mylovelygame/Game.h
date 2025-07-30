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
    // Map currentMap;  // 필요하면 활성화

    void ShowIntro();
    void GameLoop();
    void ShowMainMenu();
    void ShowStoryMenu();
    //void StartChapter(int chapterNumber);

    // 앞으로 구현할 함수들
   /* void StartStory();
    void ShowInventory();
    void SaveGame();
    bool LoadGame();
    bool HasSavedGame();*/
};
