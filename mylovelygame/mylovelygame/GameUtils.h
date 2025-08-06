#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <string>
#include <vector>



void TypeWriter(const std::string& text, int delayMs = 30);
void ClearScreen();
void SetConsoleColor(int color); // 옵션: 색상 바꾸고 싶을 때
void SleepMs(int ms);
void FlashInvertColors(int times, int delayMs, const std::string& art);
void ShowGhost(int rank);
void ShowTItle();