#include "wordle.h"


Wordle::Wordle()
{
    NewWordle();
}

void Wordle::UpdateWordle()
{
    if(!completed)
    {
        if(wordle.size() <=4)
        {
            KeyInput();
        }
        if(IsKeyPressed(KEY_BACKSPACE) && !(wordle.empty()))
        {
        wordle.pop_back();
        }
        if(IsKeyPressed(KEY_ENTER) && wordle.size() == 5)
        {
            CheckWordle();
        }
    }
    

    for(int i = 0; i < wordPosLineList[wordleLineIndex].size(); i++ )
    {
        wordPosLineList[wordleLineIndex][i].letter = wordle[i];
        if(wordle.size() < i)
        {
            wordPosLineList[wordleLineIndex][i].letter = '\0';
        }
    }
}

void Wordle::DrawWordle()
{
    DrawText("WORDLE",GetScreenWidth()/2 - 100, 50, 50, GREEN);
    for(auto& wordLine : wordPosLineList)
    {
        for(auto& word : wordLine)
        {
            DrawRectangleRec(word.rec,word.color);
            DrawText(TextFormat("%c",word.letter),word.rec.x + 20,word.rec.y + 20,50,BLACK);
            DrawRectangleLinesEx(word.rec,2,LIGHTGRAY);
        }
    }
    if(completed)
    {
        DrawRectangleLines(50,100,500,600,BLACK);
        DrawRectangle(50,100,500,600,GRAY);
        DrawRectangle(225,600,150,50,GREEN);
        DrawText("New Game",250,620,20,BLACK);
        DrawText("The correct Word", 150,120,30,BLACK);
        DrawText(correctWordle.c_str(),200,160,50,BLACK);
        DrawText("You completed in", 150, 220, 30, BLACK);
        DrawText(TextFormat("%i", wordleLineIndex), 200, 250, 40, BLACK);
        if(wordleLineIndex == 1)
        {
            DrawText("Try", 230, 250, 40, BLACK);
        }
        else
        {
            DrawText("Tries", 230, 250, 40, BLACK);
        }
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if(mouseX >= 225 && mouseX <= 375 && mouseY >= 600 && mouseY <= 650)
            {
                NewWordle();
            }
        }
    }
    DrawText(TextFormat(correctWordle.c_str()),50,50,20,BLACK);
    DrawRectangle(GetScreenWidth()/2 - 75, GetScreenHeight() - 100,160,50, GREEN);
    DrawText("ENTER",GetScreenWidth()/2 - 65, GetScreenHeight() - 90,40,WHITE);

}

void Wordle::NewWordle()
{

    std::string current;
    std::ifstream words("data.csv.txt");
    do{
        std::getline(words,current);
        WordsFromFile.push_back(current);
    }while(!words.eof());
    words.close();
    correctWordle = WordsFromFile.at( rand() % WordsFromFile.size()); 


    correctWordleList = {"HELLO","EAGLE","CRAZY","FIELD","JUMPY","HIPPO",
                        "EARLY","FABLE","HABIT","LABOR","SABER","VAGUE",
                        "WACKY","ADMIT","BACON"};
    completed = false;
    rectPosX = 100;
    rectPosY = 125;
    wordPosLine.clear();
    wordPosLineList.clear();
    for(int i = 1; i <= 30; i++)
    {
        Word word;
        word.rec = {(float)rectPosX,(float)rectPosY,75,75};
        word.color = WHITE;
        word.letter = char(0);
        rectPosX += 80;
        wordPosLine.push_back(word);
        if(i%5 == 0)
        {
            rectPosX = 100;
            rectPosY += 80;
            wordPosLineList.push_back(wordPosLine);
            wordPosLine.clear();
        } 
    }
    wordle = "";
    wordleLineIndex = 0;
}

void Wordle::CheckWordle()
{
    
    for(auto& word: WordsFromFile)
    {
        if(wordle == word)
        {
            for(int i = 0; i < wordle.size(); i++)
            {
                wordPosLineList[wordleLineIndex][i].color = GRAY;

                for(int j = 0; j < correctWordle.size();j++)
                {
                    if(wordle[i] == correctWordle[j] && i != j)
                    {
                        wordPosLineList[wordleLineIndex][i].color = ORANGE;
                    }
                }
                if(wordle[i] == correctWordle[i])
                {
                    wordPosLineList[wordleLineIndex][i].color = GREEN;
                }
            }
            if(wordle == correctWordle)
            {
                completed = true;
            }
            wordle = "";
            wordleLineIndex++;
        }
    }    
}

void Wordle::KeyInput()
{
    if(IsKeyPressed(KEY_A))
    {
        wordle += "A";
    }
    if(IsKeyPressed(KEY_B))
    {
        wordle += "B";
    }
    if(IsKeyPressed(KEY_C))
    {
        wordle += "C";
    }
    if(IsKeyPressed(KEY_D))
    {
        wordle += "D";
    }
    if(IsKeyPressed(KEY_E))
    {
        wordle += "E";
    }
    if(IsKeyPressed(KEY_F))
    {
        wordle += "F";
    }
    if(IsKeyPressed(KEY_G))
    {
        wordle += "G";
    }
    if(IsKeyPressed(KEY_H))
    {
        wordle += "H";
    }
    if(IsKeyPressed(KEY_I))
    {
        wordle += "I";
    }
    if(IsKeyPressed(KEY_J))
    {
        wordle += "J";
    }
    if(IsKeyPressed(KEY_K))
    {
        wordle += "K";
    }
    if(IsKeyPressed(KEY_L))
    {
        wordle += "L";
    }
    if(IsKeyPressed(KEY_M))
    {
        wordle += "M";
    }
    if(IsKeyPressed(KEY_N))
    {
        wordle += "N";
    }
    if(IsKeyPressed(KEY_P))
    {
        wordle += "P";
    }
    if(IsKeyPressed(KEY_Q))
    {
        wordle += "Q";
    }
    if(IsKeyPressed(KEY_R))
    {
        wordle += "R";
    }
    if(IsKeyPressed(KEY_O))
    {
        wordle += "O";
    }
    if(IsKeyPressed(KEY_S))
    {
        wordle += "S";
    }
    if(IsKeyPressed(KEY_T))
    {
        wordle += "T";
    }
    if(IsKeyPressed(KEY_U))
    {
        wordle += "U";
    }
    if(IsKeyPressed(KEY_V))
    {
        wordle += "V";
    }
    if(IsKeyPressed(KEY_W))
    {
        wordle += "W";
    }
    if(IsKeyPressed(KEY_X))
    {
        wordle += "X";
    }
    if(IsKeyPressed(KEY_Y))
    {
        wordle += "Y";
    }
    if(IsKeyPressed(KEY_Z))
    {
        wordle += "Z";
    }
}
