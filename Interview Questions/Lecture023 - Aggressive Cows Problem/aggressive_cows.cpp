#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int minAllowedDist)
{
    int cows = 1, lastStallPos = arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i]-lastStallPos>=minAllowedDist)
        {
            cows++;
            lastStallPos = arr[i];
        }
        if(cows==c)
        {
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &arr, int n, int c)
{
    sort(arr.begin(),arr.end()); ///nlogn

    int st=1, end=arr[n-1]-arr[0], ans=-1;

    while (st <= end) //O((logRange)*n)
    {
        int mid = st + (end-st)/2;
        if(isPossible(arr,n,c,mid)) //right
        {
            ans=mid; 
            st=mid+1;
        }
        else //left
        {
            end = mid-1;
        }
    }
    return ans;
}

int main()
{
    int n=5, c=3;
    vector<int> arr = {1,2,8,4,9};
    cout << getDistance(arr,n,c);
    return 0;
}