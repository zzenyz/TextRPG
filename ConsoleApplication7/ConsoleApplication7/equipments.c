#include "equipments.h"

void initEquipments() {
    // 무당 공격 장비
    equipmentList[0] = (Equipment){ "신방울", "공격력 +20%", 0, 0, WEAPON};

    // 풍수지리사 공격 장비
    equipmentList[1] = (Equipment){ "나침반", "공격력 +15%", 0, 0, WEAPON};
    
    // 신학생 공격 장비
    equipmentList[2] = (Equipment){ "성경책", "공격력 +15%", 0, 0, WEAPON};

    // 치료 장비 (상점 판매용)
    equipmentList[3] = (Equipment){ "구슬 목걸이", "매 턴 HP 10% 회복", 500, 250, ACCESSORY};
    equipmentList[4] = (Equipment){ "정기 두루마기", "매 턴 HP 10% 회복", 500, 250, ACCESSORY};
    equipmentList[5] = (Equipment){ "성수병", "매 턴 HP 10% 회복", 500, 250, ACCESSORY};
}

void applyEquipmentEffect(Player* player) {
    if (player == NULL) return;  // player가 NULL이면 바로 종료
    if (player->equippedItems.accessory == NULL) return;

    Equipment* eq = player->equippedItems.accessory;

    if (strcmp(eq->name, "구슬 목걸이") == 0) {
        player->hp = (int)(player->hp * 1.1);
        if (player->hp > player->maxHp) player->hp = player->maxHp;
        printf("\n🧿 구슬 목걸이 효과로 HP 10%% 회복!\n");
    }
    else if (strcmp(eq->name, "정기 두루마기") == 0) {
        player->hp = (int)(player->hp * 1.1);
        if (player->hp > player->maxHp) player->hp = player->maxHp;
        printf("\n📜 정기 두루마기 효과로 HP 10%% 회복!\n");
    }
    else if (strcmp(eq->name, "성수병") == 0) {
        player->hp = (int)(player->hp * 1.1);
        if (player->hp > player->maxHp) player->hp = player->maxHp;
        printf("\n💧 성수병 효과로 HP 10%% 회복!\n");
    }

    // 최대 체력 초과 방지 (여기선 이미 위에서 체크함, 중복 가능)
    if (player->hp > player->maxHp) {
        player->hp = player->maxHp;
    }
}
