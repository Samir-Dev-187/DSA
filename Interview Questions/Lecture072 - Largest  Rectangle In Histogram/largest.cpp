#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    public:
        int largestRectangleArea(vector<int>& heights)
        {
            int n = heights.size();
            vector<int> left(n, 0);
            vector<int> right(n, 0);
            stack<int> s;

            //right smaller
            for(int i=n-1; i>=0; i--)
            {
                while(s.size() > 0 && heights[s.top()] >= heights[i])
                {
                    s.pop();
                }
                right[i] = s.empty() ? n : s.top();
                s.push(i);
            }

            s.empty();

            //left samller
            for(int i=0; i<n; i++)
            {
                while(s.size() > 0 && heights[s.top()] >= heights[i])
                {
                    s.pop();
                }
                left[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }

            int ans = 0;
            for(int i=0; i<n; i++)
            {
                int width = right[i] - left[i] - 1;
                int currArea = heights[i]*width;
                ans = max(ans, currArea);
            }

            return ans;
        }
};

int main()
{
    Solution s1;
    vector<int> nums = {2,1,5,6,2,3};
    
    int result =  s1.largestRectangleArea(nums);
    cout << result;
    cout << endl;
    
    return 0;
}