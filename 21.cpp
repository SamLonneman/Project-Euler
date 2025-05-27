#include <iostream>
#include <vector>

int main()
{
    // Find the sum of all amicable numbers less than 10000
    int n = 10000;
    
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

    // Initialize a sum of amicable numbers
    int sum = 0;

    // For each number less than n
    for (int i = 1; i < n; i++)
    {
        // If amicable, add it to the sum
        if (d[d[i]] == i && i != d[i])
        {
            sum += i;
        }
    }

    // Print result
    std::cout << sum << std::endl;

    return 0;
}