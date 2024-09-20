#include <iostream>

using namespace std;

int main()
{
    char letter;
    cout <<"Enter an alphabet : a b c d :";
    cin>>letter ;
     switch (letter)
     {
       case 'a': cout<< "apple";
       break;
       case 'b': cout<< "banana";
       break;
       case 'c': cout<< "cherry";
       break;
       case 'd': cout<< "dragon fruit";
       break;
       default:
       cout<<"invalid";
       break;
     }
    return 0;
}
