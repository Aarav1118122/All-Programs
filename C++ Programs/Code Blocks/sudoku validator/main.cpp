#include <iostream>

using namespace std;

int main()
{
    int k,l,x;
    int a[8]={7,8,3,9,2,1,4,6};
    int b[8]={6,3,7,4,9,5,4,8};
    int c[8]={7,4,3,9,5,8,5,2};
    int d[8]={5,3,6,8,7,9,1,2};
    int e[8]={4,8,6,9,1,2,3,5};
    k=rand();
    cout<<"Enter the missing number from 1-10"<<endl;
    if(k%6==0)
    {
        for(int i=0;i<=7;i++)
        {
            cout<<a[i];
        }
        cin>>l;
        for(int i=0;i<=7;i++)
        {
            if(l==a[i])
            {
                cout<<"You are wrong";
                return 0;
            }
            else
            {
                x++;

            }
        }
    }
    else if(k%5==0)
    {
        for(int i=0;i<=7;i++)
        {
            cout<<b[i]<<" " ;
        }
        cin>>l;
        for(int i=0;i<=7;i++)
        {
            if(l==b[i])
            {
                cout<<"You are wrong";
                return 0;
            }
            else
            {
                x++;

            }
        }
    }
    else if(k%3==0)
    {
        for(int i=0;i<=7;i++)
        {
            cout<<c[i]<<" " ;
        }
        cin>>l;
        for(int i=0;i<=7;i++)
        {
            if(l==c[i])
            {
                cout<<"You are wrong";
                return 0;
            }
            else
            {
                x++;

            }
        }
    }
    else if(k%2==0)
    {
     for(int i=0;i<=7;i++)
        {
            cout<<d[i]<<" " ;
        }
        cin>>l;
        for(int i=0;i<=7;i++)
            {
            if(l==d[i])
            {
                cout<<"You are wrong";
                return 0;
            }
            else
            {
                x++;

            }
        }
    }
    else
    {
        for(int i=0;i<=7;i++)
        {
            cout<<e[i]<<" " ;
        }
        cin>>l;
        for(int i=0;i<=7;i++)
        {
            if(l==e[i])
            {
                cout<<"You are wrong";
                return 0;
            }
            else
            {
                x++;

            }
        }
    }
    if(x!=0)
    {
        cout<<"You are right";
    }
    return 0;
}
