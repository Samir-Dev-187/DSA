#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
    public:            
        TreeNode* helper(vector<int>& nums, int st, int end)
        {
            if(st > end)
            {
                return NULL;
            }

            int mid = st + (end-st)/2;
            TreeNode* root = new TreeNode(nums[mid]);

            root->left = helper(nums, st, mid-1);
            root->right = helper(nums, mid+1, end);

            return root;
        }

        TreeNode* sortedArrayToBST(vector<int>& nums) 
        {
            return helper(nums, 0, nums.size()-1);
        }

        void levelOrder(TreeNode* root)
        {
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty())
            {
                TreeNode* node = q.front();
                q.pop();

                if (node)
                {
                    cout << node->val << " ";
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    cout << "null ";
                }
            }
        }
};

int main()
{
    Solution s1;
    vector<int> nums = {-10, -3, 0, 5, 9};
    cout << "Before: ";
    for(int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "After: ";
    TreeNode* root = s1.sortedArrayToBST(nums);
    s1.levelOrder(root);    
    cout << endl;
    
    return 0;
}