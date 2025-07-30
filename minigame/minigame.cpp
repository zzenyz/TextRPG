#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <chrono>

using namespace std;

void setColor(int fg, int bg = 0) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bg << 4) | fg);
}

struct Pos {
    int row, col;
    Pos(int r = -1, int c = -1) : row(r), col(c) {}

    bool operator==(const Pos& other) const {
        return row == other.row && col == other.col;
    }

    bool operator!=(const Pos& other) const {
        return !(*this == other);
    }

    bool operator<(const Pos& other) const {
        if (row == other.row) return col < other.col;
        return row < other.row;
    }
};

class Game {
private:
    int size;
    vector<vector<bool>> wall;
    Pos player, ghost, exitPos;

    int ghostCounter = 0;
    int ghostSpeed = 2;

    bool isValidCell(int r, int c) {
        return r >= 0 && r < size && c >= 0 && c < size;
    }

    void GenerateMaze_Prim() {
        wall.assign(size, vector<bool>(size, true));
        

        auto isInBounds = [&](int r, int c) {
            return r > 0 && r < size - 1 && c > 0 && c < size - 1;
            };

        vector<Pos> wallList;
        Pos start(1, 1);
        wall[start.row][start.col] = false;

        int dr[4] = { -2, 2, 0, 0 };
        int dc[4] = { 0, 0, -2, 2 };

        // 시작 지점 주변 벽 리스트에 추가
        for (int i = 0; i < 4; i++) {
            int nr = start.row + dr[i];
            int nc = start.col + dc[i];
            if (isInBounds(nr, nc)) wallList.push_back(Pos(nr, nc));
        }

        while (!wallList.empty()) {
            int idx = rand() % wallList.size();
            Pos wallPos = wallList[idx];
            wallList.erase(wallList.begin() + idx);

            // 이 벽의 이웃 두 칸 중 하나가 통로인지 확인
            vector<Pos> neighbors;
            for (int i = 0; i < 4; i++) {
                int nr = wallPos.row + dr[i];
                int nc = wallPos.col + dc[i];
                if (isInBounds(nr, nc) && !wall[nr][nc]) {
                    neighbors.push_back(Pos(nr, nc));
                }
            }

            if (!neighbors.empty()) {
                Pos connected = neighbors[rand() % neighbors.size()];
                int midR = (wallPos.row + connected.row) / 2;
                int midC = (wallPos.col + connected.col) / 2;

                wall[wallPos.row][wallPos.col] = false;
                wall[midR][midC] = false;

                for (int i = 0; i < 4; i++) {
                    int nr = wallPos.row + dr[i];
                    int nc = wallPos.col + dc[i];
                    if (isInBounds(nr, nc) && wall[nr][nc])
                        wallList.push_back(Pos(nr, nc));
                }
            }
        }
    }

    bool IsReachable(Pos from, Pos to) {
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        queue<Pos> q;
        q.push(from);
        visited[from.row][from.col] = true;

        int dr[4] = { -1, 1, 0, 0 };
        int dc[4] = { 0, 0, -1, 1 };

        while (!q.empty()) {
            Pos cur = q.front(); q.pop();
            if (cur == to) return true;

            for (int i = 0; i < 4; i++) {
                int nr = cur.row + dr[i];
                int nc = cur.col + dc[i];
                if (nr < 0 || nr >= size || nc < 0 || nc >= size) continue;
                if (visited[nr][nc] || wall[nr][nc]) continue;

                visited[nr][nc] = true;
                q.push(Pos(nr, nc));
            }
        }
        return false;
    }


    Pos getRandomEmptyCell() {
        int r, c;
        do {
            r = rand() % size;
            c = rand() % size;
        } while (wall[r][c]); // 벽이면 다시 뽑기
        return Pos(r, c);
    }

    
    void MoveGhost() {
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        queue<Pos> q;
        map<Pos, Pos> parent;
        int dr[4] = { -1, 1, 0, 0 };
        int dc[4] = { 0, 0, -1, 1 };

        q.push(ghost);
        visited[ghost.row][ghost.col] = true;

        while (!q.empty()) {
            Pos cur = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = cur.row + dr[i];
                int nc = cur.col + dc[i];
                if (!isValidCell(nr, nc)) continue;
                if (visited[nr][nc] || wall[nr][nc]) continue;

                visited[nr][nc] = true;
                Pos next(nr, nc);
                parent[next] = cur;

                if (next == player) {
                    Pos step = next;
                    while (parent[step] != ghost) {
                        step = parent[step];
                    }
                    ghost = step;
                    return;
                }

                q.push(next);
            }
        }
    }

public:
    Game(int s = 21) : size(s) {
        srand((unsigned int)time(NULL));
        GenerateMaze_Prim();
        

        // 플레이어, 귀신, 출구 랜덤 배치 (벽이 아닌 곳)
        player = getRandomEmptyCell();
        ghost = getRandomEmptyCell();
        exitPos = getRandomEmptyCell();

        
        
    }

    void Draw() {
        clearScreen();
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                if (ghost.row == r && ghost.col == c) {
                    setColor(14); cout << "G"; setColor(15);
                }
                else if (player.row == r && player.col == c) {
                    setColor(12); cout << "P"; setColor(15);
                }
                else if (exitPos.row == r && exitPos.col == c) {
                    setColor(10); cout << "E"; setColor(15);
                }
                else if (wall[r][c]) {
                    setColor(8); cout << "■"; setColor(15);
                }
                else {
                    cout << "  ";
                }
            }
            cout << "\n";
        }
    }

    bool IsGameOver() {
        return player == ghost;
    }

    bool HasEscaped() {
        return player == exitPos;
    }

    void clearScreen() {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD count;
        DWORD cellCount;
        COORD homeCoords = { 0, 0 };

        if (hStdOut == INVALID_HANDLE_VALUE) return;

        if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;

        FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count);
        SetConsoleCursorPosition(hStdOut, homeCoords);
    }


    void Run() {
        

        bool needRedraw = true;

        while (true) {
            if (needRedraw) {
                Draw();
                needRedraw = false;
            }

            if (IsGameOver()) {
                cout << "게임 종료! 귀신에게 잡혔습니다.\n";
                break;
            }
            if (HasEscaped()) {
                cout << "탈출 성공! 출구에 도착했습니다.\n";
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
                Sleep(50);
            }

            ghostCounter++;
            if (ghostCounter >= ghostSpeed) {
                MoveGhost();
                ghostCounter = 0;
                needRedraw = true;
            }

            Sleep(50);
           
        }

        system("pause");
    }

};

int main() {
    Game game(21);
    game.Run();
    return 0;
}
