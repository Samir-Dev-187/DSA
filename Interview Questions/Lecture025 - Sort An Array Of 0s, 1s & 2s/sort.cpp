#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sortColors(vector<int> &nums)
{  
    int count0 = 0;    
    int count1 = 0;    
    int count2 = 0;    
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]==0) count0++;
        else if(nums[i]==1) count1++;
        else if(nums[i]==2) count2++;
    }

    int idx = 0;
    for(int i=0; i<count0; i++)
    {
        nums[idx++] = 0;
    }
        for(int i=0; i<count1; i++)
    {
        nums[idx++] = 1;
    }
        for(int i=0; i<count2; i++)
    {
        nums[idx++] = 2;
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