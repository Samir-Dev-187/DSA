#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int n = nums.size();
    int count = 0;

    for (int i=0; i<n; i++) //starting point
    {
        int sum = 0;
        for(int j=i; j<n; j++) //ending
        {
            sum += nums[j];
            if(sum == k) count++;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {1,1,1};
    int k = 2;

    cout << subarraySum(nums, k);

    return 0;
}