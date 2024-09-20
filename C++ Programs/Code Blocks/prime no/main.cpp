#include <iostream>

using namespace std;

int main()
{
    int n,p;
    int i=2;
    cout << "enter a number : ";
    cin>> n;
    while(i<n||n%2==0)
    {
        if(n%i>0)
        {
            p=1;
        }
        else
        {
          cout<< "composite";
          return 0;
        }
        i++;
    }
    if ( p == 1)
    {
        cout<<"it is prime";
    }
    return 0;
}
