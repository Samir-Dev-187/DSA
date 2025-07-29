#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Info
{
    public:
        int min, max, size;

        Info(int mi, int ma, int sz)
        {
            this->min = mi;
            this->max = ma;
            this->size = sz;
        }
};

Info helper(Node* root) //O(n)
{
    if(root == NULL)
    {
        return Info(INT_MAX, INT_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->val > left.max && root->val < right.min)
    {
        int currMin = min(root->val, left.min);
        int currMax = max(root->val, right.max);
        int currSz = left.size + right.size + 1;

        return Info(currMin, currMax, currSz);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBSTinBT(Node* root)
{
    Info info = helper(root);
    return info.size; // max BST size
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << largestBSTinBT(root) << endl;

    return 0;
}