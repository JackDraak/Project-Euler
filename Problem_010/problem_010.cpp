/*
Project Euler

Summation of primes
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

This is a functional solution, please solve the problem yourself before you review my code.
@JackDraak
*/

#include <iostream>
#include <sstream>

bool IsPrime(uint64_t);
uint64_t Get_uint64();

int main()
{
    while (true) {
        // Get a number from the console user.
        uint64_t inputNumber = Get_uint64();
        uint64_t primeSum = 0;
        for (uint64_t i = 2; i < inputNumber; i++)
        {
            if (IsPrime(i))
            {
                primeSum += i;
            }
        }
        std::cout << "The sum of primes less-than " << inputNumber << " is: " << primeSum << ".\n";
    }
    // Wait for input before exiting main.
    std::string userInput;
    std::cout << "\nhit <Enter> to exit...\n";
    getline(std::cin, userInput);
    return 0;
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
        std::cout << "Please enter a positive whole number to sum primes less-than 'N': ";
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
