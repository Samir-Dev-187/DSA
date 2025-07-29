#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& arr)
{
    int slow = arr[0], fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    
    slow  = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main()
{
    vector<int> num = {1,3,4,2,2};
    cout << findDuplicate(num);

    return 0;
}