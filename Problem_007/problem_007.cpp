/*
Project Euler

10001st prime
Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

This is a functional solution, please solve the problem yourself before you review my code.
@JackDraak
*/

#include <iostream>
#include <sstream>

bool IsPrime(uint64_t);
uint64_t Get_uint64();

int main(void)
{
    while (true) {
        // Get a number from the console user.
        uint64_t inputNumber = Get_uint64();        
        uint64_t primeSequence = 1;
        for (uint64_t i = 2; primeSequence <= inputNumber; i++)
        {
            if (IsPrime(i) && primeSequence < inputNumber)
            {
                primeSequence++;
            }
            else if (IsPrime(i) && primeSequence == inputNumber)
            {
                std::cout << "The prime at sequence: " << inputNumber << " is: " << i << ".\n";
                break;
            }
        }
    }
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
        std::cout << "Please enter a positive whole number to discover prime in sequence: ";
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
