#pragma once
#include <string>
#include <vector>
#include <time.h>


enum class GhostRank {
    WEAK,
    MEDIUM,
    STRONG,
    BOSS
};

class Ghost {
private:
    int maxHp;
    int hp;
    int atk;
    int def;

    GhostRank rank;

public:
    Ghost()  // 👈 이거 추가!
        : maxHp(10), hp(10), atk(5), def(2), rank(GhostRank::WEAK) {
    }

    Ghost(int maxHp, int atk, int def, GhostRank rank)
        : maxHp(maxHp), hp(maxHp), atk(atk), def(def), rank(rank) {
    }

    int GetHp() const { return hp; }
    int GetAtk() const { return atk; }
    int GetDef() const { return def; }
    GhostRank GetRank() const { return rank; }

    bool IsDead() const { return hp <= 0; }

    static Ghost GetRandomGhost();

    int Attack(int JobNumber, int playerDef);

};
