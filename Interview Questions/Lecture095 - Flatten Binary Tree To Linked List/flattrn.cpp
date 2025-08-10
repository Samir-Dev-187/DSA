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
        TreeNode* nextRight = NULL;
        void flatten(TreeNode* root) 
        {
            if(root == NULL)
            {
                return;
            }

            flatten(root->right);
            flatten(root->left);

            root->left = NULL;
            root->right = nextRight;
            nextRight = root;
        }

        void printTree(TreeNode* node)
        {
            if(node == NULL)
            {
                cout << " null ";
                return;
            }

            cout << node->val;
            printTree(node->left);
            printTree(node->right);
        }
};

int main()
{
    Solution s1;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    s1.flatten(root);
    s1.printTree(root);
    
    return 0;
}