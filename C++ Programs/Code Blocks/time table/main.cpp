#include <iostream>

using namespace std;

int main()
{
    char a ;
    cout <<"enter day: "<<endl;
    cin>>a;
    if(a=='m'||a=='w'||a=='f'||a=='M'||a=='W'||a=='F')
    {
        cout<<"the time is 3:30pm";
    }
    else if(a=='t'||a=='T')
    {
        cout<<"the time is 6:30pm";
    }
    else
    {
        cout<<"no class";
    }
    return 0;
}
