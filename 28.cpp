#include <iostream>

/*
 * This attempt uses the fact that the sequence counts upwards 4 times by 2, 4 times by 4, 4 times by 6, etc.
 * Once this pattern is recognized, it can be brute forced towards a result
 */
int attempt_1(int size)
{
    int n = 1;
    int sum = n;
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            n += (i + 1) * 2;
            sum += n;
        }
    }
    return sum;
}

/*
 * This attempt uses a specific quadratic representing the sum of corners of any given "layer".
 * To derive this quadratic, notice first that the upper right corner is the square of the layer number.
 * The other four corners may be derived from this, and the quadratic 4i^2 - 6i + 6 can be derived.
 */
int attempt_2(int size)
{
    int sum = 1;
    for (int i = 3; i <= size; i += 2)
    {
        sum += 4 * i * i - 6 * i + 6;
    }
    return sum;
}

int main()
{
    int size = 1001;

    std::cout << attempt_1(size) << std::endl;
    std::cout << attempt_2(size) << std::endl;
}