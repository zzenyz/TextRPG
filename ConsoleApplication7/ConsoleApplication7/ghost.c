#include "ghost.h"

void InitGhost(Ghost* ghost) {
	ghost->maxHp = 80;
	ghost->atk = 10;
	ghost->hp = ghost->maxHp;
}

void GhostAttack(Player* player, Ghost* ghost)
{  // EnemyHp도 포인터로 받기 (반격 데미지 적용하려면)
	int ghostAction;

	
	// 체력이 30 이하일 때 공격 확률 증가
	if (ghost->hp <= 30)
	{
		ghostAction = rand() % 100;
		if (ghostAction < 5) {
			printf("귀신이 지쳐 잠시 숨을 고릅니다...\n");
			return;
		}
		else {
			int ghostDamage = (ghost->atk * 1.3) + rand() % 6;

			if (player->job == 2)
			{
				int dodgeChance = rand() % 100;  // 0~99
				if (dodgeChance < 20) {
					printf("✨ 풍수지리사가 지형을 이용하여 공격을 회피했습니다!\n");
					return;  // 공격 무효
				}
			}


			player->hp -= ghostDamage;
			printf("귀신이 발악하며 반격! %d 피해를 입혔습니다.\n", ghostDamage);
		}


		return;
	}

	// 체력이 30 초과일 때 기존 행동
	ghostAction = rand() % 100;
	if (ghostAction < 20) {
		printf("귀신이 쉬고 있습니다...\n");
	}
	else if (ghostAction < 40) {
		for (int i = 0; i < 2; i++) {
			int ghostDamage = (ghost->atk * 1.2) + rand() % 6;

			if (player->job == 2)
			{
				int dodgeChance = rand() % 100;  // 0~99
				if (dodgeChance < 100) {
					printf("✨ 풍수지리사가 지형을 이용하여 공격을 회피했습니다!\n");
					return;  // 공격 무효
				}
			}
			player->hp -= ghostDamage;
			printf("귀신이 강하게 반격하여 %d 피해를 입혔습니다.\n", ghostDamage);

			if (player->hp <= 0) break;
		}
	}
	else {
		int ghostDamage = ghost->atk + rand() % 6;

		if (player->job == 2)
		{
			int dodgeChance = rand() % 100;  // 0~99
			if (dodgeChance < 100) {
				printf("✨ 풍수지리사가 지형을 이용하여 공격을 회피했습니다!\n");
				return;  // 공격 무효
			}
		}

		player->hp -= ghostDamage;
		printf("귀신이 반격하여 %d 피해를 입혔습니다.\n", ghostDamage);
	}
	Sleep(500);

}




//========귀신 지속 데미지 함수==========
void applyGhostDotDamage(Player* player, Ghost* ghost)
{
	if (player->ghostDotTurn > 0) {
		int dotDamage = player->atk / 5;  // 예: 기본 공격력의 20% 데미지
		ghost->hp -= dotDamage;
		if (ghost->hp < 0) ghost->hp = 0;
		player->ghostDotTurn--;

		printf("\n👻 신령님의 신묘한 힘이 귀신에게 %d의 피해를 입혔습니다.\n", dotDamage);
	}
}