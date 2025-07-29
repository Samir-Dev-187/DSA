#include<iostream>
using namespace std;

void printFactorial(int x);

int main()
{
    int n; 
    cout << "Enter Number: ";
    cin >> n;
    printFactorial(n);
}

void printFactorial(int x)
{
    int f = 1;
    for(int i=1; i<=x; i++){
        f *= i;
    }
    printf("%d",f);
}