// prints all five digit numbers with ascending digits
#include <iostream>
using namespace std;

int main()
{
    int count = 1;
    for (int i = 1; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            for (int k = j + 1; k < 10; k++)
            {
                for (int l = k + 1; l < 10; l++)
                {
                    for (int m = l + 1; m < 10; m++)
                    {
                        cout << count << "\t" << i * 10000 + j * 1000 + k * 100 + l * 10 + m << endl;
                        count++;
                    }
                }
            }
        }
    }

    return 0;
}