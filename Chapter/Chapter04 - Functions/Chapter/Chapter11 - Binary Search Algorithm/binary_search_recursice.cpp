#include<iostream>
#include<vector>
using namespace std;

int recursiveBinarySearch(vector<int> arr, int tar, int st, int end)
{
    if(st<=end)
    {
        int mid = st + (end-st)/2;

        if(tar > arr[mid])
        {
            return recursiveBinarySearch(arr,tar,mid+1,end);
        }
        else if(tar < arr[mid])
        {
            return recursiveBinarySearch(arr,tar,st,mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1,0,3,4,5,9,12};
    int tar1 = 12;

    vector<int> arr2 = {-1,0,3,5,9,12};
    int tar2 = 0;
    cout << recursiveBinarySearch(arr1,tar1,0,arr1.size()-1) << endl;

    return 0;
}