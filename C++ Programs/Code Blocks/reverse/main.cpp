#include <iostream>

using namespace std;

int main()
{
    int a;
    int tn = 0;
    int rev = 0;
    cout << "enter a no : ";
    cin >> a;
    tn = a;
    while(tn!=0)
    {
    rev = rev * 10;
    rev = rev + (tn % 10);
    tn = tn / 10;
    }
    cout << "the reversed number of "<< a << " is " << rev;
    return 0;
}
