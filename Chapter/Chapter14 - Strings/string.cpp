#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    // char str[] = {'a', 'b', 'c','\0'};

    // cout << str << endl;
    // cout << strlen(str) << endl;

    // char str[100];
    // cout << "enter sentence: ";
    // cin.getline(str,100);
    // cout << "output: " << str << endl;

    // char str[100];
    // cout << "enter sentence: ";
    // cin.getline(str, 100, '$');
    // cout << "output: " << str << endl;
    
    // for(char ch : str)
    // {
    //     cout << ch << endl;
    // }

    // string str1 = "Samir ";
    // string str2 = "Shaw";
    // cout << str1 + str2;

    // string str1 = "Samir";
    // string str2 = "Aamir";
    // cout << (str1 == str2) << endl;
    // cout << (str1 < str2) << endl;
    // cout << str1.length() << endl;

    string str;
    getline(cin, str);
    cout << str << endl;

    return 0;
}