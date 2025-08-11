#pragma once
#include <string>
#include <fstream>

#include "Player.h"

class SaveManager {
public:
    static const std::string SaveFileName;

    static bool HasSavedGame();
    static bool SaveGame(const Player& player);
    static bool LoadGame(Player& player);
};
