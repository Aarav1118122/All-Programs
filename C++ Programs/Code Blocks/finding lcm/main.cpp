#include <iostream>

using namespace std;

int main()
{
    int a ;
    int b ;
    int lcm ;
    int m;
    cout << "enter 2 numbers : ";
    cin>>a>>b;
     if (a>=b&&a%b==0)
    {
        cout <<"lcm is "<<a;
    }
    else if (b>=a&&b%a==0)
    {
        cout <<"lcm is "<<b;
    }
    else if(a>b && a%b!=0)
    {
        m=a%b;
        cout << (a*b)/m;
    }
     else if(b>a && b%a!=0)
    {
        m=b%a;
        cout << (a*b)/m;
    }

    else
    {
        lcm =a*b;
        cout <<"lcm is "<<lcm;
    }

    return 0;
}

    return 0;
}
