#include "Chapter2.h"

void Chapter2::ShowIntro()
{
	int introchoice;
	TypeWriter("인트로를 스킵하시겠습니까?\n", 40);
	TypeWriter("1. 예\n", 30);
	TypeWriter("2. 아니오\n", 30);
	TypeWriter("> ");
	std::cin >> introchoice;
	std::cin.ignore();

	if (introchoice == 1)
	{
		ClearScreen();
		return;
	}

	std::vector<std::string> lines = {
		"[폐교도소 입구]\n",
		"\n지도의 표시를 따라 폐허가 된 교도소 앞에 도착했다.\n",
		"\n철문은 녹슬어 있었지만, 누군가 최근에 강제로 연 흔적이 남아 있다...\n",
		"\n당신은 문틈 사이로 조심스럽게 안으로 들어선다.\n",
		"\n안은 조용했다. 지나치게... 불길할 만큼.\n",
		"\n기억이 어렴풋이 떠오른다.\n피를 뒤집어쓴 누군가가 쇠창살 너머로 손을 뻗고 있었다.\n",
		"\n“우린… 아무 잘못도 없었어…”\n",
		"\n그 목소리가 마치 바로 곁에서 들리는 것만 같다.\n",
		"\n당신은 가볍게 숨을 내쉬고, 깊은 어둠 속으로 발걸음을 옮긴다.\n"
	};

	for (const auto& line : lines) {
		TypeWriter(line, 30);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	std::cin.ignore();
	ClearScreen();

	std::vector<std::string> warn = {
		"========================================\n",
		"[Chapter 2]\n\n",
		"이곳은 과거 수많은 죄수들이 사라졌다는 전설이 있는 장소입니다.\n\n",
		"그러나 단순한 전설이 아닙니다. 일부는 진실이었고, 일부는 은폐되었습니다.\n\n",
		"- 장소를 조사하며 '단서'와 '유품'을 찾으세요.\n",
		"- 진실은, 드러내기보다 숨겨지기 위해 존재합니다.\n",
		"- 무언가가… 당신을 지켜보고 있습니다.\n\n",
		"※ 철저한 준비 없이 돌아다니지 마세요.\n",
		"========================================\n"
	};

	for (const auto& line : warn)
	{
		TypeWriter(line, 10);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	std::cin.ignore();
	ClearScreen();

}


void Chapter2::ExploreMap()
{
	std::vector<std::string> lines = {
		"========================================\n",
		"[감옥 조사 지도]\n\n",
		"지도의 낡은 모서리에 네 곳이 표시되어 있다.\n\n",
		"  1. 독방            - \"이 방에 있던 죄수는 매일 똑같은 악몽을 꿨어.\"\n",
		"  2. 지하 고문실      - \"누구도 가면 돌아오지 못했어.\"\n",
		"  3. 교도소장실        - \"그는 감시 기록을 혼자만 봤다고 하지.\"\n",
		"  4. 감시탑           - \"맨 위층엔 누군가 살던 흔적이 남아 있었어.\"\n\n",
		"메뉴로 돌아가시려면 0\n",
		"조사할 장소를 선택하세요: \n",
		"> "
	};

	for (const auto& line : lines)
	{
		TypeWriter(line, 5);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

void Chapter2::ExploreCell()
{
	bool hasKeepsake = false;
	int choice;

	while (true) 
	{
		if (battleCooldown > 0) {
			battleCooldown--;
		}
		if (battleCooldown == 0 && rand() % 10 < 7)
		{
			Setghostcomesout(true);
			battleCooldown = 3;
			return;
		}

		ClearScreen();
	
		std::vector<std::string> intro = {
			"[독방]\n\n",
			"철창 안은 축축하고 어두웠다.\n",
			"조사 가능한 곳:\n",
			"  1. 철창\n",
			"  2. 바닥 틈\n",
			"  3. 벽 낙서\n",
			"\n메뉴로 돌아가시려면 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		std::cin.ignore();
		system("cls");

		switch (choice) {
		case 1:
			TypeWriter("[철창]\n\n", 10);
			TypeWriter("손자국과 녹슨 핏자국이 겹겹이 묻어 있다.\n", 10);
			TypeWriter("문을 열기 위해 발버둥쳤던 흔적일까…\n", 10);
			break;

		case 2:
			if (!hasKeepsake) {
				TypeWriter("[바닥 틈]\n\n", 10);
				TypeWriter("바닥 틈에서 낡고 녹슨 수갑이 발견된다.\n", 10);
				TypeWriter("표면엔 말라붙은 핏자국이 가득하다.\n", 10);
				TypeWriter("(유품 획득: 녹슨 수갑)\n", 10);
				hasKeepsake = true;
				SetKeepsakeFound();
			}
			else {
				TypeWriter("[바닥 틈]\n\n", 10);
				TypeWriter("더 이상 눈에 띄는 것은 없다.\n", 10);
			}
			break;

		case 3:
			TypeWriter("[벽 낙서]\n\n", 10);
			TypeWriter("벽에 희미하게 긁힌 글자가 보인다.\n", 10);

			SetConsoleColor(12);
			TypeWriter("\"나는... 없어질 거...\"\n", 10);
			SetConsoleColor(7);

			TypeWriter("등골이 오싹해진다.\n", 10);
			break;

		case 0:
			return;

		default:
			TypeWriter("잘못된 입력입니다.\n", 10);
			break;
		}

		TypeWriter("\n", 5);
		system("pause");
		ClearScreen();
	}
}


void Chapter2::ExploreTortureRoom()
{
	int choice;
	
	while (true) {

		if (battleCooldown > 0) {
			battleCooldown--;
		}
		if (battleCooldown == 0 && rand() % 10 < 7)
		{
			Setghostcomesout(true);
			battleCooldown = 3;
			return;
		}

		ClearScreen();

		std::vector<std::string> intro = {
			"[지하 고문실]\n\n",
			"습기와 곰팡이 냄새가 진동한다.\n",
			"조사 가능한 곳:\n",
			"  1. 고문 도구\n",
			"  2. 바닥\n",
			"  3. 벽 틈\n",
			"\n메뉴로 돌아가시려면 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		std::cin.ignore();
		system("cls");

		std::vector<std::string> lines;

		switch (choice) {
		case 1:
			lines = {
				"[고문 도구]\n\n",
				"녹슬고 뾰족한 도구들이 널브러져 있다.\n",
				"누군가는 이걸로 삶의 끝을 맞았을지도 모른다.\n"
			};
			break;
		case 2:
			lines = {
				"[바닥]\n\n",
				"피가 말라붙어 굳어 있다.\n",
				"얼마나 많은 이가 이곳을 거쳐 갔을까…\n"
			};
			break;
		case 3:
			TypeWriter("[벽]\n\n", 10);
			TypeWriter("벽에 손을 대자 차가운 감촉이 전해진다.\n", 10);

			if (bossAwakened) 
			{
				TypeWriter("비밀 공간으로 통하는 벽은 이미 열려 있다.\n", 10);
				TypeWriter("하지만 그 안은 텅 비어 있고, 싸늘한 기운만 남아 있다.\n", 10);
			}
			else
			{
				TypeWriter("어딘가에서 바람이 새어나오는 소리가 들린다...\n", 10);
				TypeWriter("벽이 천천히 움직이며 비밀 공간으로 이어지는 통로가 열린다!\n", 10);

				SetConsoleColor(12); // 붉은색 시작
				TypeWriter("그 순간, 무언가가 당신을 노린다!\n", 10);
				SetConsoleColor(7); // 색 원상복구

				bossAwakened = true;
				system("pause");
				return;
			}
			break;
		case 0:
			return;
		default:
			lines = { "잘못된 입력입니다.\n" };
			break;
		}

		for (const auto& line : lines) {
			TypeWriter(line, 10);
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		TypeWriter("\n", 5);
		system("pause");
		ClearScreen();
	}
}

void Chapter2::ExploreWardenOffice()
{
	int choice;
	while (true) 
	{
		if (battleCooldown > 0) {
			battleCooldown--;
		}
		if (battleCooldown == 0 && rand() % 10 < 7)
		{
			Setghostcomesout(true);
			battleCooldown = 3;
			return;
		}

		ClearScreen();

		std::vector<std::string> intro = {
			"[교도소장실]\n\n",
			"서랍과 문서들로 가득한 방. 조용히 먼지가 내려앉아 있다.\n",
			"조사 가능한 곳:\n",
			"  1. 서랍\n",
			"  2. 책상 위 문서\n",
			"  3. 벽걸이 캐비닛\n",
			"\n메뉴로 돌아가시려면 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		std::cin.ignore();
		system("cls");

		std::vector<std::string> lines;

		switch (choice) {
		case 1:
			lines = {
				"[서랍]\n\n",
				"비어있다. 서류는 이미 사라진 지 오래다.\n"
			};
			break;
		case 2:
			if (!clueFound1)
			{
				lines = {
				"[책상 위 문서]\n\n",
				"찢어진 종이가 여기저기 흩어져 있다.\n",
				"몇몇 조각에서는 희미하게 글자가 보인다.\n",
				"\"...죄수번호 2719... 조건... 부합\"\n",
				"하지만 대부분은 알아볼 수 없다.\n",
				"(읽기 어려운 문서 조각)\n"
				};
				SetClue1Found();
			}
			else 
			{
				lines = {
					"[책상 위 문서]\n\n",
					"이미 조사한 문서 조각이다.\n"
				};
			}
			break;
		case 3:
			lines = {
				"[벽걸이 캐비닛]\n\n",
				"열쇠가 필요해 보인다. 열 수 없다.\n"
			};
			break;
		case 0:
			return;
		default:
			lines = { "잘못된 입력입니다.\n" };
			break;
		}

		for (const auto& line : lines) {
			TypeWriter(line, 10);
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		TypeWriter("\n", 5);
		system("pause");
		ClearScreen();
	}
}

void Chapter2::ExploreWatchtower()
{
	int choice;
	while (true)
	{
		if (battleCooldown > 0) {
			battleCooldown--;
		}
		if (battleCooldown == 0 && rand() % 10 < 7)
		{
			Setghostcomesout(true);
			battleCooldown = 3;
			return;
		}

		ClearScreen();

		std::vector<std::string> intro = {
			"[감시탑]\n\n",
			"낡은 계단을 오르자, 먼지가 쌓인 감시 공간이 나온다.\n",
			"조사 가능한 곳:\n",
			"  1. 침대 아래\n",
			"  2. 창가\n",
			"  3. 탁자 위 감시일지\n",
			"\n메뉴로 돌아가시려면 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		std::cin.ignore();
		system("cls");

		std::vector<std::string> lines;

		switch (choice) {
		case 1:
			lines = {
				"[침대 아래]\n\n",
				"거미줄과 먼지만 가득하다.\n"
			};
			break;
		case 2:
			lines = {
				"[창가]\n\n",
				"짙은 안개로 인해 바깥 풍경이 보이지 않는다.\n"
			};
			break;
		case 3:
			if (!clueFound2)
			{
				lines = {
				   "[탁자 위 감시일지]\n\n",
				   "\"2179는 매일 똑같은 꿈을 꾼다고 했다.\n …그 죄수는 그날 밤 사라졌고,\n 위에서는 ‘지침’라고만 했을 뿐, \n 자세한 내용은 알 수 없었다...\"\n",
				   "기록은 거기서 끊겨 있다.\n",
				   "(단서 획득: 감시일지)\n"
				};
				SetClue2Found();
			}
			else {
				lines = {
					"[탁자 위 감시일지]\n\n",
					"이미 조사한 감시일지다.\n"
				};
				break;
		case 0:
			return;
		default:
			lines = { "잘못된 입력입니다.\n" };
			break;
			}

			for (const auto& line : lines)
			{
				TypeWriter(line, 10);
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
			}
			TypeWriter("\n", 5);
			system("pause");
			ClearScreen();
		}
	}
}

void Chapter2::Outtro()
{
	ClearScreen();

	TypeWriter("모든 조사를 마친 당신은, 조용히 교도소의 어둠에서 벗어난다.\n", 30);
	TypeWriter("그러나 어딘가 개운치 않은 기분이 마음을 짓누른다.\n", 30);

	TypeWriter("주머니 속에서 무언가가 진동한다.\n", 30);
	TypeWriter("…녹슨 수갑이다.\n", 40);
	TypeWriter("붉은 기운이 퍼지며, 멀리서 맑고 쓸쓸한 종소리가 들려온다.\n", 40);

	TypeWriter("\n그 순간-\n", 50);
	TypeWriter("낯설고도 익숙한 종소리가 귀를 울린다.\n", 40);
	TypeWriter("실제인지 환청인지, 분간되지 않는 맑고 낮은 음.\n", 30);
	TypeWriter("그리고… 시야에 어렴풋한 장면이 떠오른다.\n\n", 30);

	TypeWriter("축축한 지하 고문실, 흐릿한 등불 아래 무릎 꿇은 죄수.\n", 30);
	TypeWriter("그는 이미 정신이 반쯤 나간 채, 피를 흘리고 있다.\n", 30);
	TypeWriter("그 앞에 선 인물은 고위직 제복을 입고, 무언가를 건넨다.\n", 30);
	TypeWriter("“곧 죽을 놈입니다. 마음대로 하셔도 됩니다.”\n", 40);

	TypeWriter("그 말을 들은 그림자는 서늘한 표정으로 고개를 끄덕인다.\n", 30);
	TypeWriter("천천히 몸을 굽히고, 죄수의 손가락을 쥔다.\n", 30);
	TypeWriter("그리고 망설임 없이—\n", 30);
	TypeWriter("서늘한 칼날이 손가락을 자른다.\n", 40);

	TypeWriter("툭—\n", 50);
	TypeWriter("잘린 손가락이 피를 흘리며 바닥에 떨어진다.\n", 30);
	TypeWriter("그 손가락을 조심스럽게 붕대로 감싸 쥔 인물.\n", 30);
	TypeWriter("무언가, 금단의 의식을 준비하고 있었던 듯하다.\n\n", 30);

	TypeWriter("당신은 그 장면을 지켜본다.\n", 30);
	TypeWriter("숨이 막히고, 목 안쪽이 싸늘해진다.\n", 30);
	TypeWriter("처음 보는 기억인데도, 어딘가 익숙하다.\n", 30);

	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	std::cin.ignore();
	ClearScreen();

	TypeWriter("눈을 뜨니, 다시 교도소의 어둠 속.\n", 30);
	TypeWriter("손끝에서 수갑의 차가운 감촉이 더욱 뚜렷해진다.\n", 30);
	TypeWriter("기억은 흐릿하지만, 그 잔상은 쉽게 사라지지 않을 것 같다.\n\n", 30);

	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	std::cin.ignore();
	ClearScreen();
}
