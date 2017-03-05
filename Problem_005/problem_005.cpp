/*
Project Euler

Smallest multiple
    Problem 5
    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

    What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20? ^E^E^E <RANGE>
    i.e. 5354228880 @ 23 or 80313433200 @ 27

This is a functional solution, please solve the problem yourself before you review my code.
@JackDraak
*/

// Used for I/O (input/output).
#include <iostream>
#include <sstream>

void    PauseForInput();

int main()
{
    const int RANGE = 30;
    uint64_t test = RANGE;
    int best = 0;
    bool finished = false;
    do {
        int passcount, failcount;
        failcount = 0;
        passcount = 0;
        for (int i = 2; i <= RANGE; i++)
        {
            if (test % i != 0)
            {
                failcount++;
            }
            else {
                passcount++;
            }
            if (passcount > best) best = passcount;
        }
        if (passcount == RANGE - 1)
        {
            finished = true;
            std::cout << test << " is the smallest number that can be divided by each of the\nnumbers from 1 to " << RANGE << " without any remainder.";
        }
        test += RANGE;
    } while (!finished);
    PauseForInput();
    return 0;
}

// Delay for console input.
void PauseForInput()
{
    std::string userInput; 
    std::cout << "\nPlease hit <Enter> to proceed... ";
    getline(std::cin, userInput);
    return;
}
