#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> height)
{
    int maxWater = 0;

    for(int i=0; i<height.size(); i++)
    {
        for(int j=i+1; j<height.size(); j++)
        {
            int w = j-i;
            int ht = min(height[i], height[j]);
            int curWater = w * ht;

            maxWater = max(maxWater, curWater);
        }
    }

    return maxWater;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height);
}