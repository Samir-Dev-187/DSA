#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> insertionSort(vector<int> &nums)
{
    for(int i=1; i<nums.size(); i++)
    {
        int curr = nums[i];
        int prev = i-1;

        while(prev >= 0 && nums[prev]>curr)
        {
           nums[prev+1]=nums[prev];
           prev--;
        }
        nums[prev+1] = curr;
    }
    return nums;
}

int main()
{
    vector<int> nums = {4,1,5,2,3};
    insertionSort(nums);

    for(int num : nums)
    {
        cout << num << " ";
    }
}