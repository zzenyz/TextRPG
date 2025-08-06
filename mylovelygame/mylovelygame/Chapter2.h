#pragma once
#include <iostream>

#include "Item.h"
#include "GameUtils.h"


class Chapter2
{
private:
    bool clueFound1 = false;
    bool clueFound2 = false;
    bool KeepsakeFound = false;
    bool bossAwakened = false;

public:

    //EndChapter();          // 3. Ŭ���� �� ���丮 ���

    void SetClue1Found()
    {
        clueFound1 = true;
    }
    bool GetHasFoundClue1() const { return clueFound1; }

    void SetClue2Found()
    {
        clueFound2 = true;
    }
    bool GetHasFoundClue2() const { return clueFound2; }

    void SetKeepsakeFound()
    {
        KeepsakeFound = true;
    }
    bool GetHasFoundKeepsake() const { return KeepsakeFound; }

    bool GetbossAwakened() const { return bossAwakened; }

    void ShowIntro();
    void Warn();
    void ExploreMap();         // ��� ���� �� ���

    void ExploreCell();        // 1. ���� ����
    void ExploreTortureRoom(); // 2. ���� ���� ����
    void ExploreWardenOffice();// 3. ��������� ����
    void ExploreWatchtower();
    void Outtro();

};
