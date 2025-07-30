#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

#include "struct.h"

void InitGhost(Ghost* ghost);
void GhostAttack(Player* player, Ghost* ghost);