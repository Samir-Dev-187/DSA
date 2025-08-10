#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n = 4537;
    int revNum = 0;
    while (n>0)
    {
        int dig=n%10;
        if(revNum > INT_MAX/10 || revNum < INT_MIN/10)
        {
            return 0;
        }
        revNum = (revNum*10) + dig;
        n = n/10;
    }
    cout << revNum;
}