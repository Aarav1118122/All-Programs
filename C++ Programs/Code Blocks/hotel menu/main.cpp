#include <iostream>

using namespace std;
int main()
{
    char a;
    char b;
    cout <<"Enter your meal."<<endl;
    cin>>a;
    switch(a)
    {
        case'b':
        cout <<"Milk,Cornflakes,Sandwich."<<endl;
        cout <<"What will you like to have?";
        cin>>b;
        switch(b)
        {
            case'm':
            cout<<"Rs.50";
        }

    }
    return 0;
}
