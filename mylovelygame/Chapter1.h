#pragma once
#include <iostream>

#include "Item.h"
#include "GameUtils.h"


class Chapter1
{
private:
    bool clueFound = false;
    bool KeepsakeFound = false;
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

    bool GetbossAwakened() const { return bossAwakened; }

    void ShowIntro();
    void ExploreMap();
    void ExploreGrave();
    void ExploreHut();
    void ExploreAltar();
    void ExploreYard();
    void Warn();

};

