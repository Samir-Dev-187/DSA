#include<iostream>
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
        bool helper(TreeNode* root, TreeNode* min, TreeNode* max)
        {
            if(root == NULL) return true;

            if(min != NULL && root->val <= min->val) return false;

            if(max != NULL && root->val >= max->val) return false;

            return helper(root->left, min, root) && helper(root->right, root, max);
        }
        bool isValidBST(TreeNode* root) 
        {
            return helper(root, NULL, NULL);
        }
};

int main()
{
    Solution s1;
    // TreeNode* root = new TreeNode(5);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(4);
    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(6);

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << s1.isValidBST(root);
    
    return 0;
}