/*
Project Euler

Date: 4 March 2017
Problem 4
Largest palindrome product

    A palindromic number reads the same both ways. 
    The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

    Find the largest palindrome made from the product of two 3-digit numbers.

This is a functional solution, please solve the problem yourself before you review my code.
@JackDraak
*/

#include <iostream>
#include <sstream>

bool digitalPalindrome(int);

int main(void)
{
    bool setComplete = false;
    int largest = 0;
    int a = 999;
    int b;
    do {
        for (b = a; b > a - 100; b--)
        {
            int product = a * b;
            if (digitalPalindrome(product) && product > largest)
            {
                std::cout << "A palindromic number reads the same both ways.\n";
                std::cout << "The largest palindrome made from the product of two 3-digit numbers is:\n";
                std::cout << product << " = " << b << " x " << a << ".\n";
                largest = product;
                setComplete = true;
            }
        }
        a--;
        if (a < 100) setComplete = true; // break out
    } while (!setComplete);

    // Wait for input before exiting main.
    std::string userInput;
    std::cout << "\nPlease hit <Enter> to exit...\n";
    getline(std::cin, userInput);
    return 0;
}

bool digitalPalindrome(int test)
{
    std::stringstream _s;
    _s << test;
    std::string str = _s.str();

    if (str == std::string(str.rbegin(), str.rend())) {
        return true;
    }
    return false;
}
