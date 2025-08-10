#include<iostream>
#include<vector>
#include<queue>
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
        int widthOfBinaryTree(TreeNode* root) 
        {
            queue<pair<TreeNode*, unsigned long long>> q;
            q.push({root, 0});
            int maxWidth = 0;

            while (q.size() > 0)
            {
                int currLevelSize = q.size();
                unsigned long long stIdx = q.front().second;
                unsigned long long endIdx = q.back().second;

                maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

                for(int i=0; i<currLevelSize; ++i)
                {
                    auto curr = q.front();
                    q.pop();

                    if(curr.first->left)
                    {
                        q.push({curr.first->left, curr.second*2+1});
                    }
                    if(curr.first->right)
                    {
                        q.push({curr.first->right, curr.second*2+2});
                    }
                }
            }
            return maxWidth;            
        }
};

int main()
{
    // Constructing a sample binary tree:
    //         1
    //        / \
    //       3   2
    //      /     \
    //     5       9
    //    /         \
    //   6           7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution s1;
    int width = s1.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << width << endl;

    return 0;
}
