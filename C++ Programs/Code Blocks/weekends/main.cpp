//to tell the day is weekend or not
#include <iostream>

using namespace std;

int main()
{
    char d;
    cout<<"Enter a day : ";
    cin>>d;
    switch(d)
    {

        case 'm':
        case 't':
        case 'w':
        case 'f':
            cout<<"Weekday"<<endl;
            break;
        case 's':
            cout<<"Weekend.HAVE FUN."<<static_cast<char>(1)<<endl;
            break;
        default:
            cout<<"error"<<endl;
            break;
    }
    return 0;
}
