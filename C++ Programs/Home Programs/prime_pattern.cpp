#include <iostream>
#include <math.h>
#include <thread>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
int main()
{
    int size = 49;
    int prime[size] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227};

    int diff[size];

    diff[0] = 0;
    for (int i = 0; i < size - 1; i++)
    {
        diff[i + 1] = prime[i + 1] - prime[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << prime[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 1000; i++)
    {
        sleep_for(25ms);
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << diff[i] << " ";
        }
        diff[0] = 0;
        for (int i = 0; i < size - 1; i++)
        {
            diff[i + 1] = abs(diff[i + 1] - diff[i]);
        }
    }

    return 0;
}
