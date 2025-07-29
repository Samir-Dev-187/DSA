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

static int idx = -1;
TreeNode* builtTree(vector<int> preorder)
{
    idx++;
    if(preorder[idx] == -1)
    {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = builtTree(preorder); //Left
    root->right = builtTree(preorder); //Right

    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->data == val) return root;

    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    
    return findNode(root->right, val);
}

class Solution
{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            if(root == NULL)
            {
                return NULL;
            }

            if(root->data == p->data || root->data == q->data)
            {
                return root;
            }

            TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

            if(leftLCA && rightLCA)
            {
                return root;
            }
            else if(leftLCA != NULL)
            {
                return leftLCA;
            }
            else
            {
                return rightLCA;
            }
        }
};

int main()
{
    Solution s1;
    vector<int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};

    TreeNode* root = builtTree(preorder);
    TreeNode* nodeP = findNode(root, 7);
    TreeNode* nodeQ = findNode(root, 5);
    

    TreeNode* lca = s1.lowestCommonAncestor(root, nodeP, nodeQ);
    if (lca) cout << "Lowest Common Ancestor is: " << lca->data << endl;
    else cout << "LCA not found!" << endl;

    return 0;
}
