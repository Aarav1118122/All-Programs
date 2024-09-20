#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cout<< "enter a no: ";
    cin>>a;
    b==a;
    c==a;
    for (int i=1;i<=a;i++)
    {
        b=b*(c-1);
        c=c-1;
    }
    cout<<b;

    return 0;
}
