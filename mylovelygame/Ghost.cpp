#include "Ghost.h"
Ghost Ghost::GetRandomGhost(int chapter) {
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(static_cast<unsigned int>(time(NULL)));
        isSeeded = true;
    }

    int multiplier = 100 + 30 * (chapter - 1);  

    std::vector<Ghost> ghostPool = {
        Ghost(80 * multiplier / 100, 15 * multiplier / 100, 2 * multiplier / 100, GhostRank::WEAK),
        Ghost(120 * multiplier / 100, 25 * multiplier / 100, 5 * multiplier / 100, GhostRank::MEDIUM),
        Ghost(200 * multiplier / 100, 40 * multiplier / 100, 8 * multiplier / 100, GhostRank::STRONG)
    };

    int idx = rand() % ghostPool.size();
    return ghostPool[idx];
}

int Ghost::Attack(int JobNumber, int playerDef)
{
    int currentAtk = GetAtk();
    int Damage = 0;
    
    Damage = currentAtk - (playerDef / 2);

    if (Damage < 1) Damage = 1;

    return Damage;
}

Ghost Ghost::GetBossGhost(int chapter) {
    int multiplier = 100 + 25 * (chapter - 1);

    return Ghost(
        240 * multiplier / 100,
        42 * multiplier / 100,
        16 * multiplier / 100,
        GhostRank::BOSS
    );
}
