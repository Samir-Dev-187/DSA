#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets)
{
    if(i == nums.size())
    {
        allSubsets.push_back(ans);
        return;
    }

    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allSubsets);

    ans.pop_back();
    int idx = i+1;
    while (idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
    
    getAllSubsets(nums, ans, idx, allSubsets);
}

vector<vector<int>> subSetsWithDup(vector<int> nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main()
{
    vector<int> arr = {1,2,2};
    vector<vector<int>> sets = subSetsWithDup(arr);

    for(int i=0; i<sets.size(); i++)
    {
        for(int j=0; j<sets[i].size(); j++)
        {
            cout << sets[i][j];
        }
        cout << endl;
    }

    return 0;
}