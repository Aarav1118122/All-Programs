#include <iostream>
#include <cmath>
using namespace std;

double factorial(long double num)
{
    long double factorial = 1;
    if (num == 0)
    {
        return 1;
    }

    for (long double i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}

double sum(int lowerbound, int upperbound)
{
    long double sum = 0;
    for (int i = lowerbound; i <= upperbound; i++)
    {
        sum = sum + ((factorial(6 * i) * (545140134 * i + 13591409)) / (factorial(3 * i) * pow(factorial(i), 3) * pow((-26253741264076800), i)));
    }
    return sum;
}

int main()
{
    double p = 0.0;

    int denominator = sum(0, 20);

    p = 426880 * sqrt(10005) / denominator;
    cout << p << endl;

    return 0;
}