// find out how to find if a number is power of 2 without any loop.

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;

    if (n > 0 && (n & (n - 1)) == 0)
        cout << n << " is power of 2";
    else
        cout << n << " is not power of 2";
}
