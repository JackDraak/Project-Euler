/*
Project Euler

Smallest multiple
    Problem 5
    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

    What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

This is a functional solution, please solve the problem yourself before you review my code.
@JackDraak
*/

// Used for I/O (input/output).
#include <iostream>
#include <sstream>

// Used to treat the console display as a textbox.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

bool    Continue();
void    Home();
void    Home(bool);
void    Home(int, int);
void    PauseForInput();

int main()
{
    bool finished = false;
    int test = 330000;
    int best = 0;
    Home();
    do {
        int passcount, failcount;
        failcount = 0;
        passcount = 0;
        //Home(22, 0); std::cout << test << "   "; // ID test#
        for (int i = 2; i <= 20; i++)
        {
            if (test % i != 0)
            {
            //    Home(i-1, 0); std::cout << i << ": fail";
                //Home(0, i); std::cout << "0";
                failcount++;
            }
            else {
            //    Home(i-1, 0); std::cout << i << ": pass";
                //Home(0, i); std::cout << "1";
                passcount++;
            }
            if (passcount > best) best = passcount;
            //Home(21, 0); std::cout << "pass: " << passcount << ", fail: " << failcount << "  ";
            //Home(21, 20); std::cout << " (best: " << best << ")       ";
        }
        test++;
        if (passcount == 19)
        {
            finished = true;
            Home(21, 0); std::cout << "pass: " << passcount << ", fail: " << failcount << " (test: " << test - 1<< ")       ";
        }
    } while (!finished);
    PauseForInput();
    return 0;
}

// Use this function to "Home" the cursor to the top left of the console.
void Home()
{
    HANDLE	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD	coordScreen = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coordScreen);
    return;
}

// Use this function overload to "Home" the cursor to a specific row:column.
void Home(int row, int column)
{
    short thisRow = row;
    short thisColumn = column;
    HANDLE	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD	coordScreen = { thisColumn, thisRow };
    SetConsoleCursorPosition(hConsole, coordScreen);
    return;
}

// Use this overload with a true or false argument for a "Clear and Home" effect in the console.
void Home(bool clear)
{
    HANDLE	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD	coordScreen = { 0, 0 };
    BOOL	bSuccess;
    DWORD	cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO	csbi;
    DWORD	dwConSize;
    bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
    if (!bSuccess) return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten);
    if (!bSuccess) return;
    bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
    if (!bSuccess) return;
    bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    if (!bSuccess) return;
    bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
    if (!bSuccess) return;
}

// Delay for console input.
void PauseForInput()
{
    std::string userInput;
    Home(22, 0);  std::cout << "Please hit <Enter> to proceed...                              ";
    getline(std::cin, userInput);
    return;
}

// True if continued play is requested, false if exit requested.
bool Continue()
{
    bool validInput = false;
    bool proceed = false;
    do
    {
        std::string userInput;
        Home(22, 0); std::cout << "Please enter (P)roceed or (E)xit then <Enter>, thank you.  ";
        getline(std::cin, userInput);
        if (userInput[0] == 'p' || userInput[0] == 'P')
        {
            validInput = true;
            proceed = true;
        }
        else  if (userInput[0] == 'e' || userInput[0] == 'E')
        {
            validInput = true;
        }
    } while (!validInput);
    Home(22, 0); std::cout << "                                                               ";
    return proceed;
}
