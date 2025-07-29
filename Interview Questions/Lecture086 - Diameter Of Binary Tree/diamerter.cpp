#include<iostream>
#include<vector>
using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val)
        {
            data = val;
            left = right = NULL;
        }
};

TreeNode* builtTree(vector<int>& preorder, int& idx)
{
    idx++;

    if(idx >= preorder.size() || preorder[idx] == -1)
    {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = builtTree(preorder, idx); //LEFT
    root->right = builtTree(preorder, idx); //RIGHT

    return root;
};

class Solution
{
    public:
        int height(TreeNode* root) //O(n*n)
        {
            if(root == NULL) return 0;

            int leftHt = height(root->left);
            int rightHt = height(root->right);

            return max(leftHt, rightHt) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root)
        {
            if(root == NULL) return 0;

            int leftDiam = diameterOfBinaryTree(root->left);
            int rightDiam = diameterOfBinaryTree(root->right);
            int currDiam = height(root->left) + height(root->right);

            return max(currDiam, max(leftDiam, rightDiam));
        }
};

int main()
{
    Solution s1;
    vector<int> preorder = {1,2,3,4,-1,-1,-1,-1,5,6,-1,7,-1,-1,-1};
    int idx = -1;
    TreeNode* root = builtTree(preorder, idx);

    cout << s1.diameterOfBinaryTree(root);

    return 0;
}