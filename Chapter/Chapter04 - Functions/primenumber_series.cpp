#include<iostream>
using namespace std;

int primeNumbers(int n);

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    primeNumbers(n);
}

int primeNumbers(int n)
{
    for(int i=2; i<=n; i++){
        int f = 1;
        for(int j=2; j<=i-1; j++)
        {
            if(i%j == 0){
                f=0;
                break;
            }
        }
        if(f==1)
        {
            cout << i << " ";
        }
    }
}