//#include <iostream>
//#include <windows.h>
//#include "help.h"
//#include <fstream>
//
//using namespace std;
//
//
//void gotoxy(int x, int y);
//
//int XBorder = 800;
//int YBorder = 600;
//
//int Size = 20;
//
//int XSnake[800];
//int YSnake[600];
//
//int SnakeLength = 3;
//int Direction = 2;
//int XFood;
//int YFood;
//
//bool IsGameOver = false;
//bool Exit = false;
//bool Pause = false;
//bool Started = false;
//bool ExitMode = false;
//
//int Score = 0;
//int Speed = 100;
//double Seconds = 0;
//int Minutes = 0;
//
//void setColour(int colour) // PLEASE READ: I got this function from the internet, I am only using it because it looks cool
//{
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(hConsole, colour);
//}
//
//int Level = 1;
//int Mode = 1;
//int Update = 0;
//
//
//int InfiniteWallGrid[40][30] = { 0 }; //for infinite only
//
//int XInf;
//int YInf;
//
//
//int Walls = 1;
//bool Side = false;
//
//void SetInfinite()
//{
//    //for (int i = 0; i < 40; i++)
//    //    for (int j = 0; j < 30; j++)
//    //        InfiniteWallGrid[i][j] = 0;
//
//    do {
//        XInf = rand() % (XBorder / Size - 1);
//        YInf = rand() % (YBorder / Size - 1);
//    } while (XInf!= XSnake[0] && YInf != YSnake[0]);
//
//    bool Limit = false;
//    for (int x = XInf, y = YInf, count = 0; count < 5 && Limit == false; count++)
//    {
//        if (Side) //vertical
//        {
//            InfiniteWallGrid[x][YInf] = 1;
//            x++;
//            if (x >= 40)
//                Limit = true;
//        }
//        else if (!Side) // horizontal
//        {
//            InfiniteWallGrid[XInf][y] = 1;
//            y++;
//            if (y >= 30)
//                Limit = true;
//        }
//    }
//    Side = !Side;
//}
//
//
//
//
//int Cspeed = 100;
//void CustomSpeed()
//{
//    cin.clear();
//    Cspeed = 100;
//    system("cls");
//    gotoxy(10, 5);
//    cout << "Enter speed of snake: ";
//    gotoxy(32, 5);
//    cin >> Cspeed;
//    do
//    {
//        system("cls");
//        if (Cspeed < 10 || Cspeed > 200)
//        {
//            gotoxy(10, 7);
//            cout << "Speed can only be from 10 to 200";
//        }
//        gotoxy(10, 5);
//        cout << "Enter speed of snake: ";
//        gotoxy(32, 5);
//        cin >> Cspeed;
//    } while (Cspeed < 10 || Cspeed > 200);
//
//    Speed = Cspeed;
//
//    system("cls");
//    gotoxy(10, 5);
//    setColour(13);
//    cout << "Speed of snake selected: " << Cspeed;
//    setColour(7);
//    Sleep(1000);
//}
//
//
//int key = 0;
//int wallGrid[40][30] = { 0 }; //for custom only
//
//void Custom()
//{
//    int cursorX = 0;
//    int cursorY = 0;
//    int key;
//
//    system("cls");
//
//    // Draw the initial cursor block
//    myRect(cursorX * Size, cursorY * Size, (cursorX + 1) * Size, (cursorY + 1) * Size, 255, 255, 255);
//
//    while (!ExitMode)
//    {
//        if (isCursorKeyPressed(key))
//        {
//            myRect1(0, 0, XBorder, YBorder, 255, 255, 255);
//            gotoxy(0, 26);
//            cout << "=== Custom Wall Placement Mode ===";
//            setColour(12);
//            gotoxy(0, 28);
//            cout << ">Press Enter to place/delete a wall<";
//            gotoxy(0, 29);
//            cout << ">Press 'A' to remove all walls<";
//            gotoxy(0, 30);
//            cout << ">Press Escape to exit<";
//
//            setColour(7);
//
//            for (int i = 0; i < 40; i++)
//                for (int j = 0; j < 30; j++)
//                    if (wallGrid[i][j] == 1)
//                        myRect(i * Size, j * Size, (i + 1) * Size, (j + 1) * Size, 255, 255, 0);
//                    
//                
//            if (wallGrid[cursorX][cursorY] == 0)
//                myRect1(cursorX * Size, cursorY * Size, (cursorX + 1) * Size, (cursorY + 1) * Size, 0, 0, 0);
//
//            if (key == 1) // Left
//            {
//                cursorX--;
//                if (cursorX < 0)
//                    cursorX = (XBorder / Size) - 1;
//            }
//            else if (key == 3) // Up
//            {
//                cursorY--;
//                if (cursorY < 0)
//                    cursorY = (YBorder / Size) - 1;
//            }
//            else if (key == 2) // Right
//            {
//                cursorX++;
//                if (cursorX >= (XBorder / Size))
//                    cursorX = 0;
//            }
//            else if (key == 4) // Down
//            {
//                cursorY++;
//                if (cursorY >= (YBorder / Size))
//                    cursorY = 0;
//            }
//            else if (key == 5) // Enter
//            {
//                if (wallGrid[cursorX][cursorY] == 0)
//                {
//                    wallGrid[cursorX][cursorY] = 1; // Add wall
//                    myRect(cursorX * Size, cursorY * Size, (cursorX + 1) * Size, (cursorY + 1) * Size, 255, 255, 0);
//                }
//                else if (wallGrid[cursorX][cursorY] == 1)
//                {
//                    wallGrid[cursorX][cursorY] = 0; //remove wall
//                }
//            }
//            else if (key == 10) // Escape key
//            {
//                ExitMode = true; 
//                break; 
//            }
//            else if (key == 6) // A
//            {
//                for (int i = 0; i < 40; i++)
//                    for (int j = 0; j < 30; j++)
//                        wallGrid[i][j] = 0;
//            }
//
//            myRect(cursorX * Size, cursorY * Size, (cursorX + 1) * Size, (cursorY + 1) * Size, 255, 255, 255);
//        }
//    }
//    CustomSpeed();
//
//    system("cls");
//    gotoxy(10, 5);
//    setColour(6);
//    cout << "Exiting Custom Mode...";
//    setColour(7);
//    Sleep(1000);
//}
//
//
//void ChooseLevels()
//{
//    system("cls");
//
//    gotoxy(10, 5);
//    setColour(15);
//    cout << "CHOOSE THE LEVEL OF DIFFICULTY";
//    setColour(7);
//
//    gotoxy(10, 7);
//    cout << "1. Level 1";
//    gotoxy(10, 9);
//    cout << "2. Level 2";
//    gotoxy(10, 11);
//    cout << "3. Level 3";
//    gotoxy(10, 13);
//    cout << "4. Infinite Level";
//
//    gotoxy(10, 14);
//    cout << "Choose a Level by entering the number (1-4): ";
//    cin >> Level;
//
//    if (Level == 1)
//    {
//        gotoxy(10, 16);
//        setColour(15);
//        cout << "Level 1 chosen successfully";
//        setColour(7);
//        Sleep(500);
//    }
//    else if (Level == 2)
//    {
//        gotoxy(10, 16);
//        setColour(15);
//        cout << "Level 2 chosen successfully";
//        setColour(7);
//        Sleep(500);
//    }
//    else if (Level == 3)
//    {
//        gotoxy(10, 16);
//        setColour(15);
//        cout << "Level 3 chosen successfully";
//        setColour(7);
//        Sleep(500);
//    }
//    else if (Level == 4)
//    {
//        gotoxy(10, 16);
//        setColour(15);
//        cout << "Infinite Level chosen successfully";
//        setColour(7);
//        Sleep(500);
//    }
//    else
//    {
//        gotoxy(10, 16);
//        setColour(4);
//        cout << "Invalid option chosen! Please enter again";
//        setColour(7);
//        Sleep(500);
//        ChooseLevels();
//    }
//}
//
//
//void GameModes()
//{
//    while (!ExitMode)
//    {
//        system("cls");
//
//        gotoxy(10, 5);
//        setColour(15);
//        cout << "CHOOSE THE GAME MODE!";
//        setColour(7);
//
//        gotoxy(10, 7);
//        cout << "1. Endless Mode";
//        gotoxy(10, 9);
//        cout << "2. Level Mode";
//        gotoxy(10, 11);
//        cout << "3. Custom Mode";
//        gotoxy(10, 13);
//        cout << "4. Exit";
//
//        gotoxy(10, 16);
//        cout << "Choose a Mode by entering the number (1-3): ";
//        cin >> Mode;
//
//        if (Mode == 1)
//        {
//            gotoxy(10, 17);
//            setColour(15);
//            cout << "Endless mode chosen successfully";
//            setColour(7);
//            Sleep(500);
//            break;
//            ExitMode = true;
//        }
//        else if (Mode == 2)
//        {
//            gotoxy(10, 17);
//            setColour(15);
//            cout << "Level mode chosen successfully";
//            setColour(7);
//            Sleep(500);
//            ChooseLevels();
//            break;
//            ExitMode = true;
//        }
//        else if (Mode == 3)
//        {
//            if (key != 10)
//            {
//                gotoxy(10, 17);
//                setColour(15);
//                cout << "Custom mode chosen successfully";
//                Sleep(500);
//                gotoxy(10, 18);
//                cout << "Entering custom mode";
//                setColour(7);
//                Sleep(500);
//
//                Custom(); 
//                break;
//                ExitMode = true;
//            }
//
//        }
//        else if (Mode == 4)
//        {
//            gotoxy(10, 17);
//            setColour(15);
//            cout << "Exiting...";
//            Sleep(500);
//            ExitMode = true;
//        }
//        else
//        {
//            gotoxy(10, 17);
//            setColour(4);
//            cout << "Invalid option chosen! Please enter again";
//            setColour(7);
//            Sleep(500);
//        }
//    }
//}
//
//int R = 0, G = 255, B = 0;
//int Colour;
//
//void SnakeColour()
//{
//    system("cls");
//
//    gotoxy(10, 5);
//    setColour(15);
//    cout << "CHOOSE SNAKE COLOUR!";
//    setColour(7);
//
//    gotoxy(10, 7);
//    cout << "1. ";
//    setColour(2); 
//    cout << "Green";
//    setColour(7); 
//
//    gotoxy(10, 9);
//    cout << "2. ";
//    setColour(1); 
//    cout << "Blue";
//    setColour(7);
//
//    gotoxy(10, 11);
//    cout << "3. ";
//    setColour(4); 
//    cout << "Red";
//    setColour(7);
//
//    gotoxy(10, 13);
//    cout << "4. ";
//    setColour(7); 
//    cout << "White";
//    setColour(7);
//
//    gotoxy(10, 15);
//    cout << "5. ";
//    setColour(5); 
//    cout << "Purple";
//    setColour(7);
//
//    gotoxy(10, 17);
//    cout << "6. ";
//    setColour(6); 
//    cout << "Yellow";
//    setColour(7);
//
//    gotoxy(10, 19);
//    cout << "Choose a color by entering the number (1-6): ";
//    cin >> Colour;
//
//
//    if (Colour == 1) 
//    {
//        R = 0;
//        G = 255;
//        B = 0;
//    }
//    else if (Colour == 2) 
//    {
//        R = 0;
//        G = 0;
//        B = 255;
//    }
//    else if (Colour == 3) 
//    {
//        R = 255;
//        G = 0;
//        B = 0;
//    }
//    else if (Colour == 4) 
//    {
//        R = 255;
//        G = 255;
//        B = 255;
//    }
//    else if (Colour == 5) 
//    {
//        R = 128;
//        G = 0;
//        B = 128;
//    }
//    else if (Colour == 6) 
//    {
//        R = 255;
//        G = 255;
//        B = 0;
//    }
//    else {
//        setColour(4);
//        gotoxy(10, 20);
//        cout << "Invalid choice! Defaulting to Green." << endl;
//        setColour(7);
//        Sleep(500);
//        R = 0;
//        G = 255;
//        B = 0;
//    }
//    if (Colour <= 6 && Colour >= 1)
//    {
//        gotoxy(10, 20);
//        setColour(15);
//        cout << "Colour changed successfully!";
//        setColour(7);
//        Sleep(500);
//    }
//    system("cls");
//}
//
//void FoodGeneration()
//{
//    bool illegal = true;
//    while (illegal)
//    {
//        XFood = rand() % (XBorder / Size - 1);
//        YFood = rand() % (YBorder / Size - 1);
//        if (Update == 0)
//        {
//            illegal = false;
//        }
//        else if (Update == 1)
//        {
//            illegal = false;
//            if (((XFood * Size) >= 200) && ((XFood * Size) <= 210) && ((YFood * Size) >= 200) && ((YFood * Size) <= 600))
//                illegal = true;
//            else if (((XFood * Size) >= 600) && ((XFood * Size) <= 610) && ((YFood * Size) >= 0) && ((YFood * Size) <= 420))
//                illegal = true;
//        }
//        else if (Update == 2)
//        {
//            illegal = false;
//            if (((XFood * Size) >= 290) && ((XFood * Size) <= 300) && ((YFood * Size) >= 180) && ((YFood * Size) <= 600))
//                illegal = true;
//            else if (((XFood * Size) >= 10) && ((XFood * Size) <= 20) && ((YFood * Size) >= 20) && ((YFood * Size) <= 150))
//                illegal = true;
//            else if (((XFood * Size) >= 10) && ((XFood * Size) <= 150) && ((YFood * Size) >= 10) && ((YFood * Size) <= 20))
//                illegal = true;
//            else if (((XFood * Size) >= 780) && ((XFood * Size) <= 790) && ((YFood * Size) >= 10) && ((YFood * Size) <= 160))
//                illegal = true;
//            else if (((XFood * Size) >= 650) && ((XFood * Size) <= 790) && ((YFood * Size) >= 10) && ((YFood * Size) <= 20))
//                illegal = true;
//            else if (((XFood * Size) >= 520) && ((XFood * Size) <= 530) && ((YFood * Size) >= 0) && ((YFood * Size) <= 260))
//                illegal = true;
//            else if (((XFood * Size) >= 0) && ((XFood * Size) <= 90) && ((YFood * Size) >= 260) && ((YFood * Size) <= 270))
//                illegal = true;
//            else if (((XFood * Size) >= 550) && ((XFood * Size) <= 800) && ((YFood * Size) >= 400) && ((YFood * Size) <= 410))
//                illegal = true;
//        }
//        else if (Update == 3 || (Mode == 2) && (Level == 3))
//        {
//            illegal = false;
//            if (((XFood * Size) >= 200) && ((XFood * Size) <= 210) && ((YFood * Size) >= 400) && ((YFood * Size) <= 600)) 
//                illegal = true; 
//            else if (((XFood * Size) >= 0) && ((XFood * Size) <= 250) && ((YFood * Size) >= 270) && ((YFood * Size) <= 280)) 
//                illegal = true; 
//            else if (((XFood * Size) >= 200) && ((XFood * Size) <= 210) && ((YFood * Size) >= 0) && ((YFood * Size) <= 200)) 
//                illegal = true;
//            else if (((XFood * Size) >= 400) && ((XFood * Size) <= 410) && ((YFood * Size) >= 0) && ((YFood * Size) <= 350))
//                illegal = true; 
//            else if (((XFood * Size) >= 500) && ((XFood * Size) <= 700) && ((YFood * Size) >= 390) && ((YFood * Size) <= 400)) 
//                illegal = true; 
//            else if (((XFood * Size) >= 500) && ((XFood * Size) <= 510) && ((YFood * Size) >= 390) && ((YFood * Size) <= 600)) 
//                illegal = true; 
//            else if (((XFood * Size) >= 600) && ((XFood * Size) <= 800) && ((YFood * Size) >= 200) && ((YFood * Size) <= 210)) 
//                illegal = true; 
//            else if (((XFood * Size) >= 550) && ((XFood * Size) <= 560) && ((YFood * Size) >= 0) && ((YFood * Size) <= 250)) 
//                illegal = true; 
//        }
//        else if (Update == 4)
//        {
//            illegal = false;
//            if (wallGrid[XFood][YFood] == 1)
//                illegal = true;
//        }
//
//        
//    }
//    
//}
//
//
//
//void GameStart() // To inintailze the game
//{
//    system("cls");
//    if (Mode == 3)
//        Speed = Cspeed;
//    else
//        Speed = 100;
//
//    Score = 0;
//    SnakeLength = 3;
//    Direction = 2;
//    Minutes = 0;
//    Seconds = 0;
//
//    if (!Pause)
//        IsGameOver = false;
//
//
//    XSnake[0] = (XBorder) / (2 * Size);
//    YSnake[0] = (YBorder + 0) / (2 * Size);
//
//    XSnake[1] = ((XBorder + 0) / (2 * Size)) - 1;
//    YSnake[1] = (YBorder + 0) / (2 * Size);
//
//    XSnake[2] = ((XBorder + 0) / (2 * Size)) - 2;
//    YSnake[2] = (YBorder + 0) / (2 * Size);
//
//
//    FoodGeneration();
//}
//
//
//int BR = 255, BG = 255, BB = 255; // these are for borders
//
//void SetLevels()
//{
//    if (Mode == 1)
//    {
//        Update = 0;
//    }
//    else if (Mode == 2)
//    {
//        if (Level == 1)
//            Update = 1;
//        else if (Level == 2)
//            Update = 2;
//        else if (Level == 3)
//        {
//            Update == 3;
//        }
//        else if (Level == 4)
//        {
//            Update = 666;
//        }
//    }
//    else if (Mode == 3)
//    {
//        Update = 4;
//    }
//}
//
//
//void updateSnake() 
//{
//    if (Update == 0) 
//    {
//        // for endless mode
//        for (int i = SnakeLength - 1; i > 0; --i) {
//            XSnake[i] = XSnake[i - 1];
//            YSnake[i] = YSnake[i - 1];
//        }
//
//        if (Direction == 1)
//            XSnake[0]--;
//        else if (Direction == 2)
//            XSnake[0]++;
//        else if (Direction == 3)
//            YSnake[0]--;
//        else if (Direction == 4)
//            YSnake[0]++;
//
//        Seconds = Seconds + (Speed / 1000.0);
//        if (Seconds >= 60)
//        {
//            Seconds = Seconds - 60;
//            Minutes = Minutes + 1;
//        }
//
//        if (XSnake[0] == XFood && YSnake[0] == YFood) 
//        {
//            Score = Score + 10;
//            SnakeLength++;
//            if (Speed > 20)
//                Speed = Speed - 5;
//            FoodGeneration();
//        }
//
//        if (XSnake[0] < 0 / Size) 
//            XSnake[0] = (XBorder+0)/Size - 1;  
//        else if (XSnake[0] >= (XBorder+0)/Size) 
//            XSnake[0] = 0;  
//        if (YSnake[0] < 0 / Size) 
//            YSnake[0] = (YBorder + 0) / Size - 1;  
//        else if (YSnake[0] >= (YBorder + 0) /Size) 
//            YSnake[0] = 0;  
//
//        for (int i = 1; i < SnakeLength; ++i) 
//            if (XSnake[0] == XSnake[i] && YSnake[0] == YSnake[i]) 
//                IsGameOver = true;
//    }
//    else if (Update == 1)
//    {
//        // for level 1
//
//        for (int i = SnakeLength - 1; i > 0; --i) 
//        {
//            XSnake[i] = XSnake[i - 1];
//            YSnake[i] = YSnake[i - 1];
//        }
//
//        if (Direction == 1)
//            XSnake[0]--;
//        else if (Direction == 2)
//            XSnake[0]++;
//        else if (Direction == 3)
//            YSnake[0]--;
//        else if (Direction == 4)
//            YSnake[0]++;
//
//        Seconds = Seconds + (Speed / 1000.0);
//        if (Seconds >= 60)
//        {
//            Seconds = Seconds - 60;
//            Minutes = Minutes + 1;
//        }
//
//        if (XSnake[0] == XFood && YSnake[0] == YFood) 
//        {
//            SnakeLength++;
//            Score = Score + 10;
//            if (Speed > 20)
//                Speed = Speed - 5;
//            FoodGeneration();
//        }
//
//        if (XSnake[0] < 0 / Size) {
//            XSnake[0] = (XBorder + 0) / Size - 1;  
//        }
//        else if (XSnake[0] >= (XBorder + 0) / Size) {
//            XSnake[0] = 0;  
//        }
//
//        if (YSnake[0] < 0 / Size) {
//            YSnake[0] = (YBorder + 0) / Size - 1; 
//        }
//        else if (YSnake[0] >= (YBorder + 0) / Size) {
//            YSnake[0] = 0; 
//        }
//
//        int headX = XSnake[0] * Size;
//        int headY = YSnake[0] * Size;
//
//        if (headX >= 200 && headX < 210 && headY >= 200 && headY < 600) {
//            IsGameOver = true;
//        }
//        if (headX >= 600 && headX < 610 && headY >= 0 && headY < 420) {
//            IsGameOver = true;
//        }
//        for (int i = 1; i < SnakeLength; ++i) {
//            if (XSnake[0] == XSnake[i] && YSnake[0] == YSnake[i]) {
//                IsGameOver = true;
//            }
//        }
//    }
//    else if (Update == 2)
//    {
//
//        for (int i = SnakeLength - 1; i > 0; --i)
//        {
//            XSnake[i] = XSnake[i - 1];
//            YSnake[i] = YSnake[i - 1];
//        }
//            
//        if (Direction == 1)
//            XSnake[0]--;
//        else if (Direction == 2)
//            XSnake[0]++;
//        else if (Direction == 3)
//            YSnake[0]--;
//        else if (Direction == 4)
//            YSnake[0]++;
//            
//        Seconds = Seconds + (Speed / 1000.0);
//        if (Seconds >= 60)
//        {
//            Seconds = Seconds - 60;
//            Minutes = Minutes + 1;
//        }
//
//        if (XSnake[0] == XFood && YSnake[0] == YFood) {
//            SnakeLength++;
//            Score = Score + 10;
//            if (Speed > 20)
//                Speed = Speed - 5;
//            FoodGeneration();
//        }
//            
//        if (XSnake[0] < 0 / Size) {
//            XSnake[0] = (XBorder + 0) / Size - 1;
//        }
//        else if (XSnake[0] >= (XBorder + 0) / Size) {
//            XSnake[0] = 0;
//        }
//
//        if (YSnake[0] < 0 / Size) {
//            YSnake[0] = (YBorder + 0) / Size - 1;
//        }
//        else if (YSnake[0] >= (YBorder + 0) / Size) {
//            YSnake[0] = 0;
//        }
//
//        int headX = XSnake[0] * Size;
//        int headY = YSnake[0] * Size;
//            
//        if (headX + Size > 10 && headX < 20 && headY + Size > 20 && headY < 150) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 10 && headX < 150 && headY + Size > 10 && headY < 20) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 780 && headX < 790 && headY + Size > 10 && headY < 160) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 650 && headX < 790 && headY + Size > 10 && headY < 20) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 520 && headX < 530 && headY + Size > 0 && headY < 260) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 290 && headX < 300 && headY + Size > 180 && headY < 600) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 0 && headX < 90 && headY + Size > 260 && headY < 270) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 550 && headX < 800 && headY + Size > 400 && headY < 410) {
//            IsGameOver = true;
//        }
//        for (int i = 1; i < SnakeLength; ++i) {
//            if (XSnake[0] == XSnake[i] && YSnake[0] == YSnake[i]) {
//                IsGameOver = true;
//            }
//        }
//    }
//    else if (Update == 3)
//    {
//        for (int i = SnakeLength - 1; i > 0; --i)
//        {
//            XSnake[i] = XSnake[i - 1];
//            YSnake[i] = YSnake[i - 1];
//        }
//
//        if (Direction == 1)
//            XSnake[0]--;
//        else if (Direction == 2)
//            XSnake[0]++;
//        else if (Direction == 3)
//            YSnake[0]--;
//        else if (Direction == 4)
//            YSnake[0]++;
//
//        Seconds = Seconds + (Speed / 1000.0);
//        if (Seconds >= 60)
//        {
//            Seconds = Seconds - 60;
//            Minutes = Minutes + 1;
//        }
//
//        if (XSnake[0] == XFood && YSnake[0] == YFood) 
//        {
//            SnakeLength++;
//            Score = Score + 10;
//            if (Speed > 20)
//                Speed = Speed - 5;
//            FoodGeneration();
//        }
//
//        if (XSnake[0] < 0 / Size) {
//            XSnake[0] = (XBorder + 0) / Size - 1;
//        }
//        else if (XSnake[0] >= (XBorder + 0) / Size) {
//            XSnake[0] = 0;
//        }
//
//        if (YSnake[0] < 0 / Size) {
//            YSnake[0] = (YBorder + 0) / Size - 1;
//        }
//        else if (YSnake[0] >= (YBorder + 0) / Size) {
//            YSnake[0] = 0;
//        }
//
//        int headX = XSnake[0] * Size;
//        int headY = YSnake[0] * Size;
//
//        if (headX + Size > 200 && headX < 210 && headY + Size > 400 && headY < 600) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 0 && headX < 250 && headY + Size > 270 && headY < 280) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 200 && headX < 210 && headY + Size > 0 && headY < 200) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 400 && headX < 410 && headY + Size > 0 && headY < 350) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 500 && headX < 700 && headY + Size > 390 && headY < 400) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 500 && headX < 510 && headY + Size > 390 && headY < 600) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 600 && headX < 800 && headY + Size > 200 && headY < 210) {
//            IsGameOver = true;
//        }
//        if (headX + Size > 550 && headX < 560 && headY + Size > 0 && headY < 250) {
//            IsGameOver = true;
//        }
//
//        for (int i = 1; i < SnakeLength; ++i) 
//            if (XSnake[0] == XSnake[i] && YSnake[0] == YSnake[i]) 
//                IsGameOver = true;
//    }
//    else if (Update == 4)
//    {
//        for (int i = SnakeLength - 1; i > 0; --i)
//        {
//            XSnake[i] = XSnake[i - 1];
//            YSnake[i] = YSnake[i - 1];
//        }
//
//        if (Direction == 1)
//            XSnake[0]--;
//        else if (Direction == 2)
//            XSnake[0]++;
//        else if (Direction == 3)
//            YSnake[0]--;
//        else if (Direction == 4)
//            YSnake[0]++;
//
//        Seconds = Seconds + (Speed / 1000.0);
//        if (Seconds >= 60)
//        {
//            Seconds = Seconds - 60;
//            Minutes = Minutes + 1;
//        }
//
//        if (XSnake[0] == XFood && YSnake[0] == YFood) 
//        {
//            SnakeLength++;
//            Score = Score + 10;
//            FoodGeneration();
//        }
//
//        if (XSnake[0] < 0 / Size) {
//            XSnake[0] = (XBorder + 0) / Size - 1;
//        }
//        else if (XSnake[0] >= (XBorder + 0) / Size) {
//            XSnake[0] = 0;
//        }
//        if (YSnake[0] < 0 / Size) {
//            YSnake[0] = (YBorder + 0) / Size - 1;
//        }
//        else if (YSnake[0] >= (YBorder + 0) / Size) {
//            YSnake[0] = 0;
//        }
//
//        if (wallGrid[XSnake[0]][YSnake[0]] == 1)
//            IsGameOver = true; //snake collision with them custom wallsss
//
//        for (int i = 1; i < SnakeLength; ++i) {
//            if (XSnake[0] == XSnake[i] && YSnake[0] == YSnake[i]) {
//                IsGameOver = true;
//            }
//        }
//    }
//    else if (Update == 666)
//    {
//        for (int i = SnakeLength - 1; i > 0; --i)
//        {
//            XSnake[i] = XSnake[i - 1];
//            YSnake[i] = YSnake[i - 1];
//        }
//
//        if (Direction == 1)
//            XSnake[0]--;
//        else if (Direction == 2)
//            XSnake[0]++;
//        else if (Direction == 3)
//            YSnake[0]--;
//        else if (Direction == 4)
//            YSnake[0]++;
//
//        Seconds = Seconds + (Speed / 1000.0);
//        if (Seconds >= 60)
//        {
//            Seconds = Seconds - 60;
//            Minutes = Minutes + 1;
//        }
//
//        if (XSnake[0] == XFood && YSnake[0] == YFood)
//        {
//            SnakeLength++;
//            Score = Score + 10;
//            FoodGeneration();
//            if (Walls < 15)
//            {
//                Walls++;
//                SetInfinite();
//            }
//            if (Speed > 20)
//                Speed = Speed - 5;
//        }
//
//        if (XSnake[0] < 0 / Size) {
//            XSnake[0] = (XBorder + 0) / Size - 1;
//        }
//        else if (XSnake[0] >= (XBorder + 0) / Size) {
//            XSnake[0] = 0;
//        }
//        if (YSnake[0] < 0 / Size) {
//            YSnake[0] = (YBorder + 0) / Size - 1;
//        }
//        else if (YSnake[0] >= (YBorder + 0) / Size) {
//            YSnake[0] = 0;
//        }
//
//        if (InfiniteWallGrid[XSnake[0]][YSnake[0]] == 1)
//            IsGameOver = true; //snake collision with them infinite wallsss
//
//        for (int i = 1; i < SnakeLength; ++i) {
//            if (XSnake[0] == XSnake[i] && YSnake[0] == YSnake[i]) {
//                IsGameOver = true;
//            }
//        }
//    }
//}
//
//
//void PausedGame()
//{
//    if (!Pause || IsGameOver)
//    {
//        system("cls");
//        gotoxy(10, 3);
//        setColour(6);
//        cout << "===No Saved/Paused Game Available===\n\n";
//        setColour(15);
//        Sleep(1000);
//    }
//}
//
//void SaveHighScore(int score, int mode)
//{
//    char FileName[25];
//    if (mode == 1) 
//        strcpy_s(FileName, "endless_highscores.txt");
//    else 
//        strcpy_s(FileName, "level_highscores.txt");
//
//
//    int scores[6] = { 0 };
//    int count = 0;
//
//
//    ifstream infile(FileName);
//    while (infile >> scores[count] && count < 5)
//        count++;
//    infile.close();
//
//    scores[count] = score;
//    count++;
//
//    for (int i = 0; i < count - 1; i++)
//        for (int j = 0; j < count - i - 1; j++)
//            if (scores[j] < scores[j + 1])
//            {
//                int temp = scores[j];
//                scores[j] = scores[j + 1];
//                scores[j + 1] = temp;
//            }
//                        
//    ofstream outfile(FileName);
//    for (int i = 0; i < 5 && i < count; i++)
//    {
//        outfile << scores[i] << endl;
//    }
//    outfile.close();
//}
//
//void DisplayHighScores(int mode)
//{
//    char FileName[25];
//    if (mode == 1) // Endless Mode
//        strcpy_s(FileName, "endless_highscores.txt");
//    else           // Level Mode
//        strcpy_s(FileName, "level_highscores.txt");
//
//    ifstream infile(FileName);
//    int CurrentScore;
//    int i = 1, j = 45;
//
//    gotoxy(58, 3);
//    setColour(2);
//    cout << "=== High Scores ===" << endl;
//    setColour(11);
//    if (mode == 1)
//    {
//        gotoxy(j, 5);
//        cout << "=== Endless Mode ===";
//    }
//    else
//    {
//        j = j + 25;
//        gotoxy(j, 5);
//        cout << " === Level Mode ===";
//    }
//    setColour(15);
//
//
//    while (infile >> CurrentScore)
//    {
//        gotoxy(j + 5, 5 + i);
//        cout << i << ". " << CurrentScore << endl;
//        i++;
//    }
//    infile.close();
//
//    if (i == 1) // If no scores were found
//        cout << "No high scores available!" << endl;
//    setColour(7);
//}
//
//void HighScores()
//{
//
//    int i=0;
//    DisplayHighScores(1);
//    DisplayHighScores(2);
//    //while (isCursorKeyPressed(i))
//    //{
//    //    myLine3(480, 50, 1000, 50, 255, 255, 255);
//    //    myLine3(480, 300, 1000, 300, 255, 255, 255);
//    //    myLine3(480, 50, 480, 300, 255, 255, 255);
//    //    myLine3(1000, 50, 1000, 300, 255, 255, 255);
//
//    //}
//    gotoxy(19, 13);
//
//}
//
//
//int Option;
//bool Meow = false;
//
//void MainMenu()
//{
//    while (!Exit) 
//    {
//        system("cls");
//        gotoxy(10, 5);
//        setColour(15);
//        cout << "HUNGRY SNAKE!!";
//        setColour(7);
//
//        gotoxy(8, 7);
//        cout << "1. Start New Game";
//        gotoxy(8, 8);
//        cout << "2. Play Paused Game";
//        gotoxy(8, 9);
//        cout << "3. Choose Modes";
//        gotoxy(8, 10);
//        cout << "4. Choose Snake Colour";
//        gotoxy(8, 11);
//        cout << "5. Exit";
//        gotoxy(5, 13);
//        cout << "Enter Option: ";
//        HighScores();
//
//
//        int Option = 0;
//        cin >> Option;
//
//        if (Option == 1) 
//        {
//            GameStart();
//            IsGameOver = false;
//            Pause = false;
//            Started = true;
//            Meow = false;
//            return;
//        }
//        else if (Option == 2) 
//        {
//            PausedGame();
//
//            Pause = false;
//            IsGameOver = false;
//            return;
//        }
//        else if (Option == 3) 
//        {
//            GameModes();
//        }
//        else if (Option == 4) 
//        {
//            SnakeColour();
//        }
//        else if (Option == 5) 
//        {
//            Exit = true; 
//        }
//        else 
//        {
//            gotoxy(8, 14);
//            setColour(4);
//            cout << "Invalid Option Entered! Enter Again\n";
//            setColour(7);
//            Sleep(700);
//            system("cls");
//        }
//    }
//}
//
//void DrawObstacle()
//{
//    if (Update == 0)
//    {
//        //endless mode: so no obstacles
//    }
//    else if (Update == 1)
//    {
//         //Level 1
//        myRect(200, 200, 210, 600, 255, 255, 0); 
//        myRect(600, 0, 610, 420, 255, 255, 0); 
//    }
//    else if (Update == 2)
//    {
//        //Level 2
//        myRect(290, 180, 300, 600, 255, 255, 0);
//        myRect(10, 20, 20, 150, 255, 255, 0);
//        myRect(10, 10, 150, 20, 255, 255, 0);
//        myRect(780, 10, 790, 160, 255, 255, 0);
//        myRect(650, 10, 790, 20, 255, 255, 0);
//        myRect(520, 0, 530, 260,255,255,0);
//        myRect(0, 260, 90, 270, 255, 255, 0);
//        myRect(550, 400, 800, 410, 255, 255, 0);
//    }
//    else if (Update == 3)
//    {
//        //Level 3
//        myRect(200, 400, 210, 600, 255, 255, 0);
//        myRect(0, 270, 250, 280, 255, 255, 0); 
//        myRect(200, 0, 210, 200, 255, 255, 0); 
//        myRect(400, 0, 410, 350, 255, 255, 0); 
//        myRect(500, 390, 700, 400, 255, 255, 0); 
//        myRect(500, 390, 510, 600, 255, 255, 0); 
//        myRect(600, 200, 800, 210, 255, 255, 0); 
//        myRect(550, 0, 560, 250, 255, 255, 0); 
//    }
//    else if (Update == 4)
//    {
//        //Custom Mode
//        for (int i = 0; i < 40; i++)
//            for (int j = 0; j < 30; j++)
//                if (wallGrid[i][j] == 1)
//                    myRect(i * Size, j * Size, (i + 1) * Size, (j + 1) * Size, 255, 255, 0);
//    }
//    else if (Update == 666)
//    {
//        //infinite mode
//        for (int i = 0; i < 40; i++)
//            for (int j = 0; j < 30; j++)
//                if (InfiniteWallGrid[i][j] == 1)
//                    myRect(i * Size, j * Size, (i + 1) * Size, (j + 1) * Size, 255, 255, 0);
//    }
//}
//
//void DrawFood()
//{
//    myEllipse2(XFood * Size, YFood * Size, (XFood + 1) * Size, (YFood + 1) * Size, 255, 0, 0);
//}
//
//void DrawSnake() 
//{
//    for (int i = 0; i < SnakeLength; ++i) 
//        myRect(XSnake[i] * Size, YSnake[i] * Size, (XSnake[i] + 1) * Size, (YSnake[i] + 1) * Size, R, G, B); 
//}
//
//void DisplayInfo()
//{
//    setColour(3);
//    cout << "Score: " << Score;
//    setColour(9);
//    if (Mode == 1)
//    {
//        cout << "   Endless Mode";
//    }
//    else if (Mode == 2)
//    {
//        if (Level == 1)
//        {
//            cout << "   Level Mode: ";
//            setColour(11);
//            cout << "Level 1";
//        }
//        else if (Level == 2)
//        {
//            cout << "   Level Mode: ";
//            setColour(11);
//            cout << "Level 3";
//        }
//        else if (Level == 3)
//        {
//            cout << "   Level Mode: ";
//            setColour(11);
//            cout << "Level 3";
//        }
//        else if (Level ==4)
//        {
//            cout << "   Level Mode: ";
//            setColour(11);
//            cout << "Infinite Level";
//        }
//        setColour(9);
//    }
//    else if (Mode == 3)
//        cout << "   Custom Mode";
//    setColour(3);
//    int Sec = Seconds;
//    cout << endl << "Time: " << Minutes << ":";
//    if (Sec < 10)
//        cout << "0" << Sec;
//    else
//        cout << Sec;
//    setColour(12);
//    cout << "\n<Press 'esc' to save & exit>";
//    setColour(7);
//}
//
//void ihatemylife()
//{
//    if ((Mode == 2) && (Level == 3))
//        Update = 3;
//}
//
//int main()
//{
//    while (Exit == false)
//    {
//        ExitMode = false;
//        MainMenu();
//        system("cls");
//        Sleep(50);
//        while (!IsGameOver && !Exit && !Pause && Started && !Meow)
//        {
//            gotoxy(0, 26); 
//            SetLevels();
//            ihatemylife();
//            myRect1(0, 0, XBorder, YBorder, BR, BG, BB);
//            DrawObstacle();
//            DrawSnake();
//            DrawFood();
//            DisplayInfo();
//
//            int idk;
//            idk = Direction;
//            if (isCursorKeyPressed(idk)) {
//                if (idk == 1) Direction = 1;  // Left arrow
//                if (idk == 3) Direction = 3; // Right arrow
//                if (idk == 2) Direction = 2;    // Up arrow
//                if (idk == 4) Direction = 4;  // Down arrow
//                if (idk == 10)  //esc key
//                {
//                    Pause = true;
//                    system("cls");
//                    gotoxy(10, 3);
//                    setColour(14);
//                    cout << "===Game Paused and Saved===\n\n";
//                    setColour(15);
//                    Sleep(500);
//                }
//            }
//            idk = Direction;
//            updateSnake();
//            Sleep(Speed);
//        }
//        system("cls");
//
//        if (IsGameOver && Exit == false)
//        {
//            gotoxy(10, 5);
//            setColour(4);
//            cout << "===Game Over!====" << endl;
//            gotoxy(10, 6);
//            setColour(15);
//            cout << "Your score was: " << Score;
//            Sleep(1500);
//            IsGameOver = true;
//            Pause = true;
//            Meow = true;
//            if (Mode == 1) // Endless Mode
//            {
//                SaveHighScore(Score, 1);
//            }
//            else if (Mode == 2) // Level Mode
//            {
//                SaveHighScore(Score, 2); 
//            }
//        }
//    }
//
//    gotoxy(10, 3);
//    setColour(11);
//    cout << "===Exited===\n\n\n\n";
//    setColour(15);
//
//    return 0;
//}