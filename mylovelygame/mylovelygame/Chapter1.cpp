#include "Chapter1.h"

void Chapter1::ShowIntro()
{
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

	std::vector<std::string> lines;
	lines = {
		 "[마을 공동묘지 입구]\n",
		 "\n이장의 안내를 따라 마을 깊숙한 곳에 위치한 오래된 누군가의 묘지로 향했다.\n",
		 "\n이장이 낡은 지도를 꺼내 펼친다...\n",
		 "\n\"이 지도를 가지고 마을 곳곳을 조사해 주게나\"\n",
		 "\"나는 여기까지 데려다 줄 수 있을 것 같소...\"\n",
		 "\"이 후부턴 혼자 힘으로 해결해야 한다오\"\n",
		 "\n이장이 사라진 자리에 홀로 남은 당신은\n",
		 "묘지 한가운데 서서 묘비를 바라보았다.\n",
		 "\n그 순간, 어렴풋이 기억이 스쳐 지나간다.\n",
		 "누군가와 묘지를 파헤치던 모습과 무언가를 붙잡으려 허공을 더듬는...\n",
		 "\n\"…이 정도 뼈면 충분하겠지\"\n",
		 "너무나 생생한 이 기억의 주인이 모든 일의 원흉일지 모른다는 생각이 들었다.\n",
		 "\n깊게 숨을 들이쉰 당신은 지도를 펼쳐 들고 첫 조사를 시작한다.\n"
	};

	for (const auto& line : lines) {
		TypeWriter(line, 30);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();

}

void Chapter1::Warn()
{
	std::vector<std::string> lines;

	lines =
	{
		"========================================\n",
		"[Chapter 1]\n\n",

		"이장이 건넨 낡은 지도엔 마을 공동묘지의 네 장소가 표시돼 있다.\n\n",

		"- 각 장소에서는 단서나 유품을 찾을 수 있습니다.\n",
		"- 단서와 유품은 이 사건의 진실을 파악하는 데 중요한 열쇠입니다.\n",
		"- 그러나 어떤 장소에선… 무언가가 당신을 기다리고 있을지도 모릅니다.\n\n",

		"※ 조사를 잘 선택하고, 준비 없이 돌아다니지 마세요.\n",
		"========================================\n"
	};

	for (const auto& line : lines)
	{
		TypeWriter(line, 10);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

}

void Chapter1::ExploreMap()
{
	std::vector<std::string> lines;

	lines =
	{
		"========================================\n"
		"[공동묘지 조사 지도]\n\n",
			"이장이 내민 낡은 지도에는 네 곳이 표시되어 있다.\n",
			"네 곳의 장소마다 손글씨로 남긴 메모가 적혀 있다.\n\n",

			"  1. 작은 묘실       - \"그 근처만 가면 몸이 으슬으슬 하거든.\"\n",
			"  2. 관리인 오두막   - \"예전 묘지 관리인이 살았던 곳이지.\"\n",
			"  3. 제단           - \"이 제단에 함부로 손댄 사람치고 멀쩡한 이가 없었어.\"\n"
			"  4. 마당           - \"누군가 최근에 들렀던 흔적이 있어.\"\n\n"

			"메뉴로 돌아가시려면 0\n"
			"조사할 장소를 선택하세요: \n"
			"> "
	};

	for (const auto& line : lines)
	{
		TypeWriter(line, 5);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}


void Chapter1::ExploreHut() 
{
	int choice;
	bool hasFoundClue = false;

	while (true) {
		ClearScreen();
		std::vector<std::string> intro = {
			"[관리인 오두막]\n\n",
			"문을 열자 삐걱거리는 소리와 함께 곰팡내가 퍼진다.\n",
			"누군가 오래전에 살던 흔적이 고스란히 남아 있다.\n\n",
			"조사 가능한 곳:\n",
			"  1. 책상\n",
			"  2. 책장\n",
			"  3. 침대\n",
			"\n메뉴로 돌아가시려면 0\n",
			"조사할 장소를 선택하세요: \n"
			"> "
		};
		for (const auto& line : intro) {
			TypeWriter(line, 10);
		}

		std::cin >> choice;
		system("cls");

		std::vector<std::string> lines;

		switch (choice) {
		case 1:
			lines.push_back("[책상]\n\n");
			if (!hasFoundClue) {
				lines.push_back("서랍을 열자 오래된 수첩이 눈에 띈다.\n");
				lines.push_back("“난 저주를 받은 게 분명하다. 묘지를 파헤친 그 여자 때문이야... 웃고 있었다. 분명히...”\n\n");
				lines.push_back("(단서 획득: 관리인의 일지)\n");
				hasFoundClue = true;
				SetClueFound();
			}
			else {
				lines.push_back("이미 조사했다. 더 이상 나올 건 없어 보인다.\n");
			}
			break;

		case 2:
			lines = {
				"[책장]\n\n",
				"먼지가 수북히 쌓인 책들이 줄지어 꽂혀 있다.\n",
				"제목은 모두 흐릿하고, 안은 텅 비어 있다.\n",
				"아무런 정보도 얻을 수 없었다.\n"
			};
			break;

		case 3:
			lines = {
				"[침대]\n\n",
				"침대 아래를 들춰보자, 낡은 이불이 축축하게 젖어 있다.\n",
				"무언가 기어간 자국 같은 얼룩이 보인다...\n",
				"이상한 기분만 들 뿐, 쓸만한 건 없었다.\n"
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
