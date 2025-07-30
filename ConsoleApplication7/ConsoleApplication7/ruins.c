#include "ruins.h"


void 던전(Player* player, Ghost* ghost) {

	int damagestack = 0;

	player->hp = player->maxHp;

	ghost->hp = ghost->maxHp;

	int maxAttacks = 10;        // 최대 공격 횟수 제한
	int attacksLeft = maxAttacks;
	player->playerStunTurn = 0;

	Sleep(1000);
	printf("\n폐허에 들어섭니다...\n");
	Sleep(1000);
	printf("갑자기 귀신이 나타났습니다!\n");
	Sleep(500);
	showGhost();
	Sleep(500);
	printf("🧙 당신의 체력: %d   👻 귀신의 체력: %d\n\n", player->hp, ghost->hp);


	if (player->job == 1) {
		ghost->hp = (int)(ghost->hp * 0.9);
		printf("신령님의 힘으로 귀신의 체력이 다소 감소했습니다!\n");
	}



	while (ghost->hp > 0 && player->hp > 0 && attacksLeft > 0) {
		printf("\n==== %d번째 턴 ====\n", 11 - attacksLeft);
		Sleep(500);
		printf("\n내 체력: %d  귀신 체력: %d\n\n", player->hp, ghost->hp);
		Sleep(500);
		printf("남은 공격 횟수: %d\n", attacksLeft);
		Sleep(500);

		if (player->ghostDotTurn > 0)
		{
			applyGhostDotDamage(player, ghost);
		}

		if (player->playerStunTurn > 0) {
			printf("😵 기절! 당신은 이번 턴은 쉴 수밖에 없습니다!\n\n");
			player->playerStunTurn--;
			attacksLeft--;

			GhostAttack(player, ghost);
			continue;
		}

		int choice;

		printf("\n스킬을 선택하세요: \n");
		// 직업별 스킬 설명 출력
		printf("\n[%s 스킬]\n", player->jobName);
		for (int i = 0; i < MAX_SKILL; i++) {  // 1,2번 스킬만 출력한다고 했으니 2개만
			printf("%d. %s: %s\n", i + 1, player->skillSet[i].name, player->skillSet[i].desc);
		}

		printf("%d. 아이템 사용\n", MAX_SKILL + 1);
		printf("%d. 도망가기\n", MAX_SKILL + 2);
		printf("\n선택: ");

		scanf_s("%d", &choice);

		if (choice == MAX_SKILL + 1)
		{
			useItemMenu(player);

			continue;
		}

		if (choice == MAX_SKILL + 2)
		{
			player->gold -= (int)(player->gold * 0.1);
			player->exp += damagestack / 2;

			Sleep(1000);
			printf("\n도망쳤습니다...\n");
			Sleep(500);
			printf("골드의 10%%를 잃었습니다...\n");
			printf("***현재 골드: %d G***\n", player->gold);
			Sleep(500);
			printf("경험치 %d 획득!\n", player->exp);

			Sleep(2000);

			clearScreen();
			return;
		}
		if (choice < 1 || choice > 4)
		{
			printf("\n잘못된 입력입니다.\n");
			continue;
		}

		if (choice == 2 && player->level < 2)
		{
			printf("\n2번 스킬은 레벨 2부터 사용할 수 있습니다. 현재 레벨: %d\n", player->level);
			continue;  // 다시 입력 받기
		}

		Sleep(500);

		int damage = 0;

		switch (player->job)
		{
		case 1:
			damage = 무당Attack(choice, player);
			break;
		case 2: damage = 풍수Attack(choice, player); break;
		case 3: damage = 신학생Attack(choice, player); break;
		}

		if (damage == -1)
		{
			printf("공격이 실패했습니다...\n");
			attacksLeft--;
		}
		else
		{
			damage += player->level * 3;  // 레벨별 추가 데미지 적용

			printf("귀신에게 %d 데미지!\n\n", damage);
			ghost->hp -= damage;
			attacksLeft--;
		}

		Sleep(500);

		if (damage > 0)
		{
			damagestack += damage;  // 데미지만큼 경험치 누적
		}

		if (ghost->hp <= 0) break;

		GhostAttack(player, ghost);

		applyEquipmentEffect(player);

		Sleep(500);
	}



	if (ghost->hp <= 0 && player->hp > 0) {
		player->exp += damagestack;

		printf("\n====전투 승리!====\n");
		printf("경험치 % d 획득!\n", player->exp);
		player->gold += (player->exp) / 6;
		printf("골드 %d G 획득!\n", player->gold);

		tryDropItem(player);

		// 레벨업 체크
		while (player->exp >= player->expToNextLevel)
		{
			player->exp -= player->expToNextLevel;
			leLevelUp(player, ghost);
		}

		Sleep(1000);
		printf("\n***현재 레벨: %d  경험치: %d***\n", player->level, player->exp);
	}
	else if (player->hp <= 0) {
		player->gold -= (int)(player->gold * 0.2);

		Sleep(1000);
		printf("귀신에게 패배했습니다...\n");
		Sleep(500);
		printf("골드의 20%를 잃었습니다...\n");
		printf("***현재 골드: %d G***", player->gold);
		Sleep(500);
		printf("경험치 % d 획득!\n", player->exp);
	}
	else {
		printf("공격 횟수를 모두 사용했습니다. 전투 종료.\n");
	}
	Sleep(2000);
	clearScreen();
}


void 마을(Player* player, Ghost* ghost) {
	int menu;

	while (1) {
		printf("\n=== 마을 ===\n");
		Sleep(500);
		printf("\n***현재 레벨: %d  경험치: %d***\n", player->level, player->exp);
		Sleep(500);
		printf("\n***현재 골드: %d G***\n", player->gold);
		Sleep(500);
		printf("\n1. 던전 탐험\n2. 인벤토리\n3. 상점\n4. 게임 종료\n");
		printf("\n선택: ");
		scanf_s("%d", &menu);

		Sleep(1000);

		if (menu == 1) {
			던전(player, ghost);
		}
		else if (menu == 2) {
			showInventory(player);
		}
		else if (menu == 3) {
			상점(player);
		}
		else {
			printf("게임을 종료합니다.\n");
			break;
		}
	}
}