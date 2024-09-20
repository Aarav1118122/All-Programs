#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int diceroll(int dicecount, int count);
int diceSum(int array[100], int count);
void print(int array[100], int count);

int main()
{
    diceroll(10, 1);
    return 0;
}

int diceroll(int diceCount, int count)
{
    int dices[diceCount];
    long long sum;
    for (int i = 0; i < diceCount; i++)
    {
        dices[i] = 1;
    }

    for (int dice = 0; dice < diceCount; dice++)
    {
        for (int number = 1; number <= 6; number++)
        {
            dices[dice] = number;
            print(dices, diceCount);
            sum = diceSum(dices, diceCount);
            cout << sum << endl;
        }
    }

    return 0;
}

int diceSum(int array[100], int count)
{
    long long sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += array[i];
    }

    return sum;
}
void print(int array[100], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << array[i] << " , ";
    }
    cout << endl;
}