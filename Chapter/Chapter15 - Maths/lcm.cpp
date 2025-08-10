#include<iostream>
using namespace std;

int gcdRecursion(int a, int b)
{
    if(b==0) return a;

    return gcdRecursion(b, a%b);
}

int lcm(int a, int b)
{
    int gcd = gcdRecursion(a,b);
    return (a*b)/gcd;
}

int main()
{
    cout << lcm(20,28);

    return 0;
}