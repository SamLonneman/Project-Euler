#include <iostream>

/*
 * Solution 1 uses brute force, summing all applicable numbers from 0 to n.
 * Time complexity: O(n)
 */
int solution_1(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    return sum;
}

// Formula for the sum of natural numbers up to and including n, used in Solution 2.
int sumNatNums(int n)
{
    return n * (n + 1) / 2;
}

/*
 * Solution 2 uses the insight that there are n/x multiples of x less than or equal to n (using integer division).
 * Namely, these multiples are x, 2x, 3x, ..., x(n/x).
 * Then the sum of these multiples is x + 2x + 3x + ... + x(n/x) = x * (1 + 2 + 3 + ... + n/x).
 * Conveniently, we have a formula for the sum of natural numbers up to and including a natural number.
 * So, we can add the sum of multiples of three to the sum of multiples of 5, then subtract the twice counted sum of multiples of 15.
 * Time complexity: O(1)
 */
int solution_2(int n)
{
    return 3 * sumNatNums(n / 3) + 5 * sumNatNums(n / 5) - 15 * sumNatNums(n / 15);
}

int main()
{
    int n = 1000;
    std::cout << solution_1(n) << std::endl;
    std::cout << solution_2(n) << std::endl;
}
