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
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            if(p==NULL || q==NULL) return p == q;   

            bool isLeftSame = isSameTree(p->left, q->left);
            bool isRightSame = isSameTree(p->right, q->right);

            return isLeftSame && isRightSame && p->data == q->data;
        }
};

int main()
{
    Solution s1;
    vector<int> preorder1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1}; 
    vector<int> preorder2 = {1,2,-1,-1,3,4,-1,-1,5,-1, 2};
    int idx1 = -1;
    int idx2 = -1;

    TreeNode* root1 = builtTree(preorder1, idx1);
    TreeNode* root2 = builtTree(preorder2, idx2);

    cout << (s1.isSameTree(root1, root2) ? "Trees are same" : "Trees are different") << endl;
    
    return 0;
}