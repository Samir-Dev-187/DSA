#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
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
        int prevOrder = 0;

        int kthSmallest(TreeNode* root, int k)
        {
            if(root == NULL)
            {
                return -1;
            }

            if(root->left != NULL)
            {
                int leftAns = kthSmallest(root->left, k);
                if(leftAns != -1)
                {
                    return leftAns;
                }
            }

            if(prevOrder + 1 == k)
            {
                return root->val;
            }
            prevOrder = prevOrder + 1;

            if(root->right != NULL)
            {
                int rightAns = kthSmallest(root->right, k);
                if(rightAns != -1)
                {
                    return rightAns;
                }
            }

            return -1;
        }
};

int main()
{
    Solution s1;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;

    cout << s1.kthSmallest(root, k);
    cout << endl;

    return 0;
}