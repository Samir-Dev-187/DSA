#include<iostream>
using namespace std;

int main()
{
    int arr[7] = {4,2,7,8,1,2,5};
    int s=50,f=0;
    for(int i=0; i<7; i++)
    {
        if(arr[i]==s)
        {
            cout << "Item Found At: " << i << " Index";
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout << "Item Not Found!";
    }
}