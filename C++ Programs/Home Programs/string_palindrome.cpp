#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char string[200], reverseString[200];
    char *str = string, *rstr = reverseString;
    cout << "Enter a string" << endl;
    gets(string);
    int stringLen = strlen(str);
    string[stringLen] = '\0';
    reverseString[stringLen] = '\0';
    for (int i = 0; i < stringLen; i++)
    {
        reverseString[i] = string[stringLen - i - 1];
    }
    cout << string << "\n" << reverseString << endl;
    if (strcmp(str, rstr) == 0)
    {
        cout << "This is a palindrome string" << endl;
    }
    else
    {
        cout << "This is not a palindrome string" << endl;
    }

    return 0;
}