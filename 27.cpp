#include <iostream>
#include <vector>

int main()
{

    // Choose some arbitrary N, the maximum value of n we should be able to check. We can increase this later if needed.
    int N = 100;

    // Begin a seive of Eratosthenes to find all primes up to (N^2 + 999N + 1000), the maxmimum possible value of any such quadratic
    std::vector<bool> primes(N * N + 999 * N + 1000, true);

    // For each natural number i from 2 to the square root of the size of the primes list,
    for (int i = 2; i * i < primes.size(); i++)
    {

        // For each multiple j of i
        for (int j = i * 2; j < primes.size(); j += i)
        {

            // Mark j as composite
            primes[j] = false;

        }

    }

    // Initialize a variable for the maximum number of primes produced
    int maxPrimes = -1;

    // Initialize a variable for the product of coefficients which acheive this
    int product = -1;

    // For all a such that |a| < 1000
    for (int a = -999; a < 1000; a++)
    {

        // For all b such that |b| <= 1000
        for (int b = -1000; b <= 1000; b++)
        {

            // Start counting up from 0 to N
            int n = 0;

            // Count up while the image is prime
            while (primes[n * n + a * n + b])
            {
                n++;
            }

            // If this quadratic produces the most primes seen so far,
            if (n > maxPrimes)
            {
                maxPrimes = n;
                product = a * b;
            }

        }

    }

    // Print result
    std::cout << product << std::endl;

}