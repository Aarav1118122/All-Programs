#include <iostream>
using namespace std;

void tower(int *move, int n, string from, string to, string spare);

int main()
{
    int moves = 0;
    int *move = &moves;
    tower(move, 5, "P1", "P2", "P3");
    return 0;
}

void tower(int *move, int n, string from, string to, string spare)
{
    if (n == 1)
    {
        (*move)++;
        cout << "Move from " << from << " to " << to << " Move: " << *move << endl;
    }
    else
    {
        tower(move, n - 1, from, spare, to);
        tower(move, 1, from, to, spare);
        tower(move, n - 1, spare, to, from);
    }
}