#include <iostream>

/*
 * We proceed with a dynamic programming approach.
 * Specifically, we will use variables a and b to temporarily store the prior two fibonacci numbers.
 */
int main()
{

    // Initialize a and b
    int a = 1;
    int b = 2;

    // Initialize a sum which we will gradually add to
    int sum = 0;

    // Generate next element in sequence until it exceeds 4 million
    while (b <= 4000000)
    {

        // If even, add to sum
        if (b % 2 == 0)
        {
            sum += b;
        }

        // Temporarily store the value of b
        int temp = b;

        // Add a to b
        b += a;

        // Let a take the prior value of b
        a = temp;
        
    }

    // Print result
    std::cout << sum << std::endl;

}