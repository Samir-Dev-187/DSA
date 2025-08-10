#include<iostream>
using namespace std;

int gcdRecursion(int a, int b)
{
    if(b==0) return a;

    return gcdRecursion(b, a%b);
}

int main()
{
    cout << gcdRecursion(20,24);

    return 0;
}