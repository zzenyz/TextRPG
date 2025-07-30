#include "player.h"

void initPlayer(Player* player) {
	player->level = 1;
	player->exp = 0;
	player->expToNextLevel = 100;

	player->hp;       // 초기 체력값 예시
	player->maxHp;
	player->atk;       // 초기 공격력 예시

	player->playerStunTurn = 0;
	player->ghostAttackDebuffTurn = 0;
	player->buffAttackTurn = 0;   // 이 부분 추가
	player->ghostDotTurn = 0;

	player->equippedItems.weapon = NULL;
	player->equippedItems.armor = NULL;
	player->equippedItems.accessory = NULL;


	player->gold = 0;

	// 인벤토리 초기화
	player->inventory.count = 0;
	player->inventory.maxSlots = 5;  // 기본 슬롯 수

	switch (player->job) {
	case 무당:
		strcpy(player->jobName, "무당");
		player->maxHp = 100;
		player->hp = player->maxHp;
		player->atk = 25;
		//  player->dodgeRate = 20;
		 // player->statusResist = 50;
		break;

	case 풍수지리사:
		strcpy(player->jobName, "풍수지리사");
		player->maxHp = 110;
		player->hp = player->maxHp;
		player->atk = 20;
		// player->dodgeRate = 0;
	  //   player->statusResist = 0;
		break;

	case 신학생:
		strcpy(player->jobName, "신학생");
		player->maxHp = 120;
		player->hp = player->maxHp;
		player->atk = 15;
		//player->dodgeRate = 0;
	   // player->statusResist = 0;
		break;

	default:
		// 잘못된 값일 때 무당 기본값 세팅
		strcpy(player->jobName, "무당");
		player->maxHp = 100;
		player->hp = player->maxHp;
		player->atk = 25;
		// player->dodgeRate = 20;
	   //  player->statusResist = 50;
		player->job = 무당;  // 무당으로 초기화
		break;
	}
}

//==========스킬 초기화===========
void initSkillsForPlayer(Player* player) {
	if (player->job == 1) {  // 무당
		player->skillSet[0] = (Skill){ "부적 투척", "기본 데미지" };
		player->skillSet[1] = (Skill){ "강신의 춤", "중간 데미지 + 3턴 동안 지속 데미지" };
		
	}
	else if (player->job == 2) {  // 풍수지리사
		player->skillSet[0] = (Skill){ "지맥 붕괴", "기본 데미지" };
		player->skillSet[1] = (Skill){ "풍수 봉인", "강한 데미지 + 1턴 동안 귀신 봉인" };
		
	}
	else if (player->job == 3) {  // 신학생
		player->skillSet[0] = (Skill){ "성수 투척", "기본 데미지" };
		player->skillSet[1] = (Skill){ "은총의 일격", "중간 데미지 + 피해량 50% 회복" };
		
	}
}



int 무당Attack(int skill, Player* player) {
	int damage = 0;

	if (skill == 1) {
		damage = player->atk + rand() % 6; // 5~15
		printf("🧿 부적 투척! 기본 공격을 가합니다. \n(%d의 데미지)\n", damage);
	}
	else if (skill == 2) 
	{
			damage = (player->atk * 1.1) + rand() % 6;
			printf("👻 강신의 춤! 신령님의 신묘한 힘으로 공격을 가합니다. \n(%d의 데미지)\n", damage);
			Sleep(500);
			player->ghostDotTurn = 3;  // 3턴 동안 지속 데미지 효과 부여
			printf("👻 강신의 춤! 신령님의 도움으로 귀신에게 3턴 동안 지속 피해를 입힙니다!\n");
	}

	Sleep(500);
	return damage;
}

int 풍수Attack(int skill, Player* player) {
	int damage = 0;
	int debuffChance;

	if (skill == 1) {
		damage = player->atk + rand() % 6; // 8~13
		printf("🌍 지맥 붕괴! 기본 공격을 가합니다. \n(%d의 데미지)\n", damage);
	}
	else if (skill == 2) {
		damage = (player->atk * 1.1) + rand() % 6; // 12~20
		printf("🌀 풍수 봉인! 귀신을 공격합니다. \n(%d의 데미지)\n", damage);
		debuffChance = rand() % 100;
		if (debuffChance < 50) 
		{
			player->ghostAttackDebuffTurn = 1; // 다음 턴 50% 공격력 감소
			printf("\n👁️‍🗨️ 디버프 성공! 귀신의 공격력이 1턴간 감소합니다!\n");
		}
		else 
		{
			printf("\n💨 디버프 실패! 귀신은 그대로 공격합니다.\n");
		}
	}

	Sleep(500);
	return damage;
}

int 신학생Attack(int skill, Player* player) {
	int damage = 0;

	// 15% 확률로 주문 실패 (모든 스킬 공통)
	int failChance = rand() % 100;
	if (failChance < 30) {
		printf("신학생의 주문 실패! 아무 일도 일어나지 않았다...\n");
		return -1;
	}

	// 5% 확률로 강력한 주문 발동 (모든 스킬 공통, 실패하지 않았을 경우만)
	int strongChance = rand() % 100;
	if (strongChance < 10) {
		damage = 999;
		printf("신학생의 강력한 주문 발동! 신의 심판이 내려졌다! ");
		return damage;
	}

	// 일반 공격 데미지
	if (skill == 1) {
		// 성수 투척: 10~19
		damage = player->atk + rand() % 6;
		printf("성수 투척! 기본 공격을 가합니다. \n(%d의 데미지)\n", damage);
	}
	else if (skill == 2) {
		// 은총의 일격: 20~34
		damage = (player->atk * 1.1) + rand() % 6;
		printf("은총의 일격! 기본 공격을 가합니다. \n(%d의 데미지)\n", damage);
		int healAmount = damage / 2;
		player->hp += healAmount;
		if (player->hp > player->maxHp) player->hp = player->maxHp;
		printf("\n🙏 피해량의 50%%만큼 회복! (+%d HP)\n", healAmount);
	}

	return damage;
}


//==============레벨업 함수================

void leLevelUp(Player* player, Ghost* ghost) {
	player->level++;
	player->expToNextLevel *= 1.3;

	// 능력치 강화 예시
	player->maxHp *= 1.1;
	player->atk *= 1.05;
	player->hp = player->maxHp;

	if (player->level == 2)
	{
		printf("\n🎉 레벨 2가 되었습니다!\n");
		Sleep(500);
		printf("\n지금부터 %s를 사용할 수 있습니다.\n", player->skillSet[1].name);
		printf(" - %s: %s\n", player->skillSet[1].name, player->skillSet[1].desc);
	}

	if (player->level == 3) {
		printf("\n🎉 레벨 3이 되었습니다! \n직업 전용 무기를 획득했습니다!\n");

		// 직업별 장비 지급
		int jobIndex = player->job; //무당=1, 풍수지리사=2, 신학생=3
		player->equippedItems.weapon = &equipmentList[jobIndex-1];

		printf("장착한 무기: %s\n", player->equippedItems.weapon->name);
		printf(" - 설명: %s\n", player->equippedItems.weapon->desc);
	}

	// 인벤토리 슬롯 확장 (레벨 5마다 +3칸)
	if (player->level % 4 == 0) {
		player->inventory.maxSlots += 3;
		printf("\n🎉 레벨 3이 되었습니다! \n📦 인벤토리 슬롯이 확장되었습니다! 현재 슬롯: %d칸\n", player->inventory.maxSlots);
	}

	ghost->maxHp = (int)(ghost->maxHp * 1.15);
	ghost->atk = (int)(ghost->atk * 1.1);  // 👈 귀신 공격력 증가
	ghost->hp = ghost->maxHp;

	printf("\n🎉 레벨업! 현재 레벨: %d | 경험치: %d | 다음 레벨까지: %d\n", player->level, player->exp, player->expToNextLevel);
	printf("❤️ 체력: %d | 💪 공격력: %d\n", player->hp, player->atk);
	Sleep(1000);
}
