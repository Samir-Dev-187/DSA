#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n = 111;
    int num = n;
    int sum = 0;

    while (n>0)
    {
        int x = n%10;
        sum += (x*x*x);
        n = n/10;
    }

    if(sum==num)
    {
        cout << "Armstrong Number";
    }
    else
    {
        cout << "Not A Armstrong Number";
    }
    
    
}