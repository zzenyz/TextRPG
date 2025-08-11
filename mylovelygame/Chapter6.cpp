#include "Chapter6.h"

void Chapter6Intro()
{
    ClearScreen();

    TypeWriter("폐가를 떠나려는 당신 앞에 이장이 모습을 드러낸다.\n", 40);
    TypeWriter("그는 믿음 어린 목소리로 말한다.\n", 40);
    TypeWriter("\"마을 문제는 이제 모두 해결된 것 같네. 도와주어서 정말 고마워.\"\n", 50);
    
    TypeWriter("그러나 당신은 단호하게 말한다.\n", 40);
    TypeWriter("\"아직 끝나지 않았습니다.\"\n", 50);

    TypeWriter("이장이 눈을 깜빡이며 의아한 표정을 지었지만\n", 40);
    TypeWriter("당신은 아무말도 하지 않을 채 이장을 지나친다.\n", 40);
    TypeWriter("당신은 아마도 수십 년 동안 잊혀졌을 산속 깊은 동굴로 이끌려 간다.\n\n", 50);

    SetConsoleColor(12);
    TypeWriter("[장소 이동: 숨겨진 동굴 입구]\n", 40);
    SetConsoleColor(7);

    TypeWriter("--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();
}

void Chapter6Explore()
{
    int choice = 0;
    bool fingerFound = false;
    bool ritualMarkFound = false;
    bool diaryFound = false;

    while (true)
    {
        ClearScreen();
        TypeWriter("동굴 안에는 여러 흔적들이 남아 있다. 어디를 조사할까?\n\n", 40);
        TypeWriter(" 1. 낡은 상자\n", 30);
        TypeWriter(" 2. 바닥\n", 30);
        TypeWriter(" 3. 벽 한쪽 구석\n", 30);
        TypeWriter(" 4. 탐색 종료\n\n", 30);
        TypeWriter("선택: ");

        std::cin >> choice;
        ClearScreen();

        switch (choice)
        {
        case 1:
            if (!fingerFound)
            {
                fingerFound = true;
                SetConsoleColor(12);
                TypeWriter("[조사] 낡은 상자 발견\n\n", 40);
                SetConsoleColor(7);
                TypeWriter("상자 안에서 사람들의 잘린 손가락 몇 개가 발견되었다.\n", 50);
                TypeWriter("누군가 이곳에서 끔찍한 일을 벌였음이 분명하다.\n\n", 50);
            }
            else
            {
                TypeWriter("이미 조사한 곳입니다.\n\n", 30);
            }
            break;

        case 2:
            if (!ritualMarkFound)
            {
                ritualMarkFound = true;
                SetConsoleColor(12);
                TypeWriter("[조사] 바닥\n\n", 40);
                SetConsoleColor(7);
                TypeWriter("바닥에 오래도록 지워지지 않은 기이한 문양이 남아 있다.\n", 50);
                TypeWriter("누군가 금단의 의식을 행했음을 암시하는 듯하다.\n\n", 50);
            }
            else
            {
                TypeWriter("이미 조사한 곳입니다.\n\n", 30);
            }
            break;

        case 3:
            if (!diaryFound)
            {
                diaryFound = true;
                SetConsoleColor(12);
                TypeWriter("[조사] 벽 한쪽 구석\n\n", 40);
                SetConsoleColor(7);
                TypeWriter("벽 구석에서 오래된 일기 조각을 발견했다.\n", 50);
                TypeWriter("누군가는 흥분과 광기에 가득 차 이 글을 남겼다.\n", 50);
                TypeWriter("이 글에는 자신을 지키기 위해 만든, 누구도 건드릴 수 없는 금지된 염매가 적혀 있다.\n\n", 60);
            }
            else
            {
                TypeWriter("이미 조사한 곳입니다.\n\n", 30);
            }
            break;

        case 4:
            if (fingerFound && ritualMarkFound && diaryFound)
            {
                TypeWriter("갑자기 머릿속에서 찢어지는 듯한 고통이 밀려온다!\n", 70);
                TypeWriter("눈앞이 깜깜해지고, 잊혀진 기억들이 한꺼번에 쏟아져 내린다.\n", 70);

                SetConsoleColor(12);
                TypeWriter("그 기억 속에서 보이는 것은... 다름 아닌 당신 자신의 얼굴!\n", 70);
                TypeWriter("차갑고 무표정한 그 얼굴이 점점 가까워진다...\n\n", 70);
                SetConsoleColor(7);

                TypeWriter("모든 단서가 맞춰지며, 어렴풋이 진실의 윤곽이 드러난다.\n\n", 50);
                TypeWriter("이제 그 끝을 확인하기 위해, 마지막 걸음을 내딛을 때다.\n\n", 50);

                TypeWriter("--- [계속하려면 Enter] ---\n", 30);
                std::cin.ignore();
                std::cin.get();
                return;
            }
            else
            {
                TypeWriter("아직 모든 단서를 찾지 못했다. 더 조사해야 한다.\n\n", 50);
                Sleep(1000);
            }
            break;

        default:
            TypeWriter("올바른 번호를 입력하세요.\n", 30);
            Sleep(1000);
            break;
        }

        TypeWriter("--- [계속하려면 Enter] ---\n", 30);
        std::cin.ignore();
        std::cin.get();
    }
}
