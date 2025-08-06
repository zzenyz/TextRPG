#pragma once
#include <iostream>

#include "Item.h"
#include "GameUtils.h"


class Chapter3
{
private:
    bool clueFound = false;
    bool KeepsakeFound = false;
    bool Keepsake4Found = false;
    bool bossAwakened = false;

public:

    //EndChapter();          // 3. 클리어 후 스토리 출력

    void SetClueFound()
    {
        clueFound = true;
    }
    bool GetHasFoundClue() const { return clueFound; }

    void SetKeepsakeFound()
    {
        KeepsakeFound = true;
    }
    bool GetHasFoundKeepsake() const { return KeepsakeFound; }

    void SetKeepsake4Found()
    {
        KeepsakeFound = true;
    }
    bool GetHasFoundKeepsake4() const { return Keepsake4Found; }

    bool GetbossAwakened() const { return bossAwakened; }

    void ShowIntro();
    void ExploreMap();
    void ExploreStorage();
    void ExploreBoat();
    void ExploreDockEdge();
    void ExploreLighthouse();
    void Warn();
    void Outtro();

};

