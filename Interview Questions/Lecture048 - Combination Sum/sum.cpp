#include<iostream>
#include<vector>
#include<set>
using namespace std;

void getAllCombinations(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin,  set<vector<int>> s)
{
    if(idx == arr.size() || tar<0)
    {
        return;
    }

    if(tar == 0)
    {
        if(s.find(combin) == s.end())
        {   
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);
    //single
    getAllCombinations(arr, idx, tar-arr[idx], ans, combin, s);
    combin.pop_back();

    //exclusion
    getAllCombinations(arr, idx+1, tar, ans, combin, s);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> combin;
    set<vector<int>> s;

    getAllCombinations(arr, 0, target, ans, combin, s);

    return ans;
}

int main()
{
    vector<int> arr = {2,3,6,7};
    int tar = 7;
    vector<vector<int>> ans = combinationSum(arr, tar);
    

    for(auto num : ans)    
    {
        cout << "[";
        for(int val : num)
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
}