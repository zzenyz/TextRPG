#include "miniGame.h"
void miniGame::TriggerminiGame()
{
	if (rand() % 100 < 100)
	{
		SetConsoleColor(12);
		TypeWriter("\n...뭔가가 갑자기 나타났다!\n", 5);
		SetConsoleColor(7);
		TypeWriter("기묘한 공간에 끌려들어갑니다...\n", 50);

		// 미로 크기 조정 가능
		miniGame minigame(21);
		minigame.Run();

		std::cout << "\n정신을 차려보니 다시 묘실에 서 있다...\n";
		// 성공 여부에 따라 아이템 제공 가능
	}
	else return;
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
			SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE)); // ✅ 여기!
			SetConsoleColor(12);
			TypeWriter("게임 종료! 귀신에게 잡혔습니다...\n", 50);
			SetConsoleColor(7);

			ClearScreen();
			break;
		}
		if (HasEscaped()) {
			SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE)); // ✅ 여기!
			TypeWriter("탈출 성공!출구에 도착했습니다.\n", 20);
			ClearScreen();
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
