#include<iostream>
using namespace std;

int main()
{
    int num;
    int rem;
    cout << "Enter Number: ";
    cin >> num;

    while (num>0)
    {
        rem = num % 10;
        num = num / 10;
        cout << rem;
    }
    
}