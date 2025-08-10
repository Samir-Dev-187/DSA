#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    unordered_set<int> s;

    for(int val : nums)
    {
        if(s.find(val) != s.end())
        {
            return val;
        }
        s.insert(val);
    }
    return -1;
}

int main()
{
    vector<int> nums = {0,9,3,6,8,2,6,4,2};
    cout << findDuplicate(nums);

    return 0;
}