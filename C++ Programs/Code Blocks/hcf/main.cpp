#include <iostream>

using namespace std;

int main()
{
    int n1;
    int n2;
    int lcm;
    cout <<"enter 2 numbers";
    cin>>n1>>n2;
    lcm=(n1>n2)? n1:n2;
    while (lcm%n1!=0 && lcm%n2!=0)
    {
        lcm++;
    }
    cout << "lcm = "<< lcm;
    return 0;
}
