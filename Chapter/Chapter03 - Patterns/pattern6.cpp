/*
1
2 1 
3 2 1
4 3 2 1
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;

    for(int i=1; i<=n; i++){
        int num = i;
        for(int j=1; j<=i; j++){
            cout << num << " ";
            num--;
        }
        cout << "\n";
    }
}