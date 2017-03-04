/*
Project Euler

Problem 3
Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

This is a W.I.P. solution, please solve the problem yourself before you review my code.
@JackDraak
*/
#include <vector>
#include <iostream>
#include <sstream>

std::vector<long long> primeFactorSet;
long long factoree;

bool bInSet(long long, std::vector<long long>);
bool bTestPrime(long long);
long long GetUserNumber();
void PrintFactors(long long, std::vector<long long>);

int main()
{
    // divide candidate by lowest prime that gives zero remainder.
    // store that prime & reprocess dividend
    // i.e. in the case of candidate 26 / 2 (where remainder  == 0)
    // then store 2 and re-process with candidate 13 (resulting in storing 13)
    do
    {
        std::cout << "\nFind the prime factors of a number. Enter a number to factor: ";
        factoree = GetUserNumber();

        bool bCrunching = true;
        int primeCandidate = 1;
        long long userNumber = factoree;
        do
        {
            primeCandidate++;
            if (bTestPrime(primeCandidate))
            {
                std::cout << "\nPrime Found: " << primeCandidate;
                int remainder = userNumber % primeCandidate;
                if (remainder == 0)
                {
                    std::cout << " BINGO!";
                    primeFactorSet.push_back(primeCandidate);
                    userNumber = factoree / primeCandidate;
                    break;
                }
                else {
                    std::cout << " invalid....";
                }
            }


        } while (bCrunching);
        PrintFactors(factoree, primeFactorSet);

    } while (true);
    return 0;
}

void PrintFactors(long long factoree, std::vector<long long> factors)
{
    int setSize = factors.size();
    std::cout << "\n\nPrime factors of " << factoree << ": ";
    for (int i = 0; i < setSize; i++)
    {
        std::cout << factors[i];
        if (i + 1 < setSize)  std::cout << ", ";
    }
}

long long GetUserNumber()
{
    long long userNumber;
    std::string userInput;
    while (true) {
        getline(std::cin, userInput);
        std::stringstream thisStream(userInput);
        if (thisStream >> userNumber) { break; }
        std::cout << "\nInvalid entry, please enter a number...\n";
    }
    return userNumber;
}

bool bInSet(long long testNumber, std::vector<long long> testSet)
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

bool bTestPrime(long long testee)
{
    if (testee < 2) { return false; }
    bool bZeroRemainder = false;
    std::vector<long long> theseDivisors;
    std::cout << std::endl;  // newline
    for (long long thisDivisor = 2; thisDivisor < testee; thisDivisor++)
    {
        long long thisRemainder = testee % thisDivisor;
        std::cout << thisDivisor << ":" << thisRemainder << "    ";
        std::cout << std::string(28, 8);
        if (thisRemainder == 0)
        {
            theseDivisors.push_back(thisDivisor);
            bZeroRemainder = true;
        }
    }
    return !bZeroRemainder;
}
