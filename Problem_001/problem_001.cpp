/*
Project Euler

Problem 1
Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

This is a functional solution, please solve the problem yourself before you review my code.
@JackDraak
*/

#include <vector>
#include <sstream>
#include <iostream>

bool bInSet(int);
void AddToSet(int);
int TallySet();

int const M1 = 3; // core multiplier
int const M2 = 5; // core multiplier
int const TOP = 1000;

std::vector<int> thisSet;

int main() 
{ 
    thisSet.swap(std::vector<int>());
    std::cout << "\n\nSTART ANALYSIS: " << TallySet();
    AddToSet(M1);
    std::cout << "\n\nMID ANALYSIS: " << TallySet();
    AddToSet(M2);
    std::cout << "\n\nFINAL ANALYSIS: " << TallySet();

    // Wait for input before exiting main.
    std::string userInput;
    std::cout << "\nhit <Enter> to exit...\n";
    getline(std::cin, userInput);
    return 0;
}

int TallySet()
{
    int tally = 0;
    int setSize = thisSet.size();
    if (setSize > 0)
    {
        for (int i = 0; i < setSize; i++)
        {
            tally += thisSet[i];
        }
    }
    return tally;
}

void AddToSet(int thatMultiplier)
{
    bool bComplete = false;
    int thisMultiplier = 0;
    int thisProduct = 0;
    std::cout << "\nBuilding set for x" << thatMultiplier << "...";
    do
    {
        thisMultiplier++;
        thisProduct = thisMultiplier * thatMultiplier;
        std::cout << thisMultiplier << ":" << thisProduct << " . ";
        if (thisProduct < TOP)
        {
            if (!bInSet(thisProduct)) thisSet.push_back(thisProduct);
        }
        else bComplete = true;
    } while (!bComplete);
}

bool bInSet(int testNumber)
{
    bool bIn = false;
    int setSize = thisSet.size();
    for (int i = 0; i < setSize; i++)
    {
        if (thisSet[i] == testNumber) bIn = true;
    }
    return bIn;
}
