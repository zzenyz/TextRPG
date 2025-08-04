#pragma once
#include <iostream>

#include "Map.h"
#include "Item.h"
#include "GameUtils.h"


class Chapter1
{
private:
    bool clueFound = false;
    bool KeepsakeFound = false;
   
public:
    
        //EndChapter();          // 3. Ŭ���� �� ���丮 ���
  
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

    void ShowIntro();
    void ExploreMap();
    void ExploreGrave();
    void ExploreHut();
    void ExploreAltar();
    void ExploreYard();
    void Warn();

};

