#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> selectionSort(vector<int> &nums)
{
    for(int i=0; i<nums.size()-1; i++)
    {   
        int smallestIdx = i;
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[j] < nums[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(nums[i], nums[smallestIdx]);
    }
    return nums;
}

int main()
{
    vector<int> nums = {4,1,5,2,3};
    selectionSort(nums);

    for(int num : nums)
    {
        cout << num << " ";
    }
}