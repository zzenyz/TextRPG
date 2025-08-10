#include "Chapter4.h"

void Chapter4::ShowIntro() {
    int introchoice;
    TypeWriter("인트로를 스킵하시겠습니까?\n", 40);
    TypeWriter("1. 예\n", 30);
    TypeWriter("2. 아니오\n", 30);
    TypeWriter("> ");
    std::cin >> introchoice;
    std::cin.ignore();

    if (introchoice == 1) {
        ClearScreen();
        return;
    }

    std::vector<std::string> lines = {
         "[폐교 입구]\n",
        "\n오래도록 버려진 폐교 앞에 섰다.\n",
        "녹슨 철문은 바람에 삐걱거리며 천천히 열리고,\n",
        "어둠과 먼지가 가득한 복도가 안쪽으로 길게 뻗어 있다.\n",
        "\n바닥에 떨어진 낙엽이 바람에 흩날리고, 먼지 냄새가 코를 찌른다.\n",
        "사라진 아이들의 웃음소리는 멀리서 희미하게 들리는 듯하지만\n",
        "그 소리는 곧 무거운 적막에 삼켜지고 만다.\n",
        "\n길고 긴 복도를 따라 발걸음을 옮기자, 오래된 벽에는\n",
        "지워진 낙서들과 벽지가 너덜너덜해져 있는 모습이 보인다.\n",
        "\n손끝에 닿는 차가운 벽면은 마치 누군가의 숨결을 간직한 듯\n",
        "선명한 기억을 불러일으킨다.\n",
        "\n한 걸음 한 걸음, 폐교 안 깊숙한 곳으로 들어갈수록\n",
        "불길한 기운이 짙어지고, 심장이 조여오는 듯하다.\n",
        "\n하지만 멈출 수 없다.\n",
        "이곳에 감춰진 진실이 나를 부르고 있으니까.\n",
        "\n숨을 깊게 들이쉬고, 나는 낡은 교실과 복도 사이로 발걸음을 내딛는다.\n"
    };

    for (const auto& line : lines) {
        TypeWriter(line, 30);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    std::cin.ignore();
    ClearScreen();
}

void Chapter4::ExploreMap()
{
    int choice;

        ClearScreen();
        TypeWriter("========================================\n", 20);
        TypeWriter("[이장이 내민 낡은 지도]\n\n", 20);
        TypeWriter("이장이 낡은 지도에 네 곳을 표시해 두었다.\n", 20);
        TypeWriter("각 장소 옆에는 이장이 직접 쓴 손글씨 메모가 붙어 있다.\n\n", 20);

        TypeWriter("  1. 교무실       - \"이곳엔 오래전부터 감춰진 무언가가 있다. 조심하길.\"\n", 20);
        TypeWriter("  2. 2층 교실     - \"마지막으로 모였던 아이들의 비밀을 간직한 곳.\"\n", 20);
        TypeWriter("  3. 음악실       - \"밤마다 울려 퍼지는 그 소리, 잊지 말게나.\"\n", 20);
        TypeWriter("  4. 보건실       - \"아픈 아이들이 자주 드나들던 곳이야. 이상한 기운이 맴돌지.\"\n\n", 20);

        TypeWriter("0. 메뉴로 돌아가기\n", 20);
        TypeWriter("조사할 장소를 선택하세요: \n> ", 20);

}

void Chapter4::ExploreStaffRoom() {
    int choice;
    bool foundClue = false;

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
        TypeWriter("[교무실]\n\n", 20);
        TypeWriter("조사할 장소를 선택하세요:\n", 20);
        TypeWriter("  1. 책상 서랍\n", 20);
        TypeWriter("  2. 서류철\n", 20);
        TypeWriter("  3. 책장\n", 20);
        TypeWriter("  0. 뒤로가기\n", 20);
        TypeWriter("> ", 20);

        std::cin >> choice;
        std::cin.ignore();

        ClearScreen();

        switch (choice) {
        case 1:
            TypeWriter("[책상 서랍]\n\n", 20);
            TypeWriter("서랍 안에는 낡은 볼펜과 몇 장의 메모지가 있다.\n", 20);
            TypeWriter("별다른 단서는 보이지 않는다.\n", 20);
            break;

        case 2:
            if (!clueFound1) {
                TypeWriter("[서류철]\n\n", 20);
                TypeWriter("서류철 속에는 예림 양에 관한 상담 기록과\n", 20);
                TypeWriter("예림 양 어머니가 학교에 자주 찾아왔다는 내용이 적혀 있다.\n", 20);
                SetConsoleColor(12);
                TypeWriter("(단서 획득: 상담 기록)\n", 20);
                SetConsoleColor(7);
                clueFound1 = true;
                SetClue1Found();
            }
            else {
                TypeWriter("[서류철]\n\n", 20);
                TypeWriter("이미 내용을 확인한 서류철이다.\n", 20);
            }
            break;

        case 3:
            TypeWriter("[책장]\n\n", 20);
            TypeWriter("책장에는 교육 자료와 참고서들이 빼곡히 꽂혀 있다.\n", 20);
            TypeWriter("특별한 단서는 없다.\n", 20);
            break;

        case 0:
            return;

        default:
            TypeWriter("잘못된 입력입니다. 다시 선택해 주세요.\n", 20);
            break;
        }

        TypeWriter("\n--- [계속하려면 Enter] ---\n", 20);
        std::cin.get();
        std::cin.ignore();
    }
}


void Chapter4::ExploreClassroom() {
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
        TypeWriter("[2층 교실]\n\n", 20);
        TypeWriter("책상과 의자들이 먼지를 뒤집어쓴 채 방치되어 있다.\n", 20);
        TypeWriter("학생들의 발자국과 낙서가 보인다.\n\n", 20);
        TypeWriter("조사 가능한 곳:\n", 20);
        TypeWriter("  1. 학생 책상 서랍\n", 20);
        TypeWriter("  2. 칠판 밑 바닥\n", 20);
        TypeWriter("  3. 창문 너머 운동장 쪽\n", 20);
        TypeWriter("\n0. 메뉴로 돌아가기\n");
        TypeWriter("조사할 장소를 선택하세요: \n> ", 20);

        std::cin >> choice;
        std::cin.ignore();

        ClearScreen();
        switch (choice) {
        case 1:
            if (!clueFound2) {
                TypeWriter("[학생 책상 서랍]\n\n", 20);
                TypeWriter("서랍 안에서 낡은 일기장이 발견되었다.\n", 20);
                TypeWriter("어린 아이가 쓴 듯한 글씨로 적혀 있다.\n", 20);
                TypeWriter("\"오늘 붉은 옷을 입은 아줌마가 조력자를 죽였어.\n", 20);
                TypeWriter("나는 숨죽여 지켜봤어.\n", 20);
                TypeWriter("그 아줌마가 다시 찾아올 것만 같아.\n", 20);
                SetConsoleColor(12);
                TypeWriter("(단서 획득: 일기장)\n", 20);
                SetConsoleColor(7);
                clueFound2 = true;
                SetClue2Found();
            }
            else {
                TypeWriter("[학생 책상 서랍]\n\n", 20);
                TypeWriter("이미 조사한 곳이다. 더 이상 특별한 것은 없다.\n", 20);
            }
            break;
        case 2:
            TypeWriter("[칠판 밑 바닥]\n\n", 20);
            TypeWriter("분필 가루가 흩뿌려져 있고, 발자국 자국이 희미하게 남아 있다.\n", 20);
            TypeWriter("누군가 이곳을 급히 떠난 듯하다.\n", 20);
            break;
        case 3:
            TypeWriter("[창문 너머 운동장 쪽]\n\n", 20);
            TypeWriter("바람에 흔들리는 나무와 오래된 운동장이 보인다.\n", 20);
            TypeWriter("낡은 그네가 삐걱거리는 소리를 낸다.\n", 20);
            break;
        case 0:
            return;
        default:
            TypeWriter("잘못된 입력입니다. 다시 선택해 주세요.\n", 20);
            break;
        }
        TypeWriter("\n", 10);
        system("pause");
    }
}

void Chapter4::ExploreInfirmary() {
    int choice;
    bool hintGiven = false;

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
        TypeWriter("[보건실]\n\n", 10);
        TypeWriter("낡은 침대와 약장으로 가득한 조용한 공간.\n", 15);
        TypeWriter("벽에는 오래된 건강 포스터가 빛바래고 있다.\n", 15);
        TypeWriter("한때 학생들이 드나들던 흔적이 남아 있지만, 지금은 기묘한 적막만이 감돈다.\n\n", 15);

        TypeWriter("조사 가능한 곳:\n", 15);
        TypeWriter("  1. 약장 서랍\n", 15);
        TypeWriter("  2. 침대 밑\n", 15);
        TypeWriter("  3. 출입문 근처 진료기록함\n", 15);
        TypeWriter("\n0. 메뉴로 돌아가려면 0\n조사할 장소를 선택하세요: \n> ", 15);

        std::cin >> choice;
        std::cin.ignore();
        ClearScreen();

        switch (choice) {
        case 1:
            TypeWriter("[약장 서랍]\n\n", 10);
            TypeWriter("먼지가 수북한 서랍 안에는 오래된 약병들이 가득하다.\n", 15);
            TypeWriter("라벨은 모두 바래 읽기 힘들지만, 일부 병엔 '진정제'라는 글자가 희미하게 남아 있다.\n", 15);
            break;
        case 2:
            if (!clueFound5) {
                TypeWriter("[침대 밑]\n\n", 10);
                TypeWriter("침대 밑 어두운 공간에서 작고 얇은 수첩 한 권이 발견된다.\n", 15);
                SetConsoleColor(12);
                TypeWriter("수첩 한 구석엔 이렇게 적혀 있다:\n", 15);
                TypeWriter("\"예림이 어머니께 붉은 옷을 입은 여자에 대해 말했어...\"\n", 15);
                TypeWriter("\"무슨일이 일어날 것만 같아.. 그러면 안됐던걸까?\"\n", 15);
                SetConsoleColor(7);
                clueFound5 = true;
                SetClue5Found();
            }
            else {
                TypeWriter("[침대 밑]\n\n", 10);
                TypeWriter("이미 확인한 작은 수첩 외에는 아무것도 없다.\n", 15);
            }
            break;
        case 3:
            TypeWriter("[출입문 근처 진료기록함]\n\n", 10);
            TypeWriter("오래된 진료카드와 파손된 체온계들이 흩어져 있다.\n", 15);
            TypeWriter("예림이의 이름이 적힌 기록은 보이지 않는다.\n", 15);
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

void Chapter4::ExploreMusicRoom() {
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
        TypeWriter("[음악실]\n\n", 10);
        TypeWriter("뒤엉킨 악기들과 먼지 낀 피아노, 그리고 정적이 감도는 공기.\n", 15);
        TypeWriter("한쪽 벽면엔 조그마한 공간이 반쯤 열려 있다. 사람 하나 들어갈까 말까한 크기다.\n\n", 15);

        TypeWriter("조사 가능한 곳:\n", 15);
        TypeWriter("  1. 피아노 아래\n", 15);
        TypeWriter("  2. 악보 보관함\n", 15);
        TypeWriter("  3. 가벽 근처\n", 15);
        TypeWriter("\n0. 메뉴로 돌아가려면 0\n조사할 장소를 선택하세요: \n> ", 15);

        std::cin >> choice;
        std::cin.ignore();
        ClearScreen();

        switch (choice) {
        case 1:
            TypeWriter("[피아노 아래]\n\n", 10);
            TypeWriter("먼지가 쌓인 피아노 아래엔 누군가 떨어뜨린 듯한 종이 조각들이 흩어져 있다.\n", 15);
            TypeWriter("내용은 알아볼 수 없지만, 몇몇은 무언가를 필사적으로 적은 흔적이 있다.\n", 15);
            break;
        case 2:
            TypeWriter("[악보 보관함]\n\n", 10);
            TypeWriter("책장처럼 생긴 보관함엔 곰팡이 슨 악보들이 어지럽게 꽂혀 있다.\n", 15);
            TypeWriter("누군가 급히 뒤진 흔적이 남아 있다.\n", 15);
            break;
        case 3:
            if (!bossAwakened) {
                TypeWriter("[가벽 근처]\n\n", 10);
                TypeWriter("살금살금 다가서려는 그 순간—\n", 40);
                TypeWriter("무언가 안쪽에서 움직인다.\n", 40);
                TypeWriter("낡은 악보가 바스락거리며 바닥으로 떨어진다.\n", 40);

                SetConsoleColor(12);
                TypeWriter("…기이한 존재가 모습을 드러낸다!\n", 10);
                SetConsoleColor(7);

                bossAwakened = true;
                system("pause");
                return;
            }
            else {
                TypeWriter("[조그만 공간 근처]\n\n", 10);
                TypeWriter("이미 그 안은 싸늘한 정적만이 감돌고 있다.\n", 15);
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

void Chapter4::Outtro()
{
    ClearScreen();

    TypeWriter("음악실을 감싸던 기묘한 정적이 서서히 가라앉는다.\n", 30);
    TypeWriter("그 틈으로… 또 하나의 기억이 스며든다.\n", 30);

    TypeWriter("가벽 뒤에서 느껴지던 그 기척.\n", 30);
   
    TypeWriter("귀를 찌르는 듯한 정적 속에, 다시 한 번— 종소리가 울린다.\n", 40);

    TypeWriter("\n그 순간—\n", 50);
    TypeWriter("시야가 일그러지고, 오래전 폐교의 어두운 복도가 펼쳐진다.\n\n", 30);

    TypeWriter("작은 발소리. 급히 뛰는 듯한 발걸음.\n", 30);
    TypeWriter("아이의 숨소리가 거칠게 복도 끝에서 들려온다.\n", 30);
    TypeWriter("그 아이는 두려움에 떨며 무언가를 전하려 애쓰고 있었다.\n", 30);

    TypeWriter("\n\"저 아이가 아까 부두에서 보았던 아이인가?\"\n", 30);

    TypeWriter("\n아이를 막으려는 붉은 옷 여자의 필사적인 움직임이 보인다.\n", 40);
   
    TypeWriter("한참을 쫓고, 결국 문이 열린 음악실 앞에서 아이의 흔적을 발견한다.\n", 30);
    TypeWriter("당신은 망설이지 않고, 조용히 문을 연다.\n", 30);

    TypeWriter("어둠 속, 가벽 뒤.\n", 30);
    TypeWriter("그곳에서, 아이는 당신을 올려다보고 있었다.\n", 40);

    TypeWriter("눈동자가 흔들리며 떨리는 입술이 말을 잇는다.\n", 30);
    TypeWriter("\"말하지 않을게요... 살려주세요...\"\n\n", 50);

    TypeWriter("그러나 그 여자는 조용히 손을 뻗는다.\n", 30);
    
    TypeWriter("\n기억은 종소리와 함께 닫히고, 현실로 돌아온다.\n", 30);
    TypeWriter("그러나 마음 깊은 곳, 죄책감은 더욱 선명해진다.\n", 30);

    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    std::cin.ignore();
    ClearScreen();

    TypeWriter("폐교의 먼지 냄새가 다시 코끝을 스친다.\n", 30);
    TypeWriter("하지만 귓가엔 여전히, 아이의 마지막 말이 맴도는 듯하다.\n", 30);
   
    TypeWriter("손에 쥔 어린아이의 것으로 추정되는 단추가 미세하게 떨린다.\n", 30);
    TypeWriter("그 안에서 희미하게 떨리는 기운.\n", 30);
    TypeWriter("그 아이의 기억이 아직, 사라지지 않았음을 말해주고 있다.\n", 40);

    TypeWriter("다음 목적지는 어디일까.\n", 30);
    TypeWriter("그곳엔 또 어떤 기억이, 어떤 죄가 기다리고 있을까…\n\n", 30);

    TypeWriter("\n--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    std::cin.ignore();
    ClearScreen();
}
