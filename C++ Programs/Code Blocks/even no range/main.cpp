//find all the even no between a give range
#include <iostream>

using namespace std;

int main()
{
    int s,e,i;
    cout<< "enter a starting value: ";
    cin>>s;
    cout<<"enter ending value: ";
    cin>>e;
    for(i=s;i<=e;i++)
    {
        if(i%2==0)
        {
            cout<<i<<endl;
        }
    }

    return 0;
}
