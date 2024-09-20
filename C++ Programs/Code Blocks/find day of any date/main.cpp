#include <iostream>

using namespace std;

int main()
{
    int d;
    int m;
    int y;
    int y1;
    int m1;
    int l2d;
    int dn;
    cout <<"enter date ";
    cin >>d;
    cout <<"enter month(number) ";
    cin >>m;
    cout <<"enter year ";
    cin >> y;
    switch(m)
    {
        case 1:
        case 10:
        m1=0;
        break;
        case 2:
        case 3:
        case 11:
        m1=3;
        break;
        case 4:
        case 7:
        m1=6;
        break;
        case 5:
        m1=1;
        break;
        case 6:
        m1=4;
        break;
        case 8:
        m1=2;
        break;
        case 9:
        case 12:
        m1=5;
        break;
    }
    if(y<1600||y>=2100)
        cout<<"Out of Range";
    else if(y<1700)
        y1=6;
    else if(y<1800)
        y1=4;
    else if(y<1900)
        y1=2;
    else if(y<2000)
        y1=0;
    else
        y1=6;
    l2d=y%100;
    dn=(d+m1+l2d+(l2d/4)+y1)%7;
    if (dn==0)
        cout <<"sunday";
    else if (dn==1)
        cout <<"monday";
    else if (dn==2)
        cout <<"tuesday";
    else if (dn==3)
        cout <<"wednesday";
    else if (dn==4)
        cout <<"thursday";
    else if (dn==5)
        cout <<"friday";
    else
        cout <<"saturday";
return 0;
}
