#include <iostream>

using namespace std;

int main()
{
    char a,b;
    double t1,t2;
    cout<<"Enter the unit you want to convert: ";
    cin>>a;
    cout<<"Enter the value: ";
    cin>>t1;
    cout<<"Enter the unit to which you want to convert: ";
    cin>>b;
    if(a=='c'&&b=='f')
    {
        t2=(9/5)*(t1 + 32);
        cout<<"The result is "<<t2;
    }
    else if(a=='f'&&b=='c')
    {
        t2= 5/9*(t1 - 32);
        cout<<"The result is "<<t2;
    }
    else if(a=='c'&&b=='k')
    {
        t2=  t1 + 273;
        cout<<"The result is "<<t2;
    }
    else if(a=='k'&&b=='c')
    {
        t2=  t1 - 273;
        cout<<"The result is "<<t2;
    }
    else if(a=='f'&&b=='k')
    {
        t2= 5/9*(t1 - 32) + 273;
        cout<<"The result is "<<t2;
    }
    else if(a=='k'&&a=='f')
    {
     t2= 9/5*(t1 - 273) + 32;
     cout<<"The result is "<<t2;
    }
    else
    {
        cout<<"unit not available";
    }

    return 0;
}
