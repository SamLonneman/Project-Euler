#include <iostream>
#include <unordered_set>

// The big idea is to perform the division algorithm until reaching a dividend which was already reached.

int main()
{

    // Initialize maxima at -1
    int maxCycleLength = -1;
    int maxCycleDivisor = -1;

    // Check all dividends less than 1000
    for (int i = 2; i < 1000; i++)
    {

        // Initialize dividend, divisor, and cycleLength
        int dividend = 1;
        int divisor = i;
        int cycleLength = 0;

        // Start an empty set of prior dividends
        std::unordered_set<int> prior_dividends;

        // Continue until a prior dividend is seen again
        while (!prior_dividends.count(dividend))
        {

            // Add the current dividend to the set
            prior_dividends.insert(dividend);

            // Multiply the dividend by 10
            dividend *= 10;

            // Let the new dividend become the divisor
            dividend %= divisor;

            // Increase the cycle length
            cycleLength++;

        }

        // Update maxima if needed
        if (cycleLength > maxCycleDivisor)
        {
            maxCycleLength = cycleLength;
            maxCycleDivisor = divisor;
        }

    }

    // Print result
    std::cout << maxCycleDivisor << std::endl;

}