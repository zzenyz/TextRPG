#pragma once
#include <iostream>

#include "Item.h"
#include "GameUtils.h"


class Chapter5
{
private:
    int battleCooldown = 0;
    bool clue1Found = false;
    bool clue2Found = false;
    bool KeepsakeFound = false;
    bool bossAwakened = false;
    bool ghostcomesout = false;

public:

    void SetClue1Found()
    {
        clue1Found = true;
    }
    bool GetHasFoundClue1() const { return clue1Found; }
    void SetClue2Found()
    {
        clue2Found = true;
    }
    bool GetHasFoundClue2() const { return clue2Found; }

    void SetKeepsakeFound()
    {
        KeepsakeFound = true;
    }
    bool GetHasFoundKeepsake() const { return KeepsakeFound; }

    bool GetbossAwakened() const { return bossAwakened; }

    void Setghostcomesout(bool state)
    {
        ghostcomesout = state;
    }
    bool Getghostcomesout() const { return ghostcomesout; }

    void ShowIntro();
    void ExploreMap();
    void Explorelivingroom();
    void Explorebasement();
    void Exploremasterroom();
    void Exploreattic();
    void Warn();
    void Outtro();

};

