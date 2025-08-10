#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include "GameUtils.h"

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

class miniGame {
private:
    int size;
    std::vector<std::vector<bool>> wall;
    Pos player, ghost, exitPos;

    int ghostCounter = 0;
    float ghostSpeed = 10;

    HANDLE hBuffer[2];
    int activeBuffer = 0;

    bool isValidCell(int r, int c) {
        return r >= 0 && r < size && c >= 0 && c < size;
    }

    void GenerateMaze_Prim() {
        wall.assign(size, std::vector<bool>(size, true));

        auto isInBounds = [&](int r, int c) {
            return r > 0 && r < size - 1 && c > 0 && c < size - 1;
            };

        std::vector<Pos> wallList;
        Pos start(1, 1);
        wall[start.row][start.col] = false;

        int dr[4] = { -2, 2, 0, 0 };
        int dc[4] = { 0, 0, -2, 2 };

        for (int i = 0; i < 4; i++) {
            int nr = start.row + dr[i];
            int nc = start.col + dc[i];
            if (isInBounds(nr, nc)) wallList.push_back(Pos(nr, nc));
        }

        while (!wallList.empty()) {
            int idx = rand() % wallList.size();
            Pos wallPos = wallList[idx];
            wallList.erase(wallList.begin() + idx);

            std::vector<Pos> neighbors;
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

    Pos getRandomEmptyCell() {
        int r, c;
        do {
            r = rand() % size;
            c = rand() % size;
        } while (wall[r][c]);
        return Pos(r, c);
    }

    void MoveGhost() {
        std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
        std::queue<Pos> q;
        std::map<Pos, Pos> parent;
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

    void InitDoubleBuffering() {
        CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };
        for (int i = 0; i < 2; i++) {
            hBuffer[i] = CreateConsoleScreenBuffer(
                GENERIC_READ | GENERIC_WRITE, 0, NULL,
                CONSOLE_TEXTMODE_BUFFER, NULL
            );
            SetConsoleCursorInfo(hBuffer[i], &cursorInfo);
        }
        SetConsoleActiveScreenBuffer(hBuffer[activeBuffer]);
    }

public:
    miniGame(int s = 21) : size(s) {
        srand((unsigned int)time(NULL));
        GenerateMaze_Prim();
        player = getRandomEmptyCell();
        ghost = getRandomEmptyCell();
        exitPos = getRandomEmptyCell();
    }

    void Draw() {
        HANDLE backBuffer = hBuffer[1 - activeBuffer];
        COORD bufferSize = { (SHORT)(size * 2), (SHORT)size };
        COORD bufferCoord = { 0, 0 };
        SMALL_RECT writeRegion = { 0, 0, bufferSize.X - 1, bufferSize.Y - 1 };

        std::vector<CHAR_INFO> buffer(bufferSize.X * bufferSize.Y);

        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                int idx = r * bufferSize.X + c * 2;

                CHAR_INFO& ch1 = buffer[idx];
                CHAR_INFO& ch2 = buffer[idx + 1];

                WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
                wchar_t symbol = L'■';

                if (player.row == r && player.col == c) {
                    color = FOREGROUND_RED | FOREGROUND_GREEN; // Yellow
                }
                else if (ghost.row == r && ghost.col == c) {
                    color = FOREGROUND_RED; // Red
                }
                else if (exitPos.row == r && exitPos.col == c) {
                    color = FOREGROUND_GREEN; // Green
                }
                else if (wall[r][c]) {
                    color = FOREGROUND_INTENSITY; // Gray
                }
                else {
                    ch1.Char.UnicodeChar = L' ';
                    ch1.Attributes = color;
                    ch2.Char.UnicodeChar = L' ';
                    ch2.Attributes = color;
                    continue;
                }

                ch1.Char.UnicodeChar = symbol;
                ch1.Attributes = color;
                ch2.Char.UnicodeChar = symbol;
                ch2.Attributes = color;
            }
        }

        WriteConsoleOutputW(backBuffer, buffer.data(), bufferSize, bufferCoord, &writeRegion);
        SetConsoleActiveScreenBuffer(backBuffer);
        activeBuffer = 1 - activeBuffer;
    }

    bool IsGameOver() {
        return player == ghost;
    }

    bool HasEscaped() {
        return player == exitPos;
    }

    void Run();
    bool TriggerminiGame();
};