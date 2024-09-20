#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n);
bool isSquare(int n);

int main()
{
    cout << "n\tn+6\t9n+7\tsqrt(9n+7)" << endl;
    for (int i = 0; i <= 1000; i++)
    {
        if (isPrime(i + 6))
        {
            if (isSquare(((9 * i) + 7)))
            {
                cout << i << "\t" << (i + 6) << "\t" << ((9 * i) + 7) << "\t" << sqrt((9 * i) + 7) << endl;
            }
        }
    }

    return 0;
}
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isSquare(int n)
{
    double sqrtn = sqrt(n);
    if (sqrtn == floor(sqrtn))
    {
        return true;
    }
    return false;
}