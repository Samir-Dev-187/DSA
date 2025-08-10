#include<iostream>
using namespace std;

int sumOfNumbers(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n + sumOfNumbers(n-1);
}

int main()
{
    cout << sumOfNumbers(5);
}