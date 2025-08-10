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
		 "[마을 폐사당 입구]\n",
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
    std::cin.ignore();
    ClearScreen();

    Warn();

}

void Chapter1::Warn()
{
	std::vector<std::string> lines;

	lines =
	{
		"========================================\n",
		"[Chapter 1]\n\n",

		"이장이 건넨 낡은 지도엔 폐사당의 네 장소가 표시돼 있다.\n\n",

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
		"[사당 조사 지도]\n\n",
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

void Chapter1::ExploreGrave() {
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

        // 인트로 출력
        TypeWriter("[작은 묘실]\n\n", 10);
        TypeWriter("좁고 어두운 공간에 촛불 몇 개가 깜빡인다.\n", 10);
        TypeWriter("벽에는 낙서 같은 글씨들이 새겨져 있다.\n\n", 10);
        TypeWriter("조사 가능한 곳:\n", 10);
        TypeWriter("  1. 봉인된 관\n", 10);
        TypeWriter("  2. 묘실 한편의 벽면\n", 10);
        TypeWriter("  3. 바닥의 흙더미\n\n", 10);
        TypeWriter("메뉴로 돌아가시려면 0\n", 10);
        TypeWriter("조사할 장소를 선택하세요:\n> ", 10);

        std::cin >> choice;
        std::cin.ignore();
        ClearScreen();

        switch (choice) {
        case 1:
            TypeWriter("[부서진 석관]\n\n", 10);
            if (bossAwakened) {
                TypeWriter("이미 열려 있는 석관 안은 텅 비어 있다.\n", 10);
                TypeWriter("무언가 빠져나온 듯, 안쪽은 핏자국과 흙먼지로 가득하다.\n", 10);
            }
            else {
                TypeWriter("석관의 뚜껑을 밀자, 싸늘한 기운이 퍼져나온다.\n", 10);
                TypeWriter("표면엔 부러진 손톱 자국이 선명히 남아 있다.\n", 10);

                SetConsoleColor(12); // 빨간색
                TypeWriter("잠들어 있던 무언가가 깨어난다...!\n", 10);
                SetConsoleColor(7); // 기본색 복구
                TypeWriter("전투가 시작된다!\n", 10);

                bossAwakened = true;
                system("pause");
                return; // 보스 등장 후 함수 종료
            }
            break;

        case 2:
            TypeWriter("[묘실 한편의 벽면]\n\n", 10);
            TypeWriter("벽에 붉은 잉크로 적힌 낙서가 희미하게 남아 있다.\n", 10);

            SetConsoleColor(12); // 빨간색
            TypeWriter("\"파낸 자, 죗값을 치러라...\"\n", 10);
            SetConsoleColor(7);

            TypeWriter("당신의 등골이 오싹해진다.\n", 10);
            break;

        case 3:
            TypeWriter("[바닥의 흙더미]\n\n", 10);
            TypeWriter("촉촉한 흙 아래에서 타다 남은 향과 초의 흔적이 발견된다.\n", 10);
            TypeWriter("누군가 오래전 이곳에서 은밀한 의식을 행했던 것 같다.\n", 10);
            TypeWriter("무의식적으로 당신의 손이 익숙하게 움직인다...\n", 10);
            TypeWriter("하지만 그 기억은 아직 명확히 떠오르지 않는다.\n", 10);
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


void Chapter1::ExploreHut() 
{
	int choice;
	bool hasFoundClue = false;

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
        std::cin.ignore();
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



void Chapter1::ExploreAltar() 
{
    int choice;
    bool hasFoundKeepsake = false;
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
            "[제단]\n\n",
            "검게 그을린 제단 위에는 이미 타버린 초가 놓여 있다.\n",
            "무언가 강력한 힘의 흔적이 느껴진다...\n\n",
            "조사 가능한 곳:\n",
            "  1. 제단 표면\n",
            "  2. 주변 촛대\n",
            "  3. 제단 뒤쪽\n",
            "\n메뉴로 돌아가시려면 0\n",
            "조사할 장소를 선택하세요: \n",
            "> "
        };
        for (const auto& line : intro) TypeWriter(line, 10);

        std::cin >> choice;
        std::cin.ignore();
        system("cls");

        std::vector<std::string> lines;

        switch (choice) {
        case 1:
            lines = {
                "[제단 표면]\n\n",
                "표면에는 칼로 긁은 듯한 흔적이 가득하다.\n",
                "무언가를 제물로 바친 듯한 자국이다.\n"
            };
            break;

        case 2:
            lines = {
                "[주변 촛대]\n\n",
                "촛대는 무언가 급히 끄려다 넘어진 흔적이 있다.\n",
                "바닥엔 흘러내린 초가 굳어있다.\n"
            };
            break;

        case 3:
            if (!hasFoundKeepsake)
            {
                lines = {
                    "[제단 뒤쪽]\n\n",
                    "낡은 천으로 감싸진 무언가를 발견했다.\n",
                    "그것은 깨진 옥 팔찌...\n",
                    "표면엔 피가 굳은 듯한 흔적이 남아 있다.\n",
                    "어딘가 당신의 손끝이 저려온다.\n",
                    "(유품 획득 : 부서진 옥 팔찌)\n"
                };

                hasFoundKeepsake = true;
                SetKeepsakeFound();
            }
            else
            {
                lines = {
                    "[제단 뒤쪽]\n\n",
                    "다시 살펴봤지만, 팔찌 외엔 남은 게 없다.\n"
                };
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

void Chapter1::ExploreYard() 
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
            "[마당]\n\n",
            "잡초가 무성한 마당에 발을 들이자, 으스스한 기운이 느껴진다.\n",
            "땅 속에서 무언가 꿈틀대는 것 같은 느낌...\n\n",
            "조사 가능한 곳:\n",
            "  1. 우물\n",
            "  2. 낡은 화장실\n",
            "  3. 폐기된 정원 창고\n",
            "\n메뉴로 돌아가시려면 0\n",
            "조사할 장소를 선택하세요: \n",
            "> "
        };
        for (const auto& line : intro) TypeWriter(line, 10);

        std::cin >> choice;
        std::cin.ignore();
        system("cls");

        std::vector<std::string> lines;

        switch (choice) {
        case 1:
            lines = {
                "[우물]\n\n",
                "우물 속은 까맣고 깊게 뚫려 있다.\n",
                "바닥에서 물소리는 들리지 않는다.\n",
                "무언가 다른 것이 있는 것 같지만 손이 닿지 않는다.\n"
            };
            break;

        case 2:
            lines = {
                "[낡은 화장실]\n\n",
                "문이 반쯤 열려 있고, 안에서는 쿰쿰한 냄새가 난다.\n",
                "거울에는 희미하게 번진 손자국이 남아 있다.\n",
                "누군가 이곳을 자주 드나든 듯하다...\n"
            };
            break;

        case 3:
            lines = {
                "[폐기된 정원 창고]\n\n",
                "자물쇠가 녹슬어 덜컥거리며 열렸다.\n",
                "안에는 먼지에 덮인 낡은 괭이 하나가 놓여 있다.\n",
                "그 순간, 손끝이 저릿하게 떨리며 어딘가 익숙한 느낌이 스친다.\n",
                "이 괭이는... 어디서 본 적이 있다.\n어쩌면, 무덤을 파헤치던 바로 그때...\n"
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

void Chapter1::Outtro()
{
    ClearScreen();

    TypeWriter("형체를 잃은 원혼은 사그라들며 폐사당 바닥에 흩어진다.\n", 30);
    TypeWriter("차가운 기운이 여전히 사방을 감싸고 있다.\n", 30);

    TypeWriter("주머니 속에서 미세한 진동이 느껴진다.\n", 30);
    TypeWriter("…옥팔찌다.\n", 40);
    TypeWriter("붉은 기운이 천천히 번져나오고, 멀리서 맑고 쓸쓸한 종소리가 들려온다.\n", 40);
    
    TypeWriter("\n그 순간-\n", 50);
    TypeWriter("어디선가 묘하게 익숙한 종소리가 들려온다.\n", 40);
    TypeWriter("실제인지 환청인지, 분간되지 않는 맑고 낮은 음.\n", 30);
    TypeWriter("그리고… 눈앞에 흐릿한 장면이 떠오른다.\n\n", 30);

    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    std::cin.ignore();
    ClearScreen();

    TypeWriter("낡았지만 관리가 잘 되어 보이는 폐사당..\n"); 
    TypeWriter("과거 이곳을 모습인걸까 ? \n");
    TypeWriter("아래 무릎 꿇은 누군가가 울부짖는다.\n", 30);
    TypeWriter("그리고 어두운 손이 무덤을 파헤친다.\n", 30);
    TypeWriter("무릎 꿇은 존재가 떨리는 목소리로 울부짖는다.\n", 30);
    TypeWriter("그 형체는 인간과 닮았지만, 그 기운은 오래된 무언가였다.\n", 30);
    TypeWriter("“그만둬라… 금기를 어기면, 이 땅에 저주가 드리운다…”\n", 40);
    TypeWriter("그 손은 서늘한 칼날을 꺼내 무언가를 자르기 시작한다.\n", 40);
    TypeWriter("관리인 일지에 적힌 그 여자가, 바로 저 여자인 걸까?\n", 50);
    TypeWriter("손가락 하나가 차갑게 땅에 떨어진다.\n\n", 30);

 
    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    std::cin.ignore();
    ClearScreen();

    ClearScreen();
    TypeWriter("눈을 뜨니, 폐사당의 어둠 속.\n", 30);
    TypeWriter("손끝에서 팔찌의 무게가 더욱 실감난다.\n", 30);
    TypeWriter("기억은 흐릿하지만, 이 이상한 끈은 쉽게 끊어지지 않을 것 같다.\n\n", 30);

    TypeWriter("내 머리속에 울려 퍼지는 종소리는,\n", 30);
    TypeWriter("아직 끝나지 않은 이야기를 속삭이고 있다...\n\n", 30);

 
    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    std::cin.ignore();
    ClearScreen();
}