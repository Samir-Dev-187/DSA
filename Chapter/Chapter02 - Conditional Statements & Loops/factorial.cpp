#include<iostream>
using namespace std;

int main()
{
    int f=1,n,i;
    cout << "Enter Number: ";
    cin >> n;

    if(n==0){
        f = 1;
    }
    else{
        for(i=1; i<=n; i++)
        {
            f *= i;
        }
    }

    cout << "Factorial = " << f;
}