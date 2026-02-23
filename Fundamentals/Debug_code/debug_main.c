#include <stdio.h>
#include <math.h>

float square_root(int num)
{
    float x = num;
    float y = 1;
    float epsilon = 0.000001;
    while (x - y > epsilon)
    {
        x = (x + y) / 2;
        y = num / x;
    }
    return x;
}

void bug1()
{
    int numbers[] = {4, 8, 15, 16, 23, 42};
    int sum = 0;
    double runningAvg = 0;

    // Correct loop condition to avoid out of bounds error.
    for (int i = 0; i < 6; i++)
    {
        sum = sum + numbers[i];
        runningAvg = (double)sum / (1 + i); // Cast sum to get the avg on double, added ().
        printf("After adding %d: sum = %d, average = %.2f\n",
               numbers[i], sum, runningAvg);
    }
}

void bug2()
{
    int squares[] = {1, 4, 9, 16, 25};
    float results[5];
    for (int i = 0; i < 5; i++)
    {
        results[i] = square_root(squares[i]);
        // Check if the difference between the square of the result and the original value is within an acceptable range (epsilon).
        if ((results[i] * results[i] - (float)squares[i]) > 0.0001)
        {
            printf("Something went wrong with square root!\n");
        }
    }
}
void bug3()
{
    int i = 10; // made int signed
    while (i >= 0)
    {
        i--;
    }
}

int main()
{
    bug1();
    bug2();
    bug3();
    return 0;
}