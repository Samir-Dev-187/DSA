/*
1 2 3 
4 5 6
7 8 9
*/

#include<iostream>
using namespace std;

int main()
{
    int n,i,j;
    int num = 1;
    cout << "Enter Number: ";
    cin >> n;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }
}