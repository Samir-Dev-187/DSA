#include<iostream>
using namespace std;

int main()
{
    string str = "Ac3?e3c&a";
    int st=0, end = str.length()-1;
    int f=1;

    while (st<=end)     
    {
        if(str.length() == 1)
        {
            f = 0;
            cout << "Not Palindrome";
            break;
        }
        if(str[st]==str[end])
        {
            f = 1;
        }
        else
        {
            f=0;
            cout << "Not Palindrome";
            break;
        }
        st++;
        end--;
    }

    if(f==1)
    {
        cout << "Palindrome";
    }

    return 0;
}