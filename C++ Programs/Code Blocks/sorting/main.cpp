//to input 10 nos and to arrange it in ascending order
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n[10];
    cout <<"Enter 10 numbers: "<<endl;
    for(int a=0;a<10;a++)
    {
        cin>>n[a];
    }
    cout<<endl;
    cout<<"In ascending order: "<<endl;
    cout<<endl;
    sort(n,n+10);
    for(int b=0;b<10;b++)
    {
        cout<<n[b]<<endl;
    }
    return 0;
}
