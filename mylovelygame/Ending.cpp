#include "Ending.h"
void BadEndingSequence()
{
    ClearScreen();

    // 폐가에서 이장 등장
    TypeWriter("[폐가 앞]\n", 30);
    TypeWriter("이장이 당신을 마주한다. 얼굴에는 안도감이 가득하다.\n", 40);
    TypeWriter("\"원혼들은 모두 떠난 것 같네. 마을 문제도 해결된 듯하고.\"\n", 50);
    TypeWriter("\"이제는 마음을 놓아도 될 거야.\"\n\n", 50);

    TypeWriter("하지만 당신의 마음 한켠은 여전히 편하지 않다.\n", 40);
    TypeWriter("뭔가 설명할 수 없는 불안이 밀려오고, 중요한 무언가를 놓친 듯한 기분이 든다.\n\n", 50);

    TypeWriter("--- [계속하려면 Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();

    // 집으로 돌아감
    TypeWriter("집으로 돌아왔지만, 당신의 마음은 무겁다.\n", 40);
    TypeWriter("집 안 곳곳에 희미한 잔상이 스며들고, 누군가의 시선이 느껴진다.\n", 50);
    TypeWriter("중요한 무언가를 잊은 듯한 불안이 가슴속을 파고든다.\n\n", 50);

    TypeWriter("[1] 불안을 떨치려 잠자리에 든다.\n", 30);
    TypeWriter("[2] 집 안을 조사해 본다.\n", 30);

    int choice = 0;
    while (true) {
        std::cout << "선택지를 입력하세요 (1 또는 2): ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) break;
        std::cout << "올바른 선택지를 입력하세요.\n";
    }

    ClearScreen();

    switch (choice) {
    case 1:
        BadEnding_Sleep();
        break;
    case 2:
        BadEnding_Investigate();
        break;
    }
}

void BadEnding_Sleep()
{
    ClearScreen();

    TypeWriter("불안한 마음을 억누르며 잠자리에 들었지만,\n", 40);
    TypeWriter("깊은 잠은 찾아오지 않았다.\n", 40);
    TypeWriter("꿈속에서 원혼들의 음산한 속삭임이 점점 가까워진다.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"드디어… 네가 돌아왔구나…\"\n", 70);
    TypeWriter("\"복수는 이제 시작이다…\"\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("어둠 속에서 형체들이 서서히 모습을 드러내고, 당신을 향해 다가온다.\n", 50);
    TypeWriter("공포가 정신을 짓누르고, 점점 현실과 꿈의 경계가 무너진다.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"누구야! 누구냐고! 이게 대체 뭐야!\"\n", 80);
    TypeWriter("당신의 비명은 허공에 메아리치고, 미쳐버린 정신은 혼돈 속으로 빠져든다.\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("…당신은 결국 공포와 광기에 삼켜지고 만다.\n\n", 70);

    SetConsoleColor(12);
    TypeWriter("--- [배드엔딩] ---\n", 50);
    TypeWriter("당신의 이야기는 여기서 멈춘다.\n\n", 50);
    TypeWriter("--- [게임 종료] ---\n", 40);
    SetConsoleColor(7);

    std::cin.get();
    ClearScreen();
}

void BadEnding_Investigate()
{
    ClearScreen();

    TypeWriter("불길한 기운에 사로잡혀 집안을 살피던 당신,\n", 40);
    TypeWriter("벽에는 손자국이 번져 있고, 어둠 속에서 무언가가 지켜보고 있다.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"네가… 바로 그 자였구나…\"\n", 70);
    TypeWriter("\"복수는 반드시 이루어질 것이다…\"\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("등 뒤에서 느껴지는 차가운 손길에 몸이 얼어붙고,\n", 50);
    TypeWriter("숨이 막히는 공포가 정신을 갉아먹는다.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"누구야! 당장 나와!!!\"\n", 80);
    TypeWriter("당신은 미쳐버린 듯 비명을 지르며, 정신이 산산조각 난다.\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("원혼들이 점점 가까워지고, 결국 당신은 절망 속에 삼켜진다.\n\n", 60);

    SetConsoleColor(12);
    TypeWriter("End.\n", 100);
    TypeWriter("- Ignorance Was Never Innocent -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("무지했던 당신은 결국 대가를 치르게 되었다.\n", 50);
    TypeWriter("모르는 것도… 죄였다.\n\n", 50);
    TypeWriter("--- [게임 종료] ---\n", 40);

    std::cin.get();
    ClearScreen();
}

void HappyEnding()
{
    ClearScreen();

    TypeWriter("마을의 원혼들이 떠나고, 공기는 한결 가벼워졌다.\n", 40);
    TypeWriter("당신은 깊은 숨을 내쉬며 오랜 짐을 내려놓은 듯한 평화를 느낀다.\n", 50);
    TypeWriter("어둠 속을 헤매던 마음도 이제는 밝은 빛으로 스며든다.\n\n", 50);

    TypeWriter("멀리서 이장이 다가와 말한다.\n", 40);
    SetConsoleColor(11);
    TypeWriter("\"이제 마을도, 선생님도 모두 조금은 안정을 찾은 것 같군요.\"\n\n", 60);
    SetConsoleColor(7);

    TypeWriter("하지만 마음 한 켠 어딘가, 아직 해결하지 못한 무언가가 남아 있음을 느낀다.\n", 50);
    TypeWriter("그럼에도 앞으로는 더 나은 삶을 살아야 한다는 다짐이 생긴다.\n\n", 50);

    TypeWriter("…그리고 당신은 조용히 고개를 끄덕이며 새로운 시작을 맞이한다.\n\n", 60);

    SetConsoleColor(14);
    TypeWriter("End.\n", 100);
    TypeWriter("- Rebirth -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("모든 것을 되돌려놓은 듯하지만, 당신은 끝내 전부를 기억하지 못했다.\n", 50);
    TypeWriter("그러나 마음 어딘가에 남은 막연한 죄책감은 당신을 조용히 이끈다.\n", 50);
    TypeWriter("이제는 그저, 다시는 같은 실수를 저지르지 않기를 바라며 살아갈 뿐이다.\n\n", 50);

    TypeWriter("--- [게임 종료] ---\n", 40);

    std::cin.get();
    ClearScreen();
}

void BadEnding2()
{
    ClearScreen();

    SetConsoleColor(12);
    TypeWriter("모든 진실이 드러난 순간,\n", 50);
    TypeWriter("원한의 어둠이 당신을 에워싼다.\n", 50);
    TypeWriter("처음에는 미세한 속삭임 같았지만,\n", 50);
    TypeWriter("이내 그 소리는 점점 커져, 머릿속을 찢어놓는다.\n\n", 70);

    TypeWriter("몸이 점점 무거워지고, 숨이 막힌다.\n", 50);
    TypeWriter("손끝이 싸늘하게 식어가고, 차가운 공포가 온몸을 감싼다.\n", 50);
    TypeWriter("당신은 절망 속에서 뒤로 물러나려 하지만,\n", 50);
    TypeWriter("발걸음은 무겁게 땅에 붙어 움직이지 않는다.\n\n", 70);

    TypeWriter("원혼들의 분노가 한데 모여 거대한 그림자가 되어 당신을 덮친다.\n", 50);
    TypeWriter("그 어둠은 무자비하게 당신을 집어삼키고,\n", 50);
    TypeWriter("마지막 의식마저 무산된 채, 당신은 서서히 사라져 간다.\n\n", 70);

    TypeWriter("깊은 밤, 폐가에는 차가운 바람만이 스산하게 흐른다.\n", 50);
    TypeWriter("그 어디에도 당신의 흔적은 남아 있지 않다.\n\n", 50);

    SetConsoleColor(12);
    TypeWriter("End.\n", 100);
    TypeWriter("- Too Late -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("진실은 마침내 드러났지만,\n", 50);
    TypeWriter("그 어둠은 이미 당신을 향해 움직이고 있었다.\n", 50);
    TypeWriter("발버둥도, 후회도, 외침도… 아무것도 닿지 못했다.\n\n", 50);
    TypeWriter("당신은 그날 밤, 그림자 속으로 사라졌다.\n", 50);
    TypeWriter("그리고 세상은, 마치 아무 일도 없었던 듯 계속 흘러간다.\n\n", 50);

    TypeWriter("--- [게임 종료] ---\n", 40);
    std::cin.get();
    ClearScreen();
}
void TrueEnding()
{
    ClearScreen();

    SetConsoleColor(14); // 빛나는 황금빛
    TypeWriter("갑작스레 뇌리를 스치는 기억의 파편들...\n", 60);
    TypeWriter("잊고 있던 전생의 고통과 실패, 그리고 금기된 주술의 진실.\n", 60);
    TypeWriter("그 모든 것이 선명하게 되살아난다.\n\n", 60);

    TypeWriter("가슴 깊은 곳에서 끓어오르는 의지가 솟구친다.\n", 50);
    TypeWriter("두려움과 후회는 이제 사라지고, 오직 완성에 대한 집념만이 남았다.\n\n", 60);

    TypeWriter("어둠 속에서 천천히 일어선 당신은 다시 한 번 의식을 시작한다.\n", 50);
    TypeWriter("전생에 실패했던 염매, 이제는 당신의 손에서 완성된다.\n", 50);
    TypeWriter("차가운 바람이 불어오고, 신비로운 기운이 몸을 감싼다.\n\n", 60);

    SetConsoleColor(13); // 신비로운 보라빛
    TypeWriter("주술이 완성되자, 세상이 흔들리고 시간마저 굴복하는 듯하다.\n", 50);
    TypeWriter("당신 안에서 강력한 힘이 폭발하며, 이전의 인간은 사라져 간다.\n\n", 60);

    TypeWriter("이제 당신은 더 이상 평범한 존재가 아니다.\n", 50);
    TypeWriter("신조차 함부로 건드릴 수 없는, 또 다른 차원의 존재로 거듭났다.\n\n", 60);

    TypeWriter("차가운 어둠과 찬란한 빛이 공존하는 경계에서,\n", 50);
    TypeWriter("진정한 자유와 힘이 당신을 기다린다.\n\n", 70);

    SetConsoleColor(14);
    TypeWriter("…이것이 끝이자 새로운 시작이다.\n\n", 70);

    SetConsoleColor(14);
    TypeWriter("End.\n", 100);
    TypeWriter("- The Ritual Was Completed -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("당신은 끝내 금기를 넘어섰고,\n", 50);
    TypeWriter("그 힘은 당신을 인간 너머의 존재로 이끌었다.\n\n", 50);
    TypeWriter("더 이상 두려움도, 후회도 없다.\n", 50);
    TypeWriter("세상은 이제 당신을 중심으로 다시 태어난다.\n\n", 50);

    TypeWriter("--- [게임 종료] ---\n", 40);
    std::cin.get();
    ClearScreen();
}
