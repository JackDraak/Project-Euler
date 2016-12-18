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

bool bInSet(long long, std::vector<long long>);
bool bTestPrime(long long);
void PrintFactors(long long, std::vector<long long>);
long long GetUserNumber();
std::vector<long long> GetPrimeFactors(long long);

int main()
{
    do
    {
        std::cout << "\nFind the prime factors of a number. Enter a number to factor: ";
        long long factoree = GetUserNumber();
        std::cout << "\nYou entered: " << factoree;
        std::vector<long long> theseFactors;
        theseFactors = GetPrimeFactors(factoree); 
        PrintFactors(factoree, theseFactors);
    } while (true);
    return 0;
}

std::vector<long long> GetPrimeFactors(long long factoree)
{
    bool bAllPrime;
    std::vector<long long> primeFactors;
    std::vector<long long> nonPrimeFactors;

    if (bTestPrime(factoree))
    {
        primeFactors.push_back(factoree);
        bAllPrime = true;
    } else {
        nonPrimeFactors.push_back(factoree);
        bAllPrime = false;
    }

    if (!bAllPrime)
    {
   //     do
   //     {
            int setSize = nonPrimeFactors.size();
            std::cout << "\nNPSetSize: " << setSize;
            for (int setMember = 0; setMember < setSize; setMember++)
            {
                long long thisFactoree = nonPrimeFactors[setMember];
                std::cout << ", thisFactoree: " << thisFactoree;
                for (long long divisor = 1; divisor < (thisFactoree / 5) +1; divisor++) // stop searching after first ~20%?
                {
                    if (thisFactoree % divisor == 0)
                    {
                        if (bTestPrime(divisor))
                        {
                            if (!bInSet(divisor, primeFactors))
                            {
                                std::cout << ", " << divisor << " pushed to prime set";
                                primeFactors.push_back(divisor);
                            }
                            else if (!bInSet(divisor, nonPrimeFactors))
                            {
                                std::cout << ", " << divisor << " pushed to non-prime set";
                                nonPrimeFactors.push_back(divisor);
                                bAllPrime = false;
                            }
                        }
                    }
                }
            }
  //      } //while (!bAllPrime);
    }
    return primeFactors;
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
    std::cout << "\nbPrimeTest: " << testee;
    if (testee < 2) { return false; }
    bool bZeroRemainder = false;
    int invalidDivisorCount = 0;
    std::vector<long long> theseDivisors;

    std::cout << std::endl; 
    for (long long thisDivisor = 2; thisDivisor < testee; thisDivisor++)
    {
        int thisRemainder = testee % thisDivisor;
        float completion = (thisDivisor / testee) * 100.00f;
        std::cout << thisDivisor << ":" << thisRemainder << " " << completion << "%     ";
        std::cout << std::string(28, 8);
        if (thisRemainder == 0)
        {
            theseDivisors.push_back(thisDivisor);
            bZeroRemainder = true;
            invalidDivisorCount++;
        }
    }
    return !bZeroRemainder;
}
