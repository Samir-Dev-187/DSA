#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int majorityElement(vector<int> nums, int n)
{
    sort(nums.begin(), nums.end());

    int freq = 1, ans = nums[0];
    for(int i=1; i<n; i++)
    {
        if(nums[i] == nums[i-1])
        {
            freq++;
        }
        else
        {
            freq=1;
            ans = nums[i];
        }

        if(freq > n/2)
        {
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3,2,3};
    int n = nums.size();
    int val = majorityElement(nums,n);
    cout << val << endl;
}