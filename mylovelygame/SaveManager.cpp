#include "SaveManager.h"

const std::string SaveManager::SaveFileName = "savemylovelygame.dat";


bool SaveManager::HasSavedGame() {
    std::ifstream ifs(SaveFileName, std::ios::binary);
    return ifs.good();
}

bool SaveManager::SaveGame(const Player& player) {
    std::ofstream ofs(SaveFileName, std::ios::binary);
    if (!ofs) return false;
    return player.Save(ofs);  // player Ŭ������ Save �Լ� �־�� ��
}

bool SaveManager::LoadGame(Player& player) {
    std::ifstream ifs(SaveFileName, std::ios::binary);
    if (!ifs) return false;
    return player.Load(ifs);  // player Ŭ������ Load �Լ� �־�� ��
}
