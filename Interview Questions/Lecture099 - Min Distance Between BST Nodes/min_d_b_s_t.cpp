#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
        TreeNode* prev = NULL;

        int minDiffInBST(TreeNode* root)
        {
            if(root == NULL)
            {
                return INT_MAX;
            }

            int ans = INT_MAX;
            if(root->left != NULL)
            {
                int leftMin = minDiffInBST(root->left);
                ans = min(ans, leftMin);
            }

            if(prev != NULL)
            {
                ans = min(ans, root->val - prev->val);
            }
            prev = root;

            if(root->right != NULL)
            {
                int rightMin = minDiffInBST(root->right);
                ans = min(ans, rightMin);
            }

            return ans;
        }
};

int main()
{
    Solution s1;
    // TreeNode* root = new TreeNode(4);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(6);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(48);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(49);

    cout << s1.minDiffInBST(root) << endl;

    return 0;
}