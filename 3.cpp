#include <chrono>
#include <iostream>
#include <vector>

// Function to determine whether a number is prime, used in solution 1.
bool isPrime(long long n)
{
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

/*
 * This first solution is not very efficient with time complexity O(n). This is because sqrt(n)*sqrt(n) = n.
 * Note that factors of x come in pairs: a and b, where a < sqrt(x) and b > sqrt(x), or a = b = sqrt(x).
 * Thus to locate large factors, we should count up 'a' from 2 to sqrt(x), where the larger factor will be b = x / a.
 * Once pairs of factors are located, check if they are prime. If b is prime, we are done. If a is prime, mark it but keep counting upwards for a larger candidate.
 */
void solution_1()
{
    long long x = 600851475143;
    long long largestPrimeFactor = -1;
    for (long long a = 2; a * a <= x; a++)
    {
        if (x % a == 0)
        {
            long long b = x / a;
            if (isPrime(b))
            {
                largestPrimeFactor = b;
                break;
            }
            if (isPrime(a))
            {
                largestPrimeFactor = a;
            }
        }
    }

    // Print result
    std::cout << largestPrimeFactor << std::endl;
}

/*
 * Solution 2 is far more efficient. First notice that prime factors are the smallest factors of a given number.
 * Then if we count upwards looking for factors, we reach prime factors before any others.
 * When one is reached, divide n by the prime factor and retain the result.
 * In case this prime factor occurs multiple times, do not increment i on this pass.
 * Continue dividing away the prime factors until our upward count exceeds sqrt(n), in which case we are done.
 */
void solution_2()
{
    long long n = 600851475143;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            n /= i;
        }
        else
        {
            i++;
        }
    }
    std::cout << n << std::endl;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    // solution_1();
    solution_2();
    
    // Pretty print the time taken in microseconds
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

}