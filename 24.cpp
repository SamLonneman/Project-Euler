#include <iostream>
#include <vector>

// Big idea:
// There are 10! ways to permute the digits.
// The first 9! start with 0, the next 9! start with 1, etc.
// Thus n / 9! determines the first digit.
// We then proceed to choose the next digit from the remainder
// Repeat until all digits are placed.


int main()
{
    // The one millionth item has index 999999
    int n = 999999;

    // We are given 10 digits
    int numDigits = 10;

    // Declare a list of characters since final result will exceed int max
    std::vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Declare a string to hold the final result
    std::string result = "";

    // Count downwards from numDigits - 1, i.e. 9, 8, 7, 6, 5, 4, 3, 2, 1, 0.
    for (int i = numDigits - 1; i >= 0; i--)
    {

        // Calculate iFactorial, which the number of ways to permute i items
        int iFactorial = 1;
        for (int j = i; j > 1; j--)
        {
            iFactorial *= j;
        }

        // Divide n by iFactorial to get the index of the digit needed
        int digitIndex = n / iFactorial;

        // From the remaining digits, choose the one at digitIndex position
        result += digits[digitIndex];

        // Remove the item at digitIndex from consideration
        digits.erase(digits.begin() + digitIndex);

        // Reduce n to the remainder and proceed to the next digit
        n %= iFactorial;
    }

    // Return result
    std::cout << result << std::endl;

}