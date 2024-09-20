#include <iostream>

using namespace std;

int movplr(int postn, int ply);
int rolldice();


int main()
{
    int plyrs[4];
    int plyr = 0;
    while (plyr<4)
        plyrs[plyr++]=1;
    int cnt;
    cout<<"No of Players?";
    cin>>cnt;
    plyr=0;
    do
    {
        if (plyr==cnt)
            plyr=0;
        plyrs[plyr]=movplr(plyrs[plyr],plyr+1);
        plyr++;
    }
    while(plyrs[plyr-1]!=100);
    cout<<"PLAYER "<<plyr<<" WINS"<<endl;
    return(0);
}

int movplr(int postn, int ply)
{
    int rll;
    cout<<"Player "<<ply<<", Press Enter to Roll"<<endl;
    cin.get();
    rll=rolldice();
    if ((postn+rll)>100)
        cout<<"Turn Wasted"<<endl;
    else
        postn=postn+rll;
    switch(postn)
    {
        case 8:
            cout<<"YOU CLIMBED THE LADDER"<<endl;
            postn=26;
            break;
        case 19:
            cout<<"YOU CLIMBED THE LADDER"<<endl;
            postn=38;
            break;
        case 21:
            cout<<"YOU CLIMBED THE LADDER"<<endl;
            postn=82;
            break;
        case 28:
            cout<<"YOU CLIMBED THE LADDER"<<endl;
            postn=53;
            break;
        case 36:
            cout<<"YOU CLIMBED THE LADDER"<<endl;
            postn=57;
            break;
        case 54:
            cout<<"YOU CLIMBED THE LADDER"<<endl;
            postn=88;
            break;
        case 63:
            cout<<"YOU CLIMBED THE LADDER"<<endl;
            postn=96;
            break;
        case 46:
            cout <<"OOPS!SNAKE"<<endl;
            postn=15;
            break;
        case 52:
            cout <<"OOPS!SNAKE"<<endl;
            postn=11;
            break;
        case 59:
            cout <<"OOPS!SNAKE"<<endl;
            postn=18;
            break;
        case 64:
            cout <<"OOPS!SNAKE"<<endl;
            postn=24;
            break;
        case 68:
            cout <<"OOPS!SNAKE"<<endl;
            postn=2;
            break;
        case 83:
            cout <<"OOPS!SNAKE"<<endl;
            postn=22;
            break;
        case 89:
            cout <<"OOPS!SNAKE"<<endl;
            postn=51;
            break;
        case 93:
            cout <<"OOPS!SNAKE"<<endl;
            postn=45;
            break;
        case 98:
            cout <<"OOPS!SNAKE"<<endl;
            postn=13;
            break;
        }
    cout<<"Player "<<ply<<", You are at "<<postn<<endl<<endl;
    return postn;
}
int rolldice()
{
    int dice=0;
    int roll=0;
    int cnt=0;
    do
    {
        roll=(rand()%6)+1;
        cout<<"You Roll a "<<roll<<endl;
        dice=dice+roll;
        if(cnt++==3)
        {
            cnt=0;
            dice=0;
        }
    }
    while(roll==6);
    return(dice);
}
