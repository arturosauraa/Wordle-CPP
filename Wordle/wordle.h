#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Wordle
{
public:
    struct Word
    {
        Rectangle rec;
        char letter;
        Color color;
    };

    Wordle();
    void UpdateWordle();
    void DrawWordle();
    void NewWordle();
    void CheckWordle();
    void KeyInput();
private:
    std::vector<std::string> correctWordleList;
    std::string correctWordle;
    std::string wordle;

    std::vector<Word> wordPosLine;
    std::vector<std::vector<Word>> wordPosLineList;
    int wordleLineIndex;
    int letterIndex;
    int rectPosX;
    int rectPosY;
    int completed;
    std::vector<std::string> WordsFromFile;
};