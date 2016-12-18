/*
Project Euler

Problem 3
Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

This is a __________ solution, please solve the problem yourself before you review my code.
@JackDraak
*/
#include <vector>
#include <iostream>
#include <sstream>

bool bInSet(int, std::vector<int>);
bool bTestPrime(int);
void PrintFactors(int, std::vector<int>);
int GetUserNumber();
std::vector<int> GetPrimeFactors(int);

int main()
{
    do
    {
        std::cout << "\nFind the prime factors of a number. Enter a number to factor: ";
        int factoree = GetUserNumber();
        std::cout << "\nYou entered: " << factoree;
        std::vector<int> theseFactors;
        theseFactors = GetPrimeFactors(factoree); 
        PrintFactors(factoree, theseFactors);
    } while (true);
    return 0;
}

std::vector<int> GetPrimeFactors(int factoree)
{
    std::vector<int> primeFactors;
    primeFactors.push_back(factoree);
    bool bAllPrime;
    do 
    {
        bAllPrime = true; // not really, but sets up the loop to break apropriately(?)
        int setSize = primeFactors.size();
        std::cout << "\nSetSize: " << setSize;
        for (int j = 0; j < setSize; j++)
        {
            int thisFactoree = primeFactors[j];
            std::cout << ", thisFactoree: " << thisFactoree;
            for (int i = 1; i < thisFactoree; i++)
            {
                if (thisFactoree % i == 0)
                {
                    if (!bInSet(i, primeFactors))
                    {
                        std::cout << ", " << i << " pushed to set";
                        primeFactors.push_back(i);
                        if (!bTestPrime(i)) bAllPrime = false;
                    }
                }
            }
        }
    } while (!bAllPrime);
    return primeFactors;
}

void PrintFactors(int factoree, std::vector<int> factors)
{
    int setSize = factors.size();
    std::cout << "\n\nPrime factors of " << factoree << ": ";
    for (int i = 0; i < setSize; i++)
    {
        std::cout << factors[i];
        if (i + 1 < setSize)  std::cout << ", ";
    }
}

int GetUserNumber()
{
    int userNumber;
    std::string userInput;
    while (true) {
        getline(std::cin, userInput);
        std::stringstream thisStream(userInput);
        if (thisStream >> userNumber) { break; }
        std::cout << "\nInvalid entry, please enter a number...\n";
    }
    return userNumber;
}

bool bInSet(int testNumber, std::vector<int> testSet)
{
    std::cout << "\nbSetTest: " << testNumber;
    bool bIn = false;
    int setSize = testSet.size();
    for (int i = 0; i < setSize; i++)
    {
        if (testSet[i] == testNumber) bIn = true;
    }
    return bIn;
}

bool bTestPrime(int testee)
{
    std::cout << "\nbPrimeTest: " << testee;
    if (testee < 2) { return false; }
    bool bZeroRemainder = false;
    int invalidDivisorCount = 0;
    std::vector<int> theseDivisors;

    for (int thisDivisor = 2; thisDivisor < testee; thisDivisor++)
    {
        int thisRemainder = testee % thisDivisor;
        if (thisRemainder == 0)
        {
            theseDivisors.push_back(thisDivisor);
            bZeroRemainder = true;
            invalidDivisorCount++;
        }
    }
    return !bZeroRemainder;
}
