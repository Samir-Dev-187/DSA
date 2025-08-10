#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sortColors(vector<int> &nums)
{  
    int n = nums.size();
    int low=0, mid=0, high=n-1;

    while (mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high],nums[mid]);
            high--;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0,1,2,0,0};
    sortColors(nums);

    for(int num : nums)
    {
        cout << num << " ";
    }
}