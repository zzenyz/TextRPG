#include "Ghost.h"
Ghost Ghost::GetRandomGhost() {
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(static_cast<unsigned int>(time(NULL)));
        isSeeded = true;
    }

    std::vector<Ghost> ghostPool = {
        Ghost(80, 15, 2, GhostRank::WEAK),
        Ghost(120, 25, 5, GhostRank::MEDIUM),
        Ghost(200, 40, 8, GhostRank::STRONG)
    };

    int idx = rand() % ghostPool.size();
    return ghostPool[idx];  // 복사로 반환해도 괜찮음
}