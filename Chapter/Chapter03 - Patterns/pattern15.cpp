#include<iostream>
using namespace std;

int main()
{
    int n;
    char ch = 'A';
    cout << "Enter Number: ";
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=n-i; j>0; j--){
            cout <<ch <<" ";
        }

        cout << "\n";

        for(int sp=0; sp<=i; sp++){
            cout << "  ";
        }
        ch++;
    }
}