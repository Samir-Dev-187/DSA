#include<iostream>
using namespace std;

int main()
{
    bool prime=true;
    int n=47;
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            prime=false;
            cout << "Not A Prime Number";
            break;
        }
    }
    if(prime==true)
    {
        cout << "Prime Number";
    }
}