#include "miniGame.h"

bool miniGame::TriggerminiGame()
{
	
	if (rand() % 100 < 100)
	{
		SetConsoleColor(12);
		TypeWriter("\n...무언가가 갑자기 튀어나옵니다!\n", 5);
		SetConsoleColor(7);
		TypeWriter("현실이 일그러지고, 당신의 시야가 뒤틀립니다...\n\n", 50);
		TypeWriter("이상한 힘에 끌려, 낯선 공간으로 떨어졌습니다.\n\n", 50);

		SetConsoleColor(12);
		TypeWriter("차갑고 음산한 숨결이 등골을 타고 흘러내립니다...\n", 10);
		TypeWriter("붉은 눈동자가 어둠 속에서 번뜩이며, 당신을 노려보고 있습니다.\n\n", 10);
		SetConsoleColor(7);

		TypeWriter("빨간 네모는 당신을 쫓는 귀신입니다.\n", 5);
		TypeWriter("초록 네모는 탈출구, 노란 네모는 당신입니다.\n", 5);
		TypeWriter("귀신에게 잡히기 전에 탈출구로 도망치세요!\n\n", 5);

		TypeWriter("--- [Enter를 누르면 미니게임이 시작됩니다] ---\n", 5);
		std::cin.get();
		ClearScreen();
		
		PlaySound(NULL, 0, 0); // 현재 소리 멈추기
		PlaySound(L"minigame.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		// 미로 크기 조정 가능
		miniGame minigame(21);



		minigame.Run();

		if (minigame.IsGameOver())
		{
			return true;
		}

		TypeWriter("\n정신을 차려보니, 다시 돌아와 있었습니다...\n", 50);
		SleepMs(1000);
		}
	return false;
}
void miniGame::Run()
{
	InitDoubleBuffering();
	bool needRedraw = true;

	while (true) {
		if (needRedraw) {
			Draw();
			needRedraw = false;
		}

		if (IsGameOver()) {
			SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));

			ClearScreen();

			SetConsoleColor(12);
			TypeWriter("\n악령의 눈동자와 마주쳤습니다...\n", 40);
			TypeWriter("당신을 알아챈 악령이 다가옵니다.\n", 40);
			SetConsoleColor(7);
			break; // 이후 전투 로직으로 넘어가겠지?
		}

		if (HasEscaped()) {
			SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));

			ClearScreen();

			SetConsoleColor(10);
			TypeWriter("숨통이 트입니다... 출구에 도착했습니다!\n", 20);
			TypeWriter("당신은 무사히 이 악몽에서 벗어났습니다.\n", 20);
			SetConsoleColor(7);
			break;
		}


		if (_kbhit()) {
			int key = _getch();
			int dRow = 0, dCol = 0;
			if (key == 224) {
				key = _getch();
				if (key == 72) dRow = -1;
				else if (key == 80) dRow = 1;
				else if (key == 75) dCol = -1;
				else if (key == 77) dCol = 1;

				int nr = player.row + dRow;
				int nc = player.col + dCol;

				if (isValidCell(nr, nc) && !wall[nr][nc]) {
					player = { nr, nc };
					needRedraw = true;
				}
			}
		}

		ghostCounter++;
		if (ghostCounter >= ghostSpeed) {
			MoveGhost();
			ghostCounter = 0;
			needRedraw = true;
		}

		Sleep(10);
	}

	system("pause");
}
