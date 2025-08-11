#pragma once
#include <iostream>

#include "Item.h"
#include "GameUtils.h"


class Chapter4
{
private:
    int battleCooldown = 0;    
    bool clueFound1 = false;
    bool clueFound2 = false;
    bool clueFound5 = false;
    bool bossAwakened = false;
    bool ghostcomesout = false;

public:

    //EndChapter();          // 3. 클리어 후 스토리 출력

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
    
    void Setghostcomesout(bool state)
    {
        ghostcomesout = state;
    }
    bool Getghostcomesout() const { return ghostcomesout; }

    void ShowIntro();
    void Warn();
    void ExploreMap();         // 장소 선택 맵 출력

    void ExploreStaffRoom();        // 1. 독방 조사
    void ExploreClassroom(); // 2. 지하 고문실 조사
    void ExploreInfirmary();// 3. 교도소장실 조사
    void ExploreMusicRoom();
    void Outtro();

};
