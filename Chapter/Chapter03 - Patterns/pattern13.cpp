/*
A
B A 
C B A
D C B A
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    char ch='A';
    cout << "Enter Number: ";
    cin >> n;

    for(int i=0; i<n; i++){
        for(ch='A'+i; ch>='A'; ch--){
            cout << char(ch) << " ";
        }
        cout << "\n";
    }
}