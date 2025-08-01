
//Corective apporch

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

class Solution
{
    public:
        int search(vector<int>& inorder, int left, int right, int val)
        {
            for(int i=left; i<=right; ++i)
            {
                if(inorder[i] == val)
                {
                    return i;
                }
            }

            return -1;
        }

        TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right)
        {
            if(left > right)
            {
                return NULL;
            }

            TreeNode* root = new TreeNode(preorder[preIdx]);
            
            int inIdx = search(inorder, left, right, preorder[preIdx]);
            preIdx++;
            root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
            root->right = helper(preorder, inorder, preIdx, inIdx+1, right);

            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
        {
            int preIdx = 0;
            return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
        }

        void printPreorder(TreeNode* root)
        {
            if(!root) return;
            cout << root->data << " ";
            printPreorder(root->left);
            printPreorder(root->right);
        }


};

int main()
{
    Solution s1;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* root = s1.buildTree(preorder, inorder);
    s1.printInorder(root);

    return 0;
}