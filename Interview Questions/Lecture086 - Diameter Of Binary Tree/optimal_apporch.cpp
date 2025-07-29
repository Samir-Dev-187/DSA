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
    int ans = 0;

        int height(TreeNode* root) //O(n)
        {
            if(root == NULL) return 0;

            int leftHt = height(root->left);
            int rightHt = height(root->right);

            ans = max(ans, leftHt + rightHt); //currDiam of root Node
            return max(leftHt, rightHt) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root)
        {
            height(root);

            return ans;
        }
};

int main()
{
    Solution s1;
    vector<int> preorder = {1,2,3,-1,-1,-1,4,5,-1,-1,-1};
    int idx = -1;
    TreeNode* root = builtTree(preorder, idx);

    cout << s1.diameterOfBinaryTree(root);

    return 0;
}