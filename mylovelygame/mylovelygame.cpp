#include "Game.h"
#include "GameUtils.h"

int main() 
{   
    UINT oldCP = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ClearScreen();
    ShowTItle();
    SleepMs(2000);

    SetConsoleOutputCP(oldCP);
    SetConsoleCP(oldCP);

    Game game;
    game.Start();

    return 0;
}

