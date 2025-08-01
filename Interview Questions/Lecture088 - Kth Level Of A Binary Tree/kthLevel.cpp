#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
    root->left = builtTree(preorder); //Left
    root->right = builtTree(preorder); //Right

    return root;
}

void kthLevel(Node* root, int k)
{
    if(root == NULL) return;

    if(k == 1)
    {
        cout << root->data << " "; 
        return;
    }

    kthLevel(root->left, k-1);
    kthLevel(root->right, k-1);
}

int main()
{
    vector<int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = builtTree(preorder);

    kthLevel(root, 2);

    return 0;
}
