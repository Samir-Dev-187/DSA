#include<iostream>
using namespace std;

int primeOrNot(int n);

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    primeOrNot(n);
}

int primeOrNot(int n)
{
    int f = 1;
    for(int i=2; i<n; i++)
    {
        if(n%i == 0)
        {
            f = 0;
            break;
        }
    }
    if(f==1){
        cout << n << " is Prime Number";
    }else
    {
        cout << n << " is not a Prime Number";
    }
    
}