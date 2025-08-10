/*
1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4
*/

#include<iostream>
using namespace std;

int main()
{
    int n,i,j;
    cout << "Enter Number: ";
    cin >> n;

    for (i=1; i <=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%d ",j);
        }
        cout << "\n";
    }

    return 0;
    
}