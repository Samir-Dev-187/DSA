#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int tar, int st, int end)
{
    if(st <= end)
    {
        int mid = st+(end-st)/2;

        if(arr[mid] == tar) return mid;
        else if(arr[mid] <= tar) return binarySearch(arr, tar, mid+1, end);
        else return binarySearch(arr, tar, st, mid-1);
    }
    return -1;
}

int main()
{
    vector<int> arr = {1,2,4,6,9,12,15,19,21,22,25};
    int tar = 15;
    int st=0, end=arr.size()-1;
    cout << binarySearch(arr, tar, st, end);

    return 0;
}