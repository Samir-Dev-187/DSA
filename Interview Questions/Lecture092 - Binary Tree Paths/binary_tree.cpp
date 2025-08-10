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

void preOrder(TreeNode* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

class Solution
{
    public:
        void allPaths(TreeNode* root, string path, vector<string>& ans)
        {
            if(root->left == NULL && root->right == NULL)
            {
                ans.push_back(path);
                return;
            }

            if(root->left)
            {
                allPaths(root->left, path+"->"+to_string(root->left->data), ans);
            }

            if(root->right)
            {
                allPaths(root->right, path+"->"+to_string(root->right->data), ans);
            }
        }

        vector<string> binaryTreePaths(TreeNode* root)
        {
            vector<string> ans;
            string path = to_string(root->data);

            allPaths(root, path, ans);
            return ans;
        }
};

int main()
{
    Solution s1;
    vector<int> preorder = {1,2,5,-1,-1,-1,3,-1,-1};
    TreeNode* root = builtTree(preorder);

    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    vector<string> paths = s1.binaryTreePaths(root);

    cout << "Root-to-leaf Paths: " << endl;
    for(const string& path : paths)
    {
        cout << path << endl;
    }
    cout << endl;
}