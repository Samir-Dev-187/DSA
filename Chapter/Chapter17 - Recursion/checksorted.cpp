#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int> arr, int n)
{
    if(n==0 || n==1)
    {
        return true;
    }

    return arr[n-1] >= arr[n-2] && checkSorted(arr, n-1);
}

int main()
{
    vector<int> arrs = {1,2,3,4,5};
    cout << checkSorted(arrs, arrs.size());

    return 0;
}