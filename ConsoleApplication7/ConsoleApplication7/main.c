#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

#include "struct.h"
#include "player.h"
#include "effect.h"
#include "ruins.h"
#include "ghost.h"

int main() {

    Player player;
    Ghost ghost;

    initEquipments();

    srand((unsigned int)time(NULL));

    Sleep(1000);
   
    printf("직업 선택:\n1. 무당\n2. 풍수지리사\n3. 신학생\n");
    printf("선택: ");
    scanf_s("%d", &player.job);

    if (player.job < 무당 || player.job > 3) {
        printf("잘못된 직업입니다. 무당으로 설정합니다.\n");
        player.job = 무당;
    }
    
    initPlayer(&player);

    player.equippedItems.accessory = &equipmentList[player.job + 2];
    printf("%s를 착용하였습니다.", player.equippedItems.accessory->name);


    initSkillsForPlayer(&player);
    InitGhost(&ghost);

    Sleep(1000);

    마을(&player, &ghost);

    return 0;
}

