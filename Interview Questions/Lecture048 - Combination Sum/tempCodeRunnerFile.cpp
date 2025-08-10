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