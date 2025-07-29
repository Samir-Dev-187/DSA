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
        bool isIdentical(TreeNode* p, TreeNode* q)
        {
            if(p==NULL || q==NULL) return p == q;

            return p->data == q->data && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
        }

        bool isSubTree(TreeNode* root, TreeNode* subRoot)
        {
            if(root==NULL || subRoot==NULL) return root == subRoot;

            if(root->data == subRoot->data && isIdentical(root, subRoot)) return true;  

            return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
        }
};

int main()
{
    Solution s1;
    vector<int> preorder1 = {1,2,-1,-1,3,3,5,-1,-1,6,-1,-1,3,5,-1,-1,7,-1,-1}; 
    vector<int> preorder2 = {3,6,-1,-1,6,-1,-1};
    int idx1 = -1;
    int idx2 = -1;

    TreeNode* root1 = builtTree(preorder1, idx1);
    TreeNode* root2 = builtTree(preorder2, idx2);

    cout << (s1.isSubTree(root1, root2) ? "Subroot are same" : "Subroot are different") << endl;
    
    return 0;
}