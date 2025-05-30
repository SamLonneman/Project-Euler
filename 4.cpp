#include <iostream>

/*
 * Determines whether a given integer is a palindrome.
 * Uses mod 10 to extract each digit and derive the reversed form, then checks if it is equal.
 */
bool isPalindrome(int n)
{
    int forward = n;
    int reverse = 0;
    while (n)
    {
        reverse *= 10;
        reverse += n % 10;
        n /= 10;
    }
    return forward == reverse;
}

/*
 * Essentially a brute force solution where we generate all possible products and check which ones are palidromes.
 * Notice that we start with larger numbers and work downwards so that we don't have to check smaller ones after finding a palindrome.
 */
int main()
{
    int largest = 0;
    for (int i = 100; i < 999; i++)
    {
        for (int j = i; j < 999; j++)
        {
            int n = i * j;
            if (n > largest && isPalindrome(n))
            {
                largest = n;
                break;
            }
        }
    }
    std::cout << largest << std::endl;
}