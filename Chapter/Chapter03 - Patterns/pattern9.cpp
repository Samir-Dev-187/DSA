#include<iostream>
using namespace std;

int main()
{
    int n,sp;
    int i,j;
    cout << "Enter Number: ";
    cin >> n;

    for(i=1; i<=n; i++){
        for(sp=n-i; sp>=0; sp--){
            cout << "  ";
        }

        for(j=1; j<=i; j++){
            cout << j << " ";
        }

        for(int k=j-1; k>1; k--){
            cout << k-1 << " ";
        }
        cout << "\n";
    }
}