
#include <iostream>

using namespace std;

int main()
{

    int a;
    cout <<"enter a no ";
    cin >> a;
    if (a>=1&&a<10)
    {
        cout <<"1 digit no";
    }
    else if(a>9&&a<100)
    {
        cout<<"2 digit no";
    }
    else if(a>99&&a<1000)
    {
        cout <<" 3 digit no";
    }
    else if (a>999&&a<10000)
    {
        cout <<"4 digit no";
    }
    else
    {
        cout <<"out of range"<< endl ;
    }
}

