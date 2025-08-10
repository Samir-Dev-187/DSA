#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
    int val; TreeNode *left; TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
    public:
        vector<int> inorderTraversal(TreeNode* root) 
        {
            vector<int> ans;
            TreeNode* curr = root;

            while (curr != NULL)
            {
                if(curr->left == NULL)
                {
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else 
                {
                    //find the IP
                    TreeNode* IP = curr->left;
                    while (IP->right != NULL && IP->right != curr)
                    {
                        IP = IP->right;
                    }

                    if(IP->right == NULL)
                    {
                        IP->right = curr; //create connection
                        curr = curr->left;
                    }
                    else
                    {
                        IP->right = NULL;  //delete connection
                        ans.push_back(curr->val);
                        curr = curr->right;
                    }
                }
            }
            
            return ans;
        }
};

int main()
{
    // Creating a sample tree: 
    //     1
    //      \
    //       2
    //      /
    //     3

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s1;
    vector<int> result = s1.inorderTraversal(root);

    for(int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
