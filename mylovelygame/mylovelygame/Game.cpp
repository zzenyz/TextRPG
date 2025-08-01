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

	GameLoop();
}

void Game::ShowIntro() {
	std::vector<std::string> lines;
	std::string name;
	int jobChoice;

	ClearScreen();
	TypeWriter("당신의 이름은? ");
	std::getline(std::cin, name);
	player.SetName(name);

	//ClearScreen();
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


void Game::GameLoop() {
	ShowMainMenu();
}

void Game::ShowMainMenu() {
	while (true)
	{
		ClearScreen();
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

		switch (choice) {
		case 1:
			ShowStoryMenu();
			break;
		case 2:
		{
			Inventory& inv = player.GetInventory();


			ClearScreen();
			inv.ShowInventory();         // 번호 포함해서 출력
			inv.ShowEquippedItems();

			while (true) {
				int inputNum = 0;
				TypeWriter("\n메뉴로 돌아가시려면 0", 20);
				TypeWriter("\n착용할 아이템 번호를 입력하세요:", 20);
				TypeWriter("> ");

				std::cin >> inputNum;
				std::cin.ignore();

				if (inputNum == 0) break;  // 0 입력 시 메뉴로 돌아감

				if (inputNum < 1 || inputNum >(int)inv.items.size()) {
					TypeWriter("잘못된 번호입니다. 다시 시도하세요.\n", 20);
					continue;
				}

				ItemType selectedType = inv.items[inputNum - 1].type;
				if (selectedType == ItemType::Consumable) {
					TypeWriter("소비 아이템은 장착할 수 없습니다.\n", 20);
					continue;
				}

				// 번호로 아이템 찾아서 착용
				int itemId = inv.items[inputNum - 1].id;
				inv.EquipItem(itemId);

				TypeWriter("아이템이 장착되었습니다.\n", 20);
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
				// 작은 묘실 조사 함수
				//ExploreGrave(); // 이 함수는 따로 정의해야 함
				continue;
			case 2:
				ClearScreen();
				minigame.TriggerminiGame();
				//미니 게임 후 bool 형태로 전투할지말지 반환
				
				Battle();
				
				ClearScreen();
				// 관리인 오두막 조사 함수
				chapter1.ExploreHut();
				continue;
			case 3:
				// 제단 조사 함수
				//ExploreAltar();
				continue;
			case 4:
				// 마당 조사 함수
				//ExploreYard();
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
		break;
		
	}
}

void Game::Battle()
{
	//뭐라 씨부리기

	int maxAttacks = 10;        // 최대 공격 횟수 제한
	int attacksLeft = maxAttacks;
	bool isFearful = false;
	bool isGhostFearful = false;
	bool isCursed = false;
	bool isGhostCursed = false;


	ghost = Ghost::GetRandomGhost();
	int tempGhostHp = ghost.GetHp();

	if (player.GettJob() == 1)
	{
		tempGhostHp = (tempGhostHp * 9) / 10;
		TypeWriter("신령님의 힘으로 귀신의 체력이 다소 감소했습니다!\n", 5);
	}

	while (player.GetHp() > 0 && !ghost.IsDead() && attacksLeft > 0)
	{
		ClearScreen();

		int turn = 11 - attacksLeft;

		std::cout << "===========================\n";
		std::cout << turn << "번째 턴\n";
		std::cout << "내 체력: " << player.GetHp() << "/" << player.GetMaxHp() << "  (" << GetStatusString(isFearful, isCursed) << ")\n";
		std::cout << "귀신 체력: " << tempGhostHp << "/" << ghost.GetHp() << "  (" << GetStatusString(isGhostFearful, isGhostCursed) << ")\n";
		std::cout << "===========================\n\n";

		std::cout << "스킬\n";
		const std::vector<Skill>& skills = player.GetSkillSet();
		for (size_t i = 0; i < skills.size(); ++i) {
			std::cout << i + 1 << ". " << skills[i].name << "\n";
		}

		
		TypeWriter("1. 공격한다\n", 5);
		TypeWriter("2. 아이템 사용\n", 5);
		TypeWriter(">", 5);

		int choice = 0;
		std::cin >> choice;

		switch (choice) 
		{
		case 1:
			std::cout << "스킬\n";
			const std::vector<Skill>& skills = player.GetSkillSet();
			for (size_t i = 0; i < skills.size(); ++i) {
				std::cout << i + 1 << ". " << skills[i].name << "\n";
			}

			TypeWriter("사용할 스킬 번호를 입력하세요.");
			std::cout << '>\n';

			int skillChoice;
			std::cin >> skillChoice;
			skillChoice -= 1;


			break;
		case 2:
			std::cout << "\n아이템\n";
			player.GetInventory().ShowInventory();

			break;
		default:
			TypeWriter("잘못된 선택입니다. 다시 입력하세요.\n", 5);
			break;
		}

	}

		// 플레이어 공격

		int playerAtk = player.GetTotalAtk();
		int ghostDef = ghost.GetDef();
		int damageToGhost = CalculateDamage(playerAtk, ghostDef);
		

		ghost.SetHp(ghost.GetHp() - damageToGhost);

}

