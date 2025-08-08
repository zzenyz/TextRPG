#include "Chapter3.h"

void Chapter3::ShowIntro()
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

    std::vector<std::string> lines = {
        "[버려진 부두]\n",
        "\n지도를 따라 도착한 곳은 오래된 선착장, 부두는 이미 기능을 잃은 채 무너져 있다.\n",
        "바람은 짠내를 머금고, 하늘은 잿빛으로 드리워져 있다.\n",
        "\n그러나 당신의 발걸음은 이곳을 망설임 없이 향했다.\n",
        "이 장소… 어딘가 익숙하다. 마치 오랫동안 잊고 있던 기억처럼.\n",
        "\n쉴 새 없이 파도가 철썩이고, 배는 모두 떠난 듯하다.\n",
        "그곳 어딘가에서 무언가 당신을 기다리고 있다.\n"
    };

    for (const auto& line : lines) {
        TypeWriter(line, 30);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();
}

void Chapter3::ExploreMap()
{
    std::vector<std::string> lines;

    lines =
    {
        "========================================\n"
        "[부두 조사 지도]\n\n",
        "부두 근처에 그려진 낡은 지도에는 네 곳이 표시되어 있다.\n",
        "붉게 물든 손글씨로 이상한 메모가 덧붙어 있다.\n\n",

        "  1. 유류창고        - \"문이 잠겨 있었는데, 안에서 뭔가 긁는 소리가 나더라고.\"\n",
        "  2. 낡은 어선        - \"닻은 없고, 그 안에 오래된 짐이 가득했어.\"\n",
        "  3. 부두 끝자락      - \"밤마다 파도보다 더 큰 소리가 들렸대.\"\n",
        "  4. 등대             - \"한밤중에도 등불이 켜졌다는 말이 있어. 사람이 없는데도.\"\n\n",

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


void Chapter3::ExploreStorage() {
    bool hasKeepsake = false;
    int choice;

    while (true) {
        ClearScreen();
        TypeWriter("[유류 창고]\n\n", 10);
        TypeWriter("습하고 눅눅한 공기가 가득한 유류 창고.\n", 15);
        TypeWriter("녹슨 유조통과 부서진 배럴들이 흩어져 있어, 누군가 급히 이곳을 떠난 듯한 느낌이다.\n", 15);
        TypeWriter("기름 냄새가 코끝을 자극하며, 어딘가 음산한 기운이 감돈다.\n\n", 15);
        TypeWriter("조사 가능한 장소:\n", 15);
        TypeWriter("  1. 바닥에 널린 낡은 배럴\n", 15);
        TypeWriter("  2. 창고 안쪽 벽면\n", 15);
        TypeWriter("  3. 기름 자국이 남은 바닥\n", 15);
        TypeWriter("\n0. 메뉴로 돌아가기\n", 15);
        TypeWriter("조사할 장소를 선택하세요: \n> ", 15);

        std::cin >> choice;
        std::cin.ignore();
        ClearScreen();

        switch (choice) {
        case 1:
            TypeWriter("[바닥에 널린 낡은 배럴]\n\n", 15);
            TypeWriter("녹슨 철제 배럴들이 어지럽게 쌓여 있고, 오래된 기름 냄새가 진동한다.\n", 15);
            TypeWriter("급하게 버려진 듯한 배럴 사이로 바닥이 젖어 있는 부분이 보인다.\n", 15);
            break;
        case 2:
            if (!hasKeepsake) {
                TypeWriter("[창고 안쪽 벽면 근처 낡은 상자]\n\n", 15);
                TypeWriter("벽면 근처에 놓인 낡은 나무 상자가 있다.\n", 15);
                TypeWriter("상자 안에 오래된 인형 조각과 함께 작은 단추가 보인다.\n", 15);
                TypeWriter("이 단추는 분명 아이가 남긴 흔적이다.\n", 15);
                SetConsoleColor(12);
                TypeWriter("(단서 획득 : 어린아이의 단추)\n", 15);
                SetConsoleColor(7);
                hasKeepsake = true;
                SetKeepsake4Found();
            }
            else {
                TypeWriter("[창고 안쪽 벽면 근처 낡은 상자]\n\n", 15);
                TypeWriter("상자 안에는 단추가 놓여 있다.\n");
                TypeWriter("이미 익숙한 흔적이다.\n");
            }
            break;

        case 3:
            TypeWriter("[기름 자국이 남은 바닥]\n\n", 15);
            TypeWriter("기름이 바닥을 따라 흘러내린 자국이 선명하다.\n", 15);
            TypeWriter("자국은 부두 끝으로 이어져 있어 누군가가 이쪽으로 급히 나간 듯하다.\n", 15);
            break;
        case 0:
            return;
        default:
            TypeWriter("잘못된 입력입니다. 다시 선택해 주세요.\n", 15);
            break;
        }

        TypeWriter("\n", 10);
        system("pause");
    }
}


void Chapter3::ExploreBoat() {
    int choice;
    bool hasKeepsake = false;

    while (true) {
        ClearScreen();
        TypeWriter("[부서진 어선 내부]\n\n", 10);
        TypeWriter("기울어진 선실에 들어서자, 눅눅한 바닷내음이 감돈다.\n", 10);
        TypeWriter("바닥에는 해초와 부식된 나무 조각이 널려 있다.\n\n", 10);
        TypeWriter("조사 가능한 곳:\n", 10);
        TypeWriter("  1. 선실 바닥 아래\n", 10);
        TypeWriter("  2. 조타 장치 근처\n", 10);
        TypeWriter("  3. 밧줄 더미\n", 10);
        TypeWriter("\n메뉴로 돌아가시려면 0\n조사할 장소를 선택하세요: \n> ", 10);

        std::cin >> choice;
        std::cin.ignore();
        ClearScreen();

        switch (choice) {
        case 1:
            if (!hasKeepsake) {
                TypeWriter("[선실 바닥 아래]\n\n", 10);
                TypeWriter("덜컹— 손에 무언가 걸린다.\n", 10);
                TypeWriter("꺼내보니, 피가 얼룩진 조타 손잡이다.\n", 10);
                TypeWriter("표면은 깨져 있고, 오래전 누군가 단단히 붙잡았던 자국이 남아 있다.\n", 10);
                SetConsoleColor(12);
                TypeWriter("(유품 획득: 깨진 조타 손잡이)\n", 10);
                SetConsoleColor(7);
                hasKeepsake = true;
                SetKeepsakeFound();
            }
            else {
                TypeWriter("[선실 바닥 아래]\n\n", 10);
                TypeWriter("더 이상 특별한 것은 보이지 않는다.\n", 10);
            }
            break;
        case 2:
            TypeWriter("[조타 장치 근처]\n\n", 10);
            TypeWriter("조타 장치는 이미 녹슬어 쓸 수 없다.\n", 10);
            TypeWriter("어딘가 부자연스럽게 부서진 자국이 남아 있다.\n", 10);
            break;
        case 3:
            TypeWriter("[밧줄 더미]\n\n", 10);
            TypeWriter("축축한 밧줄 사이에서 짐승의 털 같은 것이 엉켜 있다.\n", 10);
            TypeWriter("사람의 것일까, 짐승의 것일까… 정확히 알 수 없다.\n", 10);
            break;
        case 0:
            return;
        default:
            TypeWriter("잘못된 입력입니다.\n", 10);
            break;
        }

        TypeWriter("\n", 5);
        system("pause");
    }
}

void Chapter3::ExploreDockEdge() {
    int choice;

    while (true) {
        ClearScreen();
        TypeWriter("[부두 끝]\n\n", 10);
        TypeWriter("파도가 철썩이며 부두 기둥을 때린다.\n", 10);
        TypeWriter("그 끝엔 누군가 서 있었던 듯, 깊이 파인 발자국 흔적이 보인다.\n\n", 10);
        TypeWriter("조사 가능한 곳:\n", 10);
        TypeWriter("  1. 오래된 고무 튜브와 낡은 어망 더미\n", 10);
        TypeWriter("  2. 철제 기둥 주변\n", 10);
        TypeWriter("  3. 부두 난간 끝자락\n", 10);
        TypeWriter("\n메뉴로 돌아가시려면 0\n조사할 장소를 선택하세요: \n> ", 10);

        std::cin >> choice;
        std::cin.ignore();
        ClearScreen();

        switch (choice) {
        case 1:
            TypeWriter("[오래된 고무 튜브와 낡은 어망 더미]\n\n", 15);
            TypeWriter("한쪽 구석에는 오래된 고무 튜브와 낡은 어망이 어지럽게 쌓여 있다.\n", 15);
            TypeWriter("바닷바람에 쓸려 온 모래와 먼지가 가득하며,\n", 15);
            TypeWriter("어디선가 끈적한 해양 생물의 냄새가 은은하게 풍긴다.\n", 15);
            break;

        case 2:
            TypeWriter("[철제 기둥 주변]\n\n", 15);
            TypeWriter("누군가 급하게 이곳을 지나간 듯한 흔적이 남아 있다.\n", 15);
            break;
        case 3:
            TypeWriter("[부두 난간 끝자락]\n\n", 10);

            if (bossAwakened) {
                TypeWriter("이미 그 자리는 싸늘한 공기만이 감돌고 있다.\n", 10);
                TypeWriter("기묘한 기운이 가라앉았지만, 뭔가 아직 끝나지 않은 느낌이다...\n", 10);
            }
            else {
                TypeWriter("잔잔하던 물결이 갑자기 일렁인다...\n", 10);
                TypeWriter("바다 안쪽에서 묘한 울음소리가 들려온다.\n", 10);
                TypeWriter("순간, 발밑 바닥이 떨리기 시작한다!\n", 10);

                SetConsoleColor(12); // 붉은색
                TypeWriter("…기이한 존재가 모습을 드러낸다!\n", 10);
                SetConsoleColor(7); // 복구

                bossAwakened = true;
                system("pause");
                return;
            }
            break;
        case 0:
            return;
        default:
            TypeWriter("잘못된 입력입니다.\n", 10);
            break;
        }

        TypeWriter("\n", 5);
        system("pause");
    }
}


void Chapter3::ExploreLighthouse() {
    int choice;
    
    while (true) {
        ClearScreen();
        TypeWriter("[버려진 등대 내부]\n\n", 10);
        TypeWriter("무너진 계단을 따라 올라가자, 오래된 등불과 거울 장치가 보인다.\n", 10);
        TypeWriter("바다를 굽어보는 등대 내부는 오래되어 삭았지만,누군가가 사용한 흔적이 남아 있다.\n", 15);
        TypeWriter("한쪽 구석에는 누군가 머물렀던 흔적이 있다.\n\n", 10);
        TypeWriter("조사 가능한 곳:\n", 10);
        TypeWriter("  1. 장비 뒷편 나무 상자\n", 10);
        TypeWriter("  2. 창가\n", 10);
        TypeWriter("  3. 먼지 쌓인 책상\n", 10);
        TypeWriter("\n메뉴로 돌아가시려면 0\n조사할 장소를 선택하세요: \n> ", 10);

        std::cin >> choice;
        std::cin.ignore();
        ClearScreen();

        switch (choice) {
        case 1:
            TypeWriter("[장비 뒷편 나무 상자]\n\n", 10);
            TypeWriter("상자 안엔 낡은 천과 통조림이 있다. 생활의 흔적일까.\n", 10);
            break;
        case 2:
            TypeWriter("[창가]\n\n", 10);
            TypeWriter("창틀 위에 쌓인 먼지 너머로 바다가 보인다.\n", 10);
            TypeWriter("누군가 오래도록 이곳을 지켜봤던 것처럼 느껴진다.\n", 10);
            break;
        case 3:
            if (!clueFound) {
                TypeWriter("[등대지기 메모]\n\n", 15);
                TypeWriter("최근 이 마을에서 이상한 소문이 돌고 있다.\n", 15);
                SetConsoleColor(12);
                TypeWriter("\"요즘 저 여자가 뭔가 수상한 짓을 한다고들 한다.\"\n", 15);
                TypeWriter("\"그가 왜 그녀를 돕는지 이해할 수 없다. 더욱 큰 일이 벌어질까 두렵다.\"\n");
                SetConsoleColor(7);
                TypeWriter("이 메모는 누군가의 불안과 의심으로 가득 차 있다.\n", 15);
                clueFound = true;
                SetClueFound();
            }
            else {
                TypeWriter("[등대지기 메모]\n\n", 15);
                TypeWriter("메모에는 변함없는 불안과 의심만이 적혀 있다.\n", 15);
            }
            break;
        case 0:
            return;
        default:
            TypeWriter("잘못된 입력입니다.\n", 10);
            break;
        }
        TypeWriter("\n", 5);
        system("pause");
    }
}

void Chapter3::Outtro()
{
    ClearScreen();

    TypeWriter("부두를 감싸던 소금기와 피비린내가 서서히 가라앉는다.\n", 30);
    TypeWriter("그 틈에서… 잊혀졌던 기억이 스며든다.\n", 30);

    TypeWriter("손에 쥔 조타 손잡이가 미세하게 떨린다.\n", 30);
    TypeWriter("붉은 기운이 맴돌며, 낮고 맑은 종소리가 귓가를 울린다.\n", 40);

    TypeWriter("\n그 순간—\n", 50);
    TypeWriter("당신의 시야가 희미하게 흐려지고, 또 하나의 기억이 떠오른다.\n\n", 30);

    TypeWriter("젖은 나무 판자 위.\n", 30);
    TypeWriter("쓰러진 인물의 손끝에서 피가 천천히 바닥으로 번진다.\n", 30);
    TypeWriter("당신의 손에는, 잘린 손가락 하나가 들려 있다.\n", 30);

    TypeWriter("쓰러진 자가 눈을 뜨고, 떨리는 목소리로 중얼인다.\n\n", 40);
    TypeWriter("“…왜… 왜 나야…?”\n", 50);
    TypeWriter("“…우린… 함께였잖아…”\n\n", 50);

    TypeWriter("하지만 당신은 대답하지 않는다.\n", 30);
    TypeWriter("그를 바다로 밀어넣고, 잔잔한 물결이 모든 것을 덮는다.\n", 30);

    TypeWriter("등을 돌려 걸음을 떼려는 그 순간—\n", 40);
    TypeWriter("바스락.\n", 40);
    TypeWriter("등 뒤에서 아주 작은 소리가 들린다.\n", 40);

    TypeWriter("당신은 무심결에 고개를 돌린다.\n", 30);
    TypeWriter("부두 끝, 오래된 상자 뒤에 무언가가 숨어 있었다.\n", 40);
    TypeWriter("…조그마한 그림자.\n", 30);
    TypeWriter("작은 키, 마른 팔다리, 새하얀 눈동자.\n", 30);

    TypeWriter("그 존재는 당신과 눈을 마주치고, 순간적으로 몸을 숨긴다.\n", 40);
    TypeWriter("그 아이는, 이 모든 것을… 보고 있었다.\n", 50);

    TypeWriter("그 아이는… 누구였을까?\n", 30);
    TypeWriter("그리고 왜… 그 기억에 섞여 있었던 걸까…\n\n", 30);

    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();

    TypeWriter("짠내와 바닷바람이 다시 피부를 스친다. 부두다.\n", 30);
    TypeWriter("하지만 귓가엔 아직도, 그 작은 숨소리가 남아 있는 듯하다.\n", 30);
    TypeWriter("…무언가가 당신을 지켜보고 있었다.\n", 40);

    TypeWriter("당신은 무의식적으로 주머니에서 지도를 꺼낸다.\n", 30);
    TypeWriter("붉은 잉크로 표시된 다음 목적지...\n", 30);
    TypeWriter("그건— 바로 ‘폐교’였다.\n", 40);

    TypeWriter("방금 전 기억 속, 그 아이가 사라진 방향과 정확히 일치한다.\n", 40);
    TypeWriter("마치 누군가가… 아니, 그 아이가 당신을 그곳으로 이끌고 있는 듯하다.\n\n", 50);

    TypeWriter("그 폐교에서, 또 어떤 기억이 기다리고 있을까…\n\n", 30);

    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();
}
