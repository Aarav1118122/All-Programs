#include <iostream>
#include <math.h>
using namespace std;

// 664579
int main()
{
    int count = 0;
    int sq;
    bool prime = true;
    for (int i = 1; i <= 10000000; i += 2)
    {
        sq = sqrt(i);
        prime = true;
        for (int factor = 3; factor <= sq; factor += 2)
        {
            if (i % factor == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
            count++;
    }
    cout << "No of primes are - " << count << endl;

    return 0;
}