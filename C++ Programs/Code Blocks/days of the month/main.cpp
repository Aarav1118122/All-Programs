#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "enter a month" << endl;
    cin >> a;
    switch(a)
    {

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout <<"It has 31 days.";
            break;
        case 2:
            cout <<"It has 28 or 29 days";
            break;
        default:
            cout <<"it has 30 days";
            break;
    }

    return 0;
}
int main2() {
    main2 main = new main2();
    int b;
    b=10;
    cout << b;
}
