//#include "Chapter5.h"
//
//void Chapter5::ShowIntro() {
//    std::vector<std::string> lines = {
//        "[마을 폐가 입구]\n",
//        "\n이장의 낡은 지도를 따라 마을 외곽, 오래도록 비어 있던 폐가에 도착했다.\n",
//        "\n지도엔 네 곳이 표시되어 있고, 이장이 손수 적은 메모가 여기저기 붙어 있다.\n",
//        "\n'예림 엄마와 관련이 있을지도 모른다는 생각이 들었다.\n",
//        "\n이장은 여기까지 동행해주었지만, 이 뒤부턴 스스로 조심하며 움직여야 한다고 했다.\n",
//        "\n홀로 남은 당신은 깊게 숨을 들이쉬고 폐가 안으로 발걸음을 옮긴다.\n",
//        "\n묵은 나무가 삐걱이고, 바람이 서늘하게 불어온다.\n",
//        "\n숨겨진 진실에 조금씩 다가가는 기분이 든다...\n"
//    };
//
//    for (const auto& line : lines) {
//        TypeWriter(line, 30);
//        std::this_thread::sleep_for(std::chrono::milliseconds(300));
//    }
//
//    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
//    std::cin.get();
//    ClearScreen();
//}
//
//void Chapter5::ExploreMap() {
//    int choice;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("========================================\n", 20);
//        TypeWriter("[폐가 조사 지도]\n\n", 20);
//        TypeWriter("네 곳에 손글씨로 메모가 붙어 있다.\n", 20);
//        
//        TypeWriter("  1. 거실       - \"오래된 가구와 낡은 가족 사진이 남아 있소. 조심히 살펴보게.\"\n", 20);
//        TypeWriter("  2. 지하실     - \"차가운 공기 속에 오래 묵은 상자들이 쌓여 있소. 뭔가 숨겨져 있을지 몰라.\"\n", 20);
//        TypeWriter("  3. 안방       - \"누군가 마지막으로 머문 듯한 방이오. 무언가 느껴지거든 조심히 행동하게.\"\n", 20);
//        TypeWriter("  4. 다락방     - \"먼지 쌓인 옷가지와 물건들이 보이오. 잊힌 기억이 숨어 있을지도 모르지.\"\n\n", 20);
//
//        TypeWriter("0. 메뉴로 돌아가기\n", 20);
//        TypeWriter("조사할 장소를 선택하세요: \n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//
//        switch (choice) {
//        case 1:
//            ExploreLivingRoom();
//            break;
//        case 2:
//            ExploreBasement();
//            break;
//        case 3:
//            ExploreMasterRoom();
//            break;
//        case 4:
//            ExploreAttic();
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("잘못된 입력입니다.\n", 20);
//            system("pause");
//            break;
//        }
//    }
//}
//
//void Chapter5::ExploreLivingRoom() {
//    int choice;
//    bool clueFound = false;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[거실]\n\n", 20);
//        TypeWriter("낡은 소파와 먼지 쌓인 탁자가 어지럽게 놓여 있다.\n", 20);
//        TypeWriter("벽에는 빛바랜 사진 액자가 걸려 있다.\n\n", 20);
//        TypeWriter("조사 가능한 곳:\n", 20);
//        TypeWriter("  1. 사진 액자\n", 20);
//        TypeWriter("  2. 소파 밑\n", 20);
//        TypeWriter("  3. 책장\n", 20);
//        TypeWriter("0. 돌아가기\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            if (!clueFound) {
//                TypeWriter("[사진 액자]\n\n", 20);
//                TypeWriter("행복해 보이는 가족 사진이다.\n", 20);
//                TypeWriter("…잠깐, 이 아이는…\n", 20);
//                TypeWriter("어? 이 아이… 예림이잖아?\n", 20);
//                SetConsoleColor(12);
//                TypeWriter("(단서 획득: 가족 사진)\n", 20);
//                SetConsoleColor(7);
//                clueFound = true;
//                SetClue1Found();
//            }
//            else {
//                TypeWriter("이미 본 사진이다. 더 이상 단서는 없다.\n", 20);
//            }
//            break;
//        case 2:
//            TypeWriter("[소파 밑]\n\n", 20);
//            TypeWriter("먼지가 수북히 쌓여 있고 오래된 리모컨만 굴러다닌다.\n", 20);
//            break;
//        case 3:
//            TypeWriter("[책장]\n\n", 20);
//            TypeWriter("낡은 잡지와 찢어진 동화책들이 꽂혀 있다.\n", 20);
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("잘못된 입력입니다.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
//
//void Chapter5::ExploreBasement() {
//    int choice;
//    bool clueFound = false;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[지하실]\n\n", 20);
//        TypeWriter("축축한 공기 속, 오래된 박스와 가구들이 어둠에 잠겨 있다.\n\n", 20);
//        TypeWriter("조사 가능한 곳:\n", 20);
//        TypeWriter("  1. 오래된 상자\n", 20);
//        TypeWriter("  2. 선반 위\n", 20);
//        TypeWriter("  3. 콘센트 뒤\n", 20);
//        TypeWriter("0. 돌아가기\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            if (!clueFound) {
//                TypeWriter("[오래된 상자]\n\n", 20);
//                TypeWriter("상자 안에는 빛바랜 신문 조각이 섞여 있다.\n", 20);
//                TypeWriter("한 구석의 기사 제목이 눈에 들어온다:\n", 20);
//                TypeWriter("『딸을 찾아갔던 마지막 방문지… 그 후 행방불명』\n", 20);
//                SetConsoleColor(12);
//                TypeWriter("(단서 획득: 신문 조각)\n", 20);
//                SetConsoleColor(7);
//                clueFound = true;
//                SetClue2Found();
//            }
//            else {
//                TypeWriter("이미 조사한 상자다.\n", 20);
//            }
//            break;
//        case 2:
//            TypeWriter("[선반 위]\n\n", 20);
//            TypeWriter("오래된 캔들과 깨진 유리병이 놓여 있다.\n", 20);
//            break;
//        case 3:
//            TypeWriter("[콘센트 뒤]\n\n", 20);
//            TypeWriter("거미줄이 쳐져 있고, 이물질로 막혀 있다.\n", 20);
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("잘못된 입력입니다.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
//
//void Chapter5::ExploreMasterRoom() {
//    int choice;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[안방]\n\n", 20);
//        TypeWriter("이불이 반쯤 젖혀진 침대와, 커튼이 반쯤 닫힌 창문.\n", 20);
//        TypeWriter("방 안에는 낮은 숨소리가 들리는 듯한 착각이 든다.\n\n", 20);
//        TypeWriter("조사 가능한 곳:\n", 20);
//        TypeWriter("  1. 화장대\n", 20);
//        TypeWriter("  2. 커튼 뒤 그림자\n", 20);
//        TypeWriter("  3. 침대 밑\n", 20);
//        TypeWriter("0. 돌아가기\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            TypeWriter("[화장대]\n\n", 20);
//            TypeWriter("닳아버린 빗과 오래된 립스틱이 놓여 있다.\n", 20);
//            break;
//        case 2:
//            TypeWriter("[커튼 뒤 그림자]\n\n", 20);
//            TypeWriter("커튼 사이로 어렴풋이 사람 형체 같은 것이 보인다.\n", 20);
//            TypeWriter("하지만 다가가 보면 아무것도 없다.\n", 20);
//            break;
//        case 3:
//            if (!bossAwakened) {
//                TypeWriter("[침대 밑]\n\n", 20);
//                TypeWriter("손전등을 비추는 순간, 그 안에서 무언가가 움직인다.\n", 30);
//                SetConsoleColor(12);
//                TypeWriter("…기이한 존재가 갑작스레 모습을 드러낸다!\n", 30);
//                SetConsoleColor(7);
//                bossAwakened = true;
//                system("pause");
//                return;
//            }
//            else {
//                TypeWriter("그곳엔 이제 아무것도 없다.\n", 20);
//            }
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("잘못된 입력입니다.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
//
//void Chapter5::ExploreAttic() {
//    int choice;
//    bool keepsakeFound = false;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[다락방]\n\n", 20);
//        TypeWriter("먼지 가득한 상자들과 옷가지가 흩어져 있다.\n\n", 20);
//        TypeWriter("조사 가능한 곳:\n", 20);
//        TypeWriter("  1. 장난감 상자\n", 20);
//        TypeWriter("  2. 천으로 덮인 의자\n", 20);
//        TypeWriter("  3. 벽면 구석\n", 20);
//        TypeWriter("0. 돌아가기\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            if (!keepsakeFound) {
//                TypeWriter("[장난감 상자]\n\n", 20);
//                TypeWriter("곰인형 하나가 상자 안에 누워 있다.\n", 20);
//                TypeWriter("등에 달린 리본은 조금 헤어졌지만, 어쩐지 아련한 느낌이다.\n", 20);
//                SetConsoleColor(12);
//                TypeWriter("(유품 획득: 곰인형)\n", 20);
//                SetConsoleColor(7);
//                keepsakeFound = true;
//                SetKeepsake1Found();
//            }
//            else {
//                TypeWriter("곰인형 외엔 특별한 것이 없다.\n", 20);
//            }
//            break;
//        case 2:
//            TypeWriter("[천으로 덮인 의자]\n\n", 20);
//            TypeWriter("누렇게 바랜 천이 내려앉은 흔적뿐.\n", 20);
//            break;
//        case 3:
//            TypeWriter("[벽면 구석]\n\n", 20);
//            TypeWriter("거미줄만 잔뜩 쳐져 있다.\n", 20);
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("잘못된 입력입니다.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
