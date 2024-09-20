#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    cout << factorial(7) << endl;
}

int factorial(int n)
{

    if (n <= 1)
        return 1;
    else
    {
        int fact = n * factorial(n - 1);
        return fact;
    }
}
