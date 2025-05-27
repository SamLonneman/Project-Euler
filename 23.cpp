#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    // Find the sum of all amicable numbers less than 28123
    int n = 28123;
    
    // Initialize a sum of proper divisors for each number less than n
    std::vector<int> d(n);

    // Iterate over each number i from 1 to sqrt(n)
    for (int i = 1; i * i < n; i++)
    {
        // For each multiple j of i, i is a divisor of j
        for (int j = i * 2; j < n; j += i)
        {
            // Make sure i is less than or equal to sqrt(j) so we don't double count it
            if (i * i <= j)
            {
                // Add i to the sum of proper divisors of j
                d[j] += i;

                // If j/i is distinct from i and not j itself, it is also a proper divisor
                if (i * i != j && i != 1)
                {
                    // So, add it to the sum of proper divisors of j
                    d[j] += j / i;
                }
            }
        }
    }

    // Identify abundant numbers
    std::vector<int> abundantNumbers;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > i)
        {
            abundantNumbers.push_back(i);
        }
    }

    // Initialize a bool vector of whether a number is an abundant sum
    std::vector<bool> abundantSums(n + 1);

    // For each pair of abundant numbers i, j,
    for (int i = 0; i < abundantNumbers.size(); i++)
    {
        for (int j = i; j < abundantNumbers.size(); j++)
        {
            // If i + j > n, we already know it isn't an abundant sum
            if (abundantNumbers[i] + abundantNumbers[j] > n)
                break;
            
            // Otherwise, i + j is an abundant sum
            abundantSums[abundantNumbers[i] + abundantNumbers[j]] = true;
        }
    }

    // Calculate the sum of all non-abundant sums
    int sum = 0;
    for (int i = 0; i < abundantSums.size(); i++)
    {
        if (!abundantSums[i])
        {
            sum += i;
        }
    }

    // Print result
    std::cout << sum << std::endl;

    return 0;
}