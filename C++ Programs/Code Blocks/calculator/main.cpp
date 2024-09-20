#include <iostream>
#include <string>

using namespace std;

int main()
{
    double a;
    double b;
    string ot;
    char op;
    cout<<"enter a number : ";
    cin>>a;
    cout<<"enter an operator + - * / :  ";
    cin>>op;
    cout<<"enter second number : ";
    cin>> b;
    if (op=='+')
    {
        ot=to_string(a+b);
    }
    else if (op=='-')
    {
        ot=to_string(a-b);
    }
    else if(op=='*')
    {
        ot=to_string(a*b);
    }
    else if(op=='/')
    {
        ot=to_string(a/b);
    }
    else
    {
        ot="error";
    }
    cout << ot;
    return 0;
}
