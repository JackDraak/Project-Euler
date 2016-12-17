/*
Project Euler

Problem 2
Even Fibonacci numbers

Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
find the sum of the even-valued terms.

This is a complete solution, please solve the problem yourself before you review my code.
@JackDraak
*/
#include <vector>
#include <iostream>
#include <sstream>

bool bEvenNumber(int);
int TallySet(std::vector<int>);

int main() 
{ 
    std::vector<int> fibinacciEvenSet;
    std::vector<int> fibinacciOddSet;
    int value_A = 1;
    int value_B = 2;
   
    do
    {
        if (bEvenNumber(value_A)) fibinacciEvenSet.push_back(value_A);
        if (bEvenNumber(value_B)) fibinacciEvenSet.push_back(value_B);
        if (!bEvenNumber(value_A)) fibinacciOddSet.push_back(value_A);
        if (!bEvenNumber(value_B)) fibinacciOddSet.push_back(value_B);
        value_A += value_B;
        value_B += value_A;
    } while (!(value_A > 4000000 || value_B > 4000000));

    // Output results.
    std::cout << "\nA = " << value_A;
    std::cout << "\nB = " << value_B;
    std::cout << "\nOdd Tally: " << TallySet(fibinacciOddSet);
    std::cout << "\nEven Tally: " << TallySet(fibinacciEvenSet);

    // Wait for input before exiting main.
    std::string userInput;
    std::cout << "\nhit <Enter> to exit...\n";
    getline(std::cin, userInput);
    return 0;
}

int TallySet(std::vector<int> thisSet)
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

bool bEvenNumber(int testNumber)
{
    bool bEven = false;
    if (testNumber % 2 == 0) bEven = true;
    return bEven;
}
