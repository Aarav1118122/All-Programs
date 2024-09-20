#include <iostream>
using namespace std;

int main()
{
    long int number = 33550334;
    int sum = 0;
    while (number < 1000000000)
    {
        for (int i = 2; i < number / 2; i++)
        {
            if (number % i == 0)
            {
                sum = sum + i + (number / i);
            }
        }
        if (sum == number - 1)
        {
            cout << number << endl;
        }
        sum = 0;
        number++;
        // cout << number << endl;
    }

    return 0;
}