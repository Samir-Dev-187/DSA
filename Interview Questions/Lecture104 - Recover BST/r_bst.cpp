#include<iostream>
#include<vector>
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
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* sec = NULL;

        void inorder(TreeNode* root) //O(n)
        {
            if(root == NULL)
            {
                return;
            }
            inorder(root->left);

            if(prev != NULL && prev->val > root->val)
            {
                if(first == NULL)
                {
                    first = prev;
                }
                sec = root;
            }
            prev = root;
            inorder(root->right);
        }

        void recoverTree(TreeNode* root) 
        {
            //inorder => first, sec
            // first, sec =>swap
            inorder(root);

            int temp = first->val;
            first->val = sec->val;
            sec->val = temp;
        }

        void printBST(TreeNode* root)
        {
            if(root == NULL)
            {
                return;
            }
            cout << root->val << " ";
            printBST(root->left);
            printBST(root->right);
        }
};

int main()
{
    Solution s1;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    s1.recoverTree(root);
    s1.printBST(root);
    cout << endl;

    return 0;
}