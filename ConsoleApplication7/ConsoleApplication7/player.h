#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "struct.h"

void initPlayer(Player* player);

//========스킬 초기화===========
void initSkillsForPlayer(Player* player);

int 무당Attack(int skill, Player* player);
int 풍수Attack(int skill, Player* player);
int 신학생Attack(int skill, Player* player);
void GhostAttack(Player* player, Ghost* ghost);

//========레벨업 함수==========
void leLevelUp(Player* player, Ghost* ghost);