#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        {
            if(root == NULL)
            {
                return NULL;
            }

            if(root->val > p->val && root->val > q->val) // left subtree
            {
                lowestCommonAncestor(root->left, p, q);
            }
            else if(root->val < p->val && root->val < q->val) // right subtree
            {
                lowestCommonAncestor(root->right, p, q);
            }
            else 
            {
                return root;
            }

            return NULL;
        }
};

int main()
{
    Solution s1;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);

    TreeNode* ans = s1.lowestCommonAncestor(root, p, q);
    cout << ans->val;
    cout << endl;

    return 0;
}