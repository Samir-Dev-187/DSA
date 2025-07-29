#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> nums,int n)
{
    for(int val:nums)
    {
        int freq = 0;

        for(int el: nums)
        {
            if(el == val)
            {
                freq++;
            }
            if(freq>n/2)
            {
                return val;
            }
        }
    }
}

int main()
{
    vector<int> nums = {3,2,3};
    int n = nums.size();
    int val = majorityElement(nums,n);
    cout << val << endl;
}