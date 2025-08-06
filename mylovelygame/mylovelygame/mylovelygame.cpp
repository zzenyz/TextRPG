#include "Game.h"
#include "GameUtils.h"

int main() 
{   
    ClearScreen();
    ShowTItle();
    SleepMs(2000);

    Game game;
    game.Start();

    return 0;
}

