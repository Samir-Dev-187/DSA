#include<iostream>
#include<vector>
#include<queue>
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
        TreeNode* helper(vector<int>& preorder, int &i, int bound)
        {
            if(i == preorder.size() || preorder[i] > bound)
            {
                return NULL;
            }

            TreeNode* root = new TreeNode(preorder[i++]);
            root->left = helper(preorder, i, root->val);
            root->right = helper(preorder, i, bound);

            return root;
        }

        TreeNode* bstFromPreorder(vector<int>& preorder) 
        {
            int i = 0;
            return helper(preorder, i, INT_MAX);
        }

        void printLevelOrder(TreeNode* root)
    {
        if (!root) {
            cout << "[]\n";
            return;
        }

        vector<string> output;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                output.push_back(to_string(curr->val));
                q.push(curr->left);
                q.push(curr->right);
            } else {
                output.push_back("null");
            }
        }

        // Remove trailing "null"s
        while (!output.empty() && output.back() == "null")
            output.pop_back();

        // Print as [8,5,10,1,7,null,12]
        cout << "[";
        for (int i = 0; i < output.size(); ++i) {
            cout << output[i];
            if (i != output.size() - 1)
                cout << ",";
        }
        cout << "]\n";
    }

};

int main()
{
    Solution s1;
    vector<int> preorder = {8,5,1,7,10,12};

    TreeNode* root = s1.bstFromPreorder(preorder);
    s1.printLevelOrder(root);

    return 0;
}