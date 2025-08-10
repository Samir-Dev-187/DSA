#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left = right = NULL;
        }
};

static int idx = -1;
Node* builtTree(vector<int> preorder)
{
    idx++;

    if(preorder[idx] == -1)
    {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = builtTree(preorder); //LEFT
    root->right = builtTree(preorder); //RIGHT

    return root;
};

int count(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = builtTree(preorder);

    cout << "Count : " << count(root) << endl;
    
    return 0;
}