#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &nums)
{
    int st = 1, end = nums.size()-2;

    while (st<=end)
    {
        int mid = st + (end-st)/2;
        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
        {
            return mid;
        }
        else if(nums[mid-1] < nums[mid]) //right
        {
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> numsMain = {0,10,5,2};
    cout << peakIndexInMountainArray(numsMain);
}