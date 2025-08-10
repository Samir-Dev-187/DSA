#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> bubbleSort(vector<int> &nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        bool isSwap = false;
        for(int j=0; j<nums.size()-1-i; j++)
        {
            if(nums[j]>nums[j+1])
            {
                swap(nums[j],nums[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap)
        {
            return nums;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {4,1,5,2,3};
    // vector<int> ans = bubbleSort(nums);
    bubbleSort(nums);

    for(int num : nums)
    {
        cout << num << " ";
    }
}