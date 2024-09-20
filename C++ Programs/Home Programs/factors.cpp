#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int factors(int number);
int main()
{
    int highLimit, factorNo;
    cout << "Enter the range" << endl;
    cin >> highLimit;
    int factorCountList[highLimit];
    for (int i = 1; i < highLimit; i++)
    {
        factorNo = factors(i);
        factorCountList[i] = factorNo;
        cout << i << " - " << factorCountList[i] << endl;
        }
    return 0;
}
int factors(int number)
{
    int factorCount = 0;
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
            factorCount++;
    }
    return factorCount;
}