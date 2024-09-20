#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    cout <<"enter 2 nos : ";
    cin >>a>>b;
    for (int i=2; i=a||b;i++)
    {
     if(a%i==0)
     {
         a/=i;
     }
     else if(b%i==0)
     {
         b/=i;
     }
     else
     {
         return 15;
     }
    }
    cout<<a*b;

    return 0 ;
}
