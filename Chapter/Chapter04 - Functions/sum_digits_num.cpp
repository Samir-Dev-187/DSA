#include<iostream>
using namespace std;

int sumDigits(int y);

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    sumDigits(n);

}

int sumDigits(int y)
{
    int x,sum=0;

    while(y!=0)
    {
        x = y%10;
        y =y/10;
        sum = sum+x;
    }
    cout << sum;
}