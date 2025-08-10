#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int curSum=0, maxSum= INT_MIN;

    for(int val: nums)
    {
        curSum += val;
        maxSum = max(curSum,maxSum);
        if(curSum<0)
        {
            curSum=0;
        }
    }
    cout << maxSum << endl;
}