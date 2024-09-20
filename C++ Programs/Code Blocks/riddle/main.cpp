
#include <iostream>

using namespace std;
void riddle(char,char);
int main()
{
    char ans;
    char ask;
    cout <<"1,5,25,15,20,10,_"<<endl;
    cout <<"Fill in the blank or pass(p).If you are in trouble ask for hint(h)"<<endl;
    cin>>ans;
    if (ans=='h')
    {
        cout <<"It is an one digit number."<<endl;
        cin>>ans;
        riddle(ans,'5');
    }
    else
    {
        riddle(ans,'5');
    }
    cout <<"Next? y or n."<<endl;
    cin >>ask;
    if (ask=='y')
    {
    cout <<"1,6,36,18,42,12,_"<<endl;
    cout<<"Fill in the blank or pass(p).If you are in trouble ask for hint(h)"<<endl;
    cin >>ans;
    if (ans=='h')
    {
        cout <<"It is an one digit number."<<endl;
        cin>>ans;
        riddle(ans,'6');
    }
    else
    {
        riddle(ans,'6');
    }
    }
    else
    {
     return 0;
    }

    return 0;
}
void riddle(char ans, char anw)
{
    if (ans==anw)
    {
        cout <<"CORRECT" <<endl;
    }
    else if(ans=='p')
    {
        cout <<"Ans is "<<anw<<"."<<endl;
    }
    else
    {
        cout <<"WRONG.Ans is "<<anw<<"."<<endl;
    }
}
