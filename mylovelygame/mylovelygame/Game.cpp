#include "Game.h"

void Game::Start() {
	/*Inventory& inv = player.GetInventory();

	std::cout << "[DEBUG] 장비 추가 시도 1\n";
	SleepMs(1000);
	inv.AddItem(EquipmentItem(10, "신방울", ItemType::Weapon, 1, 100,"??", 5, 0, 0));
	std::cout << "[DEBUG] 장비 추가 완료 1\n";
	SleepMs(1000);
	inv.AddItem(EquipmentItem(13, "구슬 목걸이", ItemType::Armor, 1, 120,"??", 0, 3, 20));
	inv.AddItem(EquipmentItem(16, "영적 비녀", ItemType::Accessory, 1, 150,"??", 0, 5, 30));*/

	if (SaveManager::HasSavedGame()) {
		ClearScreen();
		TypeWriter("저장된 게임이 있습니다.\n", 40);
		TypeWriter("1. 새 게임\n", 30);
		TypeWriter("2. 불러오기\n", 30);
		TypeWriter("> ");

		int choice;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 2) {
			if (SaveManager::LoadGame(player)) {    // LoadGame은 저장된 데이터 불러오는 함수, 성공시 true 반환
				SetConsoleColor(12); // 빨간색
				TypeWriter("\n게임을 불러옵니다...\n", 30);
				SetConsoleColor(7);
			}
			else {
				SetConsoleColor(12); // 빨간색
				TypeWriter("불러오기에 실패했습니다... 새 게임을 시작합니다.\n", 30);
				SetConsoleColor(7);
				ShowIntro();
			}
		}
		else {
			ShowIntro();
		}
	}
	else {
		ShowIntro();
	}

	ShowMainMenu();
}

void Game::ShowIntro() {
	std::vector<std::string> lines;
	std::string name;
	int jobChoice;

	ClearScreen();
	TypeWriter("당신의 이름은? ");
	std::getline(std::cin, name);
	player.SetName(name);

	ClearScreen();
	TypeWriter("직업을 선택하세요\n", 40);
	TypeWriter("1. 무당\n", 30);
	TypeWriter("2. 풍수지리사\n", 30);
	TypeWriter("3. 신학생\n", 30);
	TypeWriter("> ");
	std::cin >> jobChoice;
	std::cin.ignore(); // 줄바꿈 제거

	// 유효성 검사
	if (jobChoice < 1 || jobChoice > 3) {
		TypeWriter("\n잘못된 선택입니다. 기본값으로 무당이 설정됩니다.\n\n");
		jobChoice = 1;
	}

	player.reSetJob(jobChoice);

	ClearScreen();
	SetConsoleColor(12); // 빨간색
	TypeWriter(name + "님, 반갑습니다.\n", 40);
	SetConsoleColor(7);

	TypeWriter("당신은 " + player.GetJobName() + "입니다.\n\n", 35);
	SleepMs(1500);
	ClearScreen();

	int introchoice;
	TypeWriter("인트로를 스킵하시겠습니까?\n", 40);
	TypeWriter("1. 예\n", 30);
	TypeWriter("2. 아니오\n", 30);
	TypeWriter("> ");
	std::cin >> introchoice;
	std::cin.ignore(); // 줄바꿈 제거

	if (introchoice == 1)
	{
		ClearScreen();
		return;
	}

	// 직업별 멘트 설정
	switch (jobChoice) {
	case 1:
		lines = {
			"[방울 소리가 들린다.]\n",
			"그건 어릴 적, 처음 귀신을 본 날부터 늘 따라다니던 소리였다.\n",
			"당신은 원하지 않아도 봐야만 했고, 들리지 않아도 들려왔다.\n",
			"수많은 혼이 당신을 지나쳤지만, 이번 건… 다르다.\n",
			"이건 그냥 떠도는 원혼이 아니다.\n",
			"묶여 있고, 뒤틀렸고, 풀어야만 하는 사연이다.\n",
			"할머니께서 마지막 굿을 하며 말했었다.\n",
			"“이건 니 팔자다… 이거 피하면, 다음은 니가 되겄어.”\n",
			"그 순간, 당신의 손끝에서 방울이 울렸다.\n",
			"“가라… 그 혼을 풀고 와라.”\n",
			"그리고 이제, 당신의 발밑에 그 장소가 있다.\n"
		};
		break;
	case 2:
		lines = {
			"[흙냄새가 진하게 밴 꿈을 꾸었다.]\n",
			"한 소녀가 오래된 집 앞에 서 있었다.\n",
			"그녀는 땅을 파고 있었고, 무언가를 묻었다.\n",
			"그 위에 피가 흘렀다.\n",
			"당신은 자리에서 일어나 지도를 폈다.\n",
			"붉은 선이 한 곳을 가리키고 있었다.\n",
			"그건 이상했다.\n",
			"그 장소는 당신이 아무도 말하지 않았던 ‘금기의 지점’이었다.\n",
			"풍수에서 말한다.\n",
			"**기운은 순환되어야 한다.**\n",
			"막힌 곳엔 혼이 맺히고,\n",
			"맺힌 곳엔 저주가 남는다.\n",
			"당신은 ‘흐름’을 열러 간다.\n",
			"그러나 그 흐름의 끝에, 무엇이 기다릴지는 아무도 모른다.\n"
		};
		break;
	case 3:
		lines = {
			"[당신은 잠들기 전, 기도하고 있었다.]\n",
			"하지만 오늘은 이상하게, 기도 끝에 평안이 오지 않았다.\n",
			"창밖에서, 누군가 당신의 이름을 속삭였다.\n",
			"성경책이 저절로 펼쳐졌다.\n",
			"마치, 다음 페이지를 강제로 읽히듯이.\n",
			"당신은 믿는다. 신의 뜻이 있기에.\n",
			"그러나 신은 당신에게 아직 **답을 주지 않았다.**\n",
			"지금 당신이 가는 곳은, 신조차 침묵한 장소.\n",
			"그곳엔 오래전 목숨을 잃은 이들의 기도가\n",
			"응답받지 못한 채 쌓여 있다.\n",
			"그리고 당신이 그 기도를 들어야 할 때가 왔다.\n"
		};
		break;
	}

	// 출력
	for (const auto& line : lines) {
		TypeWriter(line, 35);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();

	lines = {
		"[낡은 마을 입구 앞]\n",
		"당신이 도착하자, 마을 이장이 지친 얼굴로 당신을 맞이한다.\"\n",
		"\"드디어 오셨군.\"\n",
		"\"이 마을에서 30년 전부터 설명할 수 없는 일이 계속되고 있소\"\n",
		"\"폐가에선 울음소리가 멈추질 않고,  우물에선 밤마다 검은 손이 나온다는 말이 전해져 왔소\"\n",
		"\"아이들은 악몽에 시달리고,  어른들은 이유 없이 병들거나, 사라지기도 했소”\"\n",
		"\n그... 자... 망쳐...\n",
		"\n이장이 중얼거렸다.\n",
		"\n\"처음엔 다들 우연이라 여겼지만… 이젠 누구도 그렇게 믿지 않지요.\"\n"
		"\"그 탓인지, 젊은이들은 하나둘씩 마을을 떠나고 있소.\n"
		"\"이대로라면… 이 마을은 정말 끝장일지도 모르오.\"\n"
		"\"부디… 내 어릴적 추억이 가득한 소중한 마을을 구해주시오.\"\n"

		"\n왜인지 어딘가 낯설면서도 익숙한 기분이 든다...\n"
		"마을 사람들의 두려움이 내 마음 깊숙이 스며드는 것만 같다.\n"
		"이곳에 숨겨진 진실을 꼭 찾아야만 해.\n"
	};

	for (const auto& line : lines) {
		TypeWriter(line, 35);
		std::this_thread::sleep_for(std::chrono::milliseconds(300)); 
	}

	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();
}

void Game::ShowPlayerStatus() {
	const int hpBarWidth = 30;
	const int expBarWidth = 30;

	std::string playerName = player.GetName();
	std::string jobName = player.GetJobName();
	int currentHp = player.GetHp();
	int maxHp = player.GetMaxHp();
	int currentExp = player.GetEXP();
	int maxEXP = player.GetMaxEXP();
	int level = player.GetLevel();

	float hpRatio = static_cast<float>(currentHp) / maxHp;
	int hpFill = static_cast<int>(hpRatio * hpBarWidth);

	float expRatio = static_cast<float>(currentExp) / maxEXP;
	int expFill = static_cast<int>(expRatio * expBarWidth);

	std::cout << "===========================\n";
	std::cout << "이름: " << playerName
		<< "    직업: " << jobName << "\n";
	std::cout << "레벨: " << level << "\n";

	std::cout << "경험치: " << currentExp << " / " << maxEXP << "\n    [";
	for (int i = 0; i < expBarWidth; ++i) {
		if (i < expFill) std::cout << "=";
		else std::cout << "─";
	}
	std::cout << "]\n";

	std::cout << "체력: " << currentHp << " / " << maxHp << "\n    [";
	for (int i = 0; i < hpBarWidth; ++i) {
		if (i < hpFill) std::cout << "=";
		else std::cout << "─";
	}
	std::cout << "]\n";

	std::cout << "===========================\n\n";
}


void Game::ShowMainMenu() {
	while (true)
	{
		ClearScreen();
		ShowPlayerStatus();
		TypeWriter("메인 메뉴\n", 30);
		TypeWriter("1. 스토리 진행\n", 20);
		TypeWriter("2. 인벤토리\n", 20);
		TypeWriter("3. 기억 저장소\n", 20);
		TypeWriter("4. 상점\n", 20);
		TypeWriter("5. 저장\n", 20);
		TypeWriter("6. 종료\n", 20);
		TypeWriter("> ");

		int choice = 0;
		std::cin >> choice;
		std::cin.ignore();

		ClearScreen();
		ShowPlayerStatus();

		switch (choice) {
		case 1:
			ShowStoryMenu();
			break;
		case 2:
		{
			Inventory& inv = player.GetInventory();

			inv.ShowInventory();         // 번호 포함해서 출력
			inv.ShowEquippedItems();

			while (true) {
				TypeWriter("\n1. 아이템 사용\n 2. 아이템 착용\n", 20);
				TypeWriter("\n메뉴로 돌아가시려면 0", 20);
				TypeWriter("> ");
				
				int menuChoice = 0;
				std::cin >> menuChoice;
				std::cin.ignore();

				if (menuChoice == 0) break;

				if (menuChoice == 1) 
				{
					TypeWriter("\n사용할 아이템 번호를 입력하세요: \n", 20);
					TypeWriter("> ");

					int useNum = 0;
					std::cin >> useNum;
					std::cin.ignore();

					if (useNum == 0) continue;
					if (useNum < 1 || useNum >(int)inv.items.size()) {
						TypeWriter("잘못된 번호입니다.\n", 20);
						continue;
					}

					Item& selectedItem = inv.items[useNum - 1];
					if (selectedItem.type != ItemType::Consumable) {
						TypeWriter("이 아이템은 사용할 수 없습니다.\n", 20);
						continue;
					}

					bool used = player.UseItem(selectedItem.id);
					if (used) {
						TypeWriter("아이템을 사용했습니다.\n", 20);
					}
					else {
						TypeWriter("아이템 사용에 실패했습니다.\n", 20);
					}
				}

				else if (menuChoice == 2)
				{

					TypeWriter("\n착용할 아이템 번호를 입력하세요: \n", 20);
					TypeWriter("> ");

					int equipNum = 0;
					std::cin >> equipNum;
					std::cin.ignore();

					if (equipNum == 0) continue;
					if (equipNum < 1 || equipNum >(int)inv.items.size()) {
						TypeWriter("잘못된 번호입니다.\n", 20);
						continue;
					}

					ItemType selectedType = inv.items[equipNum - 1].type;
					if (selectedType == ItemType::Consumable) {
						TypeWriter("소비 아이템은 장착할 수 없습니다.\n", 20);
						continue;
					}

					// 번호로 아이템 찾아서 착용
					int itemId = inv.items[equipNum - 1].id;
					inv.EquipItem(itemId);

					TypeWriter("아이템이 장착되었습니다.\n", 20);
				}
			}
			break;
		}
		case 3:
			player.ShowMemoryStorage();
			break;
		case 4:
			ShowShopItems(player);
			break;
		case 5:
			SaveManager::SaveGame(player);
			ClearScreen();
			TypeWriter("저장 완료!!\n", 40);
			break;
		case 6:
			TypeWriter("게임을 종료합니다.\n");
			return;
		default:
			TypeWriter("잘못된 선택입니다. 다시 시도하세요.\n");
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		}
	}
}

void Game::ShowStoryMenu() {
	std::vector<std::string> chapterTitles =
	{
		"부서진 묘비 조각\n",
		"녹슨 족쇄\n",
		"낡은 손목시계\n",
		"분홍색 머리핀\n",
		"어머니의 일기장\n",
		"낡은 카세트 테이프\n"
	};

	TypeWriter("== 기억의 조각 ==\n", 30);

	int unlocked = player.GetUnlockedChapter();
	int i = 0;
	while (true)
	{
		for (i = 0; i < chapterTitles.size(); ++i)
		{
			std::string line = "<chapter " + std::to_string(i + 1) + "> ";
			if (i < unlocked)
			{
				line += chapterTitles[i] + "\n";
			}
			else
			{
				line += "??? (잠김)\n";
			}
			TypeWriter(line, 5);  // 각 라인 출력
		}

		TypeWriter("\n메뉴로 돌아가시려면 0\n", 10);
		TypeWriter("\n진행할 챕터 번호를 입력하세요: \n", 10);
		TypeWriter("> ");
		int choice;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 0)
		{
			break;
		}

		if (choice < 1 || choice > 6) {
			TypeWriter("잘못된 번호입니다.\n", 40);
			ClearScreen();
			continue;
		}

		if (player.GetUnlockedChapter() < choice) {
			TypeWriter("아직 잠긴 챕터입니다.\n", 40);
			ClearScreen();
			continue;
		}

		ClearScreen();
		StartChapter(choice);
		break;
	}

}


void Game::StartChapter(int chapterNumber)
{
	bool Wahl = false;
	switch (chapterNumber)
	{
	case 1:
		chapter1.ShowIntro();
		chapter1.Warn();
		bool backToMenu = false;

		while (!backToMenu)
		{
			chapter1.ExploreMap();
			int choice;
			std::cin >> choice;
			std::cin.ignore();

			switch (choice) {
			case 0:
				// 메뉴로 돌아가기 처리
				std::cout << "\n메인 메뉴로 돌아갑니다...\n";
				backToMenu = true;
				break;
			case 1:
				ClearScreen();
				Wahl = minigame.TriggerminiGame();
				//미니 게임 후 bool 형태로 전투할지말지 반환

				if (Wahl == true)
				{
					Battle();
				}
				ClearScreen();
				// 관리인 오두막 조사 함수
				// 작은 묘실 조사 함수
				chapter1.ExploreGrave(); 
				continue;
			case 2:
			{
				ClearScreen();
				Wahl = minigame.TriggerminiGame();
				//미니 게임 후 bool 형태로 전투할지말지 반환

				if (Wahl == true)
				{
					Battle();
				}
				ClearScreen();
				// 관리인 오두막 조사 함수
				chapter1.ExploreHut();
				continue;
			}
			case 3:
				ClearScreen();
				Wahl = minigame.TriggerminiGame();
				//미니 게임 후 bool 형태로 전투할지말지 반환

				if (Wahl == true)
				{
					Battle();
				}
				ClearScreen();
				// 관리인 오두막 조사 함수
				// 제단 조사 함수
				chapter1.ExploreAltar();
				continue;
			case 4:
				ClearScreen();
				Wahl = minigame.TriggerminiGame();
				//미니 게임 후 bool 형태로 전투할지말지 반환

				if (Wahl == true)
				{
					Battle();
				}
				ClearScreen();
				// 관리인 오두막 조사 함수
				// 마당 조사 함수
				chapter1.ExploreYard();
				continue;
			default:
				std::cout << "\n잘못된 입력입니다. 다시 선택하세요.\n";
				continue;
			}
		}
		if (chapter1.GetHasFoundClue())
		{
			player.AddClue("관리인의 일지 - '묘지를 파헤친 여자가 저주의 시작이다.'");
		}
		if (chapter1.GetHasFoundKeepsake())
		{
			player.AddKeepsake("부서진 옥 팔찌 - 옥 팔찌 조각에서 희미하게 느껴지는 원한과 저주의 기운.");
		}
		break;
		
	}
}

void Game::Battle()
{
	int JobNumber = player.GettJob();
	int maxAttacks = 10;        // 최대 공격 횟수 제한
	int attacksLeft = maxAttacks;

	bool isFearful = false;
	bool isGhostFearful = false;
	bool isCursed = false;
	bool isGhostCursed = false;
	int isCursedTurns = 0;      // 3턴 지속 저주용
	int isghostCursedTurns = 0; // 귀신 저주 피해용
	int isFearedTurns = 0;      // 1턴 봉인용 (플레이어 공포)
	int isghostFearedTurns = 0; // 귀신 봉인용

	int secSkillMaxUse = 2;
	int secSkillUsed = 2;

	ghost = Ghost::GetRandomGhost();
	int tempGhostHp = ghost.GetHp();

	ClearScreen();
	ShowPlayerStatus();

	if (JobNumber == 1)
	{
		tempGhostHp = (tempGhostHp * 9) / 10;
		TypeWriter("신령님의 힘으로 귀신의 체력이 다소 감소했습니다!\n", 5);
		SleepMs(500);
	}

	int totalExp = 0;
	int totalGold = 0;

	while (player.GetHp() > 0 && !ghost.IsDead() && attacksLeft > 0)
	{
		ClearScreen();

		int turn = maxAttacks - attacksLeft + 1;
		ShowPlayerStatus();

		std::cout << "===========================\n";
		std::cout << "[" << turn << "번째 턴]\n\n";
		std::cout << "귀신 체력: " << tempGhostHp << "/" << ghost.GetHp() << "  (" << GetStatusString(isGhostFearful, isGhostCursed) << ")\n";
		std::cout << "===========================\n\n";

		// 플레이어 상태 효과 처리 (공포, 저주)
		if (isFearedTurns > 0) {
			TypeWriter("당신은 공포에 사로잡혀 1턴 동안 행동할 수 없습니다!\n", 5);
			isFearedTurns--;
			attacksLeft--;
		}
		else
		{
			TypeWriter("1. 공격한다\n", 5);
			TypeWriter("2. 아이템 사용\n", 5);
			TypeWriter(">", 5);

			int choice = 0;
			std::cin >> choice;

			if (choice == 1)
			{
				std::cout << "\n스킬 목록:\n";
				const std::vector<Skill>& skills = player.GetSkillSet();

				for (size_t i = 0; i < skills.size(); ++i) {
					std::cout << i + 1 << ". " << skills[i].name;
					if (i == 1) {
						std::cout << " [" << secSkillUsed << "/" << secSkillMaxUse << "]";
					}
					std::cout << "\n";  // 꼭 줄바꿈
				}
				std::cout.flush();  // 출력 버퍼 비우기

				TypeWriter("사용할 스킬 번호를 입력하세요: \n", 5);
				TypeWriter("> ", 5);
				std::cout.flush();  // 필요하면 플러시

				int skillChoice;
				std::cin >> skillChoice;
				skillChoice -= 1;

				if (skillChoice < 0 || skillChoice >= (int)skills.size()) {
					TypeWriter("\n잘못된 스킬 번호입니다.\n", 5);
					continue;
				}

				if (skillChoice == 1 && secSkillUsed <= 0) {
					TypeWriter("\n이 스킬은 더 이상 사용할 수 없습니다.\n", 5);
					continue;
				}

				bool skillFailed = false;
				bool criticalHit = false;
				int Damage = 0;
				int ghostDef = ghost.GetDef();

				if (JobNumber == 3)
				{
					int randVal = std::rand() % 100;

					if (randVal < 15)
					{
						skillFailed = true;
						Damage = 0;
						TypeWriter("\n[미숙함]\n 스킬 사용에 실패했습니다!\n", 5);
					}
					else
					{
						randVal = std::rand() % 100;
						if (randVal < 5)
						{
							criticalHit = true;
							Damage += 999;
							TypeWriter("\n[신의 가호]\n 엄청난 피해를 입혔습니다!\n", 5);
						}
					}
				}

				if (!skillFailed)
				{
					switch (skillChoice)
					{
					case 0:
					{
						const std::string& skillName = player.GetSkillSet()[0].name;
						Damage += player.Attack(0, ghostDef, 1.0);
						TypeWriter("\n" + skillName + "을 사용했습니다! (" + std::to_string(Damage) + " 데미지)\n", 5);
						break;
					}
					case 1:
					{
						const std::string& skillName = player.GetSkillSet()[1].name;
						Damage += player.Attack(0, ghostDef, 0.8);
						TypeWriter("\n" + skillName + "을 사용했습니다! (" + std::to_string(Damage) + " 데미지)\n", 5);
					}
						if (JobNumber == 1)
						{
							isghostCursedTurns = 3;
							TypeWriter("귀신이 신령님의 신성한 힘에 의해 3턴 동안 피해를 입습니다!\n", 5);
						}
						else if (JobNumber == 2)
						{
							isghostFearedTurns = 1;
							TypeWriter("귀신이 봉인되어 1턴 동안 행동하지 못합니다!\n", 5);
						}
						else if (JobNumber == 3)
						{
							int healAmount = Damage / 2;
							int newHp = player.GetHp() + healAmount;
							if (newHp > player.GetMaxHp()) newHp = player.GetMaxHp();
							player.SetHp(newHp);
							TypeWriter("체력을 " + std::to_string(healAmount) + " 회복했습니다!\n", 5);
						}
						secSkillUsed--;
						break;

					default:
						TypeWriter("\n해당 스킬은 아직 구현되지 않았습니다.\n", 5);
						break;
					}
				}

				tempGhostHp -= Damage;
				if (tempGhostHp < 0) tempGhostHp = 0;

				totalExp += Damage;
				
				attacksLeft--;
			}
			else if (choice == 2)
			{
				std::cout << "\n[아이템 목록]\n";
				Inventory& inv = player.GetInventory();
				inv.ShowInventory();

				while (true) 
				{
					TypeWriter("\n메뉴로 돌아가시려면 0\n", 10);
					TypeWriter("\n사용할 아이템 번호를 입력하세요: ", 10);
					TypeWriter("> ", 10);
					int itemNum = 0;
					std::cin >> itemNum;
					std::cin.ignore();

					if (itemNum == 0) continue;

					if (itemNum < 1 || itemNum >(int)inv.items.size()) {
						TypeWriter("잘못된 번호입니다.\n", 20);
						continue;
					}

					Item& selected = inv.items[itemNum - 1];

					if (selected.type != ItemType::Consumable) {
						TypeWriter("이 아이템은 사용할 수 없습니다.\n", 20);
						continue;
					}

					bool used = player.UseItem(selected.id);

					if (used) {
						TypeWriter("아이템을 사용했습니다.\n", 20);
					}
					else {
						TypeWriter("아이템 사용에 실패했습니다.\n", 20);
					}

					break;
				}

			}
			else
			{
				TypeWriter("\n잘못된 선택입니다. 다시 입력하세요.\n", 5);
				continue;
			}
		}

		// 저주 피해 처리 (3턴 지속)
		if (isCursedTurns > 0) {
			int curseDamage = player.GetAtk() / 10;  // 플레이어 공격력의 10%
			if (curseDamage < 1) curseDamage = 1;

			player.SetHp(player.GetHp() - curseDamage);
			TypeWriter("\n저주 피해로 " + std::to_string(curseDamage) + "의 피해를 입었습니다!\n", 5);
			isCursedTurns--;
		}

		// 귀신 저주 피해 처리
		if (isghostCursedTurns > 0)
		{
			int curseDamage = player.GetAtk() / 10;
			if (curseDamage < 1) curseDamage = 1;

			tempGhostHp -= curseDamage;
			if (tempGhostHp < 0) tempGhostHp = 0;

			TypeWriter("\n귀신이 저주로 인해 " + std::to_string(curseDamage) + "의 피해를 입었습니다!\n", 5);
			isghostCursedTurns--;
	
		}

		int DamageTaken = 0;
		int playerDef = player.GetTotalDef();

		if (isghostFearedTurns > 0)
		{
			TypeWriter("\n귀신은 봉인되어 아무 행동도 하지 못했습니다!\n", 5);
			isghostFearedTurns--;
		}
		else
		{
			DamageTaken = ghost.Attack(JobNumber, playerDef);

			TypeWriter("\n귀신의 공격! 당신은 " + std::to_string(DamageTaken) + "의 피해를 입었습니다!\n", 5);

			// 귀신 공격 후 확률로 플레이어 상태 이상 적용
			int curseChance = std::rand() % 100;
			int fearChance = std::rand() % 100;

			if (fearChance < 10 && isFearedTurns == 0)
			{
				isFearedTurns = 1;
				TypeWriter("\n귀신의 공포 공격! 당신은 1턴 동안 행동할 수 없습니다!\n", 5);
			}

			if (curseChance < 15 && isCursedTurns == 0)
			{
				isCursedTurns = 3;
				TypeWriter("\n귀신의 저주! 당신은 3턴 동안 피해를 입습니다!\n", 5);
			}
		}

		if (DamageTaken > 0)
		{
			int newHp = player.GetHp() - DamageTaken;
			player.SetHp(newHp);
		}

		SleepMs(1000);
		if (tempGhostHp <= 0) break;  // 승리
		if (player.GetHp() <= 0) break;  // 패배
	}

	player.SetEXP(player.GetEXP() + totalExp);
	totalGold = (totalExp / 2);

	if (tempGhostHp <= 0)
	{
		TypeWriter("\n귀신을 물리쳤습니다! 승리했습니다!\n", 5);  // ✅ 승리 메시지
		player.AddGold(player.GetGold() + totalGold);
		TypeWriter("\n총 경험치 " + std::to_string(totalExp) + " 획득했습니다!\n", 5);
		TypeWriter("총 골드 " + std::to_string(totalGold) + " 획득했습니다!!\n", 5);
		if (player.GetEXP() >= player.GetMaxEXP()) 
		{
			player.LevelUp();
		}
	}
	else if (player.GetHp() <= 0 || (attacksLeft == 0 && tempGhostHp > 0))
	{
		TypeWriter("\n당신은 쓰러졌습니다... 패배했습니다.\n", 5); 

		TypeWriter("\n총 경험치 " + std::to_string(totalExp) + " 획득했습니다!\n", 5);
		int goldLost = player.GetGold() / 10;
		player.SpendGold(goldLost);
		TypeWriter("골드 " + std::to_string(goldLost) + "를 잃었습니다.\n", 5);

		if (player.GetEXP() >= player.GetMaxEXP())
		{
			player.LevelUp();
		}

		int hpRestore = player.GetMaxHp() / 10;
		if (hpRestore < 1) hpRestore = 1;  // 최소 1은 회복
		player.SetHp(hpRestore);
		TypeWriter("\n당신은 가까스로 정신을 차리고 돌아왔습니다.", 5);
	}

	SleepMs(1000);
}
