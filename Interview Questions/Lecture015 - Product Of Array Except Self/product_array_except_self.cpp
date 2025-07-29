#include<iostream>
#include<vector>
using namespace std;

vector<int> productArray(vector<int> nums)
{
    vector<int> ans;

    for(int i=0; i<nums.size(); i++)
    {
        int p=1;
        for(int j=0; j<nums.size(); j++)
        {
            if(j==i)    
            {
                continue;
            }
            p *=nums[j];
        }
        ans.push_back(p);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productArray(nums);
    
    for(int val: ans)
    {
        cout << val << " ";
    }
}