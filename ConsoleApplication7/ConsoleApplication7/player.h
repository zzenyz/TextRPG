#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "struct.h"

void initPlayer(Player* player);

//========��ų �ʱ�ȭ===========
void initSkillsForPlayer(Player* player);

int ����Attack(int skill, Player* player);
int ǳ��Attack(int skill, Player* player);
int ���л�Attack(int skill, Player* player);
void GhostAttack(Player* player, Ghost* ghost);

//========������ �Լ�==========
void leLevelUp(Player* player, Ghost* ghost);