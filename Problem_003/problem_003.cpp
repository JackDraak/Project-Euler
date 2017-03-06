/*
Project Euler

Problem 3
Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

This is a functional solution, please solve the problem yourself before you review my code.
@JackDraak
*/

#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>

bool IsPrime(uint64_t);
uint64_t Get_uint64();
void GetPrimeFactors(uint64_t);
std::vector<uint64_t> primeFactors;

int main(void)
{
    while (true) {
        // Get a number from the console user.
        uint64_t inputNumber = Get_uint64();
        if (inputNumber == 1) std::cout << inputNumber << " is not prime and has no prime factors.\n\n";
        else if (IsPrime(inputNumber)) std::cout << inputNumber << " is prime.\n\n";
        else {
            // find prime factors
            std::vector<uint64_t>().swap(primeFactors);
            GetPrimeFactors(inputNumber);
            
            std::cout << "The prime factors of " << inputNumber << " are:\n";
            int setSize = primeFactors.size();
            for (int i = 0; i < setSize; i++)
            {
                std::cout << primeFactors[i];
                if (i + 1 < setSize) std::cout << ", ";
            }
            std::cout << "\n\n";
        }
    }
    return 0;
}

void GetPrimeFactors(uint64_t n) {
    uint64_t f = 2;
    while (f * f <= n) {
        if (n % f == 0) {
            primeFactors.push_back(f);
            n /= f;
        }
        else {
            f++;
        }
    }
    if (n > 1) {
        primeFactors.push_back(n);
    }
}

bool IsPrime(uint64_t test)
{
    int max = floor(sqrt(test));
    if (test <= 1) return false;
    for (uint64_t n = max; n > 1; n--)
    {
        if (test % n == 0) return false;
    }
    return true;
}

uint64_t Get_uint64()
{
    std::string input;
    uint64_t number;
    while (true)
    {
        std::cout << "Please enter a positive whole number to discover prime factors: ";
        getline(std::cin, input);
        if (input[0] == '-') continue;
        std::stringstream _stream(input);
        if (_stream >> number) {
            if (number < 1) { continue; }
            else { break; }
        }
    }
    return number;
}
