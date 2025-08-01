#pragma once
#include <iostream>

#include "Map.h"
//#include "Battle.h"
#include "Item.h"
#include "GameUtils.h"


class Chapter1
{
private:
    bool clueFound = false;
   
    
public:
    
        //EndChapter();          // 3. 클리어 후 스토리 출력
  
    void SetClueFound()
    {
        clueFound = true;
    }
    bool GetHasFoundClue() const { return clueFound; }

    void ShowIntro();
    void ExploreMap();
    void ExploreHut();
    void Warn();
};

