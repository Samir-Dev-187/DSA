#include<iostream>
using namespace std;

int main()
{
    int n,sp=0;
    cout << "Enter Number: ";
    cin >> n;

    for(int i=1; i<=n; i++){
        
        for(int j=0; j<=n-i; j++){
            cout << i << " ";
        }
        cout << "\n";
        for(sp=1; sp<=i; sp++){
            cout << "  ";
        }
    }
}