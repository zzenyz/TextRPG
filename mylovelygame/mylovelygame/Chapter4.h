#pragma once
#include <iostream>

#include "Item.h"
#include "GameUtils.h"


class Chapter4
{
private:
    bool clueFound1 = false;
    bool clueFound2 = false;
    bool clueFound5 = false;
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

    void SetClue5Found()
    {
        clueFound5 = true;
    }
    bool GetHasFoundClue5() const { return clueFound5; }

    bool GetbossAwakened() const { return bossAwakened; }

    void ShowIntro();
    void Warn();
    void ExploreMap();         // ��� ���� �� ���

    void ExploreStaffRoom();        // 1. ���� ����
    void ExploreClassroom(); // 2. ���� ���� ����
    void ExploreInfirmary();// 3. ��������� ����
    void ExploreMusicRoom();
    void Outtro();

};
