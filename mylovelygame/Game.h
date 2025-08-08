#pragma once
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define PlaySound PlaySoundW

#include "Player.h"
#include "GameUtils.h" 
#include "SaveManager.h"
#include "Inventory.h"
#include "Shop.h"
#include "Chapter1.h"
#include "Chapter2.h"
#include "Chapter3.h"
#include "Chapter4.h"
#include "Chapter5.h"
#include "Chapter6.h"
#include "miniGame.h"
#include "Ghost.h"
#include "Ending.h"

class Game {
public:
    void Start();

private:
    Player player;
    Chapter1 chapter1;
    Chapter2 chapter2;
    Chapter3 chapter3;
    Chapter4 chapter4;
    Chapter5 chapter5;
    miniGame minigame;
    Ghost ghost;

    void ShowIntro();
    void ShowPlayerStatus();
    void ShowMainMenu();
    void ShowStoryMenu();
    void StartChapter(int chapterNumber);
    void PlayMiniGameAndBattle(int chapterNumber);
    bool Battle(const Ghost& enemy);
    void CheckChapter5Ending();
    void CheckChapter6Ending();

    std::string GetStatusString(bool isFearful, bool isCursed) {
        std::string status;

        if (isFearful)
            status += "두려움 ";
        if (isCursed)
            status += "저주 ";

        if (status.empty())
            status = "정상";

        return status;
    }
    int CalculateDamage(int attackerAtk, int defenderDef) {
        int damage = attackerAtk - (defenderDef / 2);
        if (damage < 1) damage = 1; // 최소 1 대미지 보장
        return damage;
    }
  };

