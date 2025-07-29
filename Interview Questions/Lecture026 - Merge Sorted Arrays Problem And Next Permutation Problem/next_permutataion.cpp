#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutataion(vector<int> &A)
{
    // find the pivot
    int pivot = -1, n=A.size();

    for(int i=n-1; i>=0; i--)
    {
        if(A[i] < A[i+1])
        {
            pivot = i;
            break;
        }
    }

    if(pivot == -1)
    {
        reverse(A.begin(), A.end()); // in place changes
        return;
    }

    //2nd step: next larger element
    for(int i=n-1; i>pivot; i--)
    {
        if(A[i] > A[pivot])
        {
            swap(A[i], A[pivot]);
            break;
        }
    }

    // 3rd step: reverse (piv+1 to n-1)
    // reverse(A.begin() + pivot + 1, A.end());

    int i=pivot+1, j=n-1;
    while (i <= j)
    {
        swap(A[i++], A[j--]);
    }
    
}

int main()
{
    vector<int> arr = {1,2,3,5,4};
    nextPermutataion(arr);

    for(int a : arr)
    {
        cout << a << " ";
    }
}