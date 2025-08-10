#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int st = 0, end = nums.size()-1;

    while (st <=end)
    {
        int mid = st + (end-st)/2;
        if(nums[mid]==target)
        {
            return mid;
        }

        if(nums[st] <= nums[mid]) // left sorted
        {  
            if(nums[st] <= target && target <= nums[mid])
            {
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        } 
        else{ //right sorted
            if(nums[mid] <= target && target <= nums[end])
            {
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {6,7,0,1,2,3,4};
    int target = 7;
    cout << endl;
    cout << search(nums,target);
}