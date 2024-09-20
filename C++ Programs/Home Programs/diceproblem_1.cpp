#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
void diceroll(long long probability[601], int count, int sum, int noofdices);
int main()
{
    // File initialization
    FILE *fpout;
    fpout = fopen("diceproblem.csv", "w");
    if (fpout == NULL)
    {
        cout << "File unable to open" << endl;
        return -1;
    }

    // Input from the user
    int noofdices;
    cout << "Enter number of dices" << endl;
    cin >> noofdices;
    int upperlimit = 6 * noofdices + 1;

    // The calculation part
    long long total = pow(6, noofdices);
    long long probability[upperlimit] = {0};
    diceroll(probability, 1, 0, noofdices);

    // The export of file part (only words till 10 dices. For higher output only in terminal)
    unsigned long long sumofprob = 0;
    char Rows[100 * upperlimit]; // Sum row to print in file
    sprintf(Rows, "%s,%s,%s\n", "Sum", "Probability", "Percentage");
    fputs(Rows, fpout);
    for (int i = 1; i < upperlimit; i++)
    {
        sumofprob += probability[i];
        cout << i << "\t" << probability[i] << "\t" << sumofprob << endl;
        double percent = (probability[i] * 100) / total;
        sprintf(Rows, "%d,%d,%f\n", i, probability[i], percent);
        fputs(Rows, fpout);
    }
}

void diceroll(long long probability[601], int count, int sum, int noofdices)
{
    int nextcount = count + 1; // Store the dice count of the next call
    if (count >= noofdices)    // Stores the results of the last dice
    {
        for (int i = 1; i <= 6; i++)
        {
            probability[sum + i]++;
        }
    }
    else // Stores the results of first 9 dices
    {
        for (int i = 1; i <= 6; i++)
        {
            int currentsum = sum + i;
            diceroll(probability, nextcount, currentsum, noofdices);
        }
    }
}