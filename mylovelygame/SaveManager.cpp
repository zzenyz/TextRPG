#include "SaveManager.h"

const std::string SaveManager::SaveFileName = "savemylovelygame.dat";


bool SaveManager::HasSavedGame() {
    std::ifstream ifs(SaveFileName, std::ios::binary);
    return ifs.good();
}

bool SaveManager::SaveGame(const Player& player) {
    std::ofstream ofs(SaveFileName, std::ios::binary);
    if (!ofs) return false;
    return player.Save(ofs);  // player 클래스에 Save 함수 있어야 함
}

bool SaveManager::LoadGame(Player& player) {
    std::ifstream ifs(SaveFileName, std::ios::binary);
    if (!ifs) return false;
    return player.Load(ifs);  // player 클래스에 Load 함수 있어야 함
}
