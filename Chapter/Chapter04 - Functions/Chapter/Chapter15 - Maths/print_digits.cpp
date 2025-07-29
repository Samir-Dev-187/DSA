#include<iostream>
using namespace std;

int main()
{
    int n = 3568;
    while (n>0)
    {
        int x = n%10;
        n = n/10;
        cout << x << " ";
    }
    
}