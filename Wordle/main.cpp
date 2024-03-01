#include <raylib.h>
#include <iostream>
#include "wordle.h"

using namespace std;


int main()
{
    InitWindow(600,800, "Test");
    SetTargetFPS(60);
    Wordle wordle = Wordle();
    while(!WindowShouldClose())
    {
        // int key = GetCharPressed();
        // if(key > 90 && key < 100)
        // {
        //     int keys = GetKeyPressed();
        //     char letter = char(key);
        //     DrawText(TextFormat("%c",letter),250,250,40,WHITE);
        // }
        BeginDrawing();
        wordle.DrawWordle();

        ClearBackground(WHITE);
        wordle.UpdateWordle();
        EndDrawing();
    }
    CloseWindow();
    return 0;
} 