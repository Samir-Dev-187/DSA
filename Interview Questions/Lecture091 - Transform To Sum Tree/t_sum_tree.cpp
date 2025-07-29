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
    root->left = builtTree(preorder); //Left
    root->right = builtTree(preorder); //Right

    return root;
}

void preOrder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int sumTree(Node* root)
{
    if(root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = builtTree(preorder);

    cout << "Before Conversion: ";
    preOrder(root);
    cout << endl;

    sumTree(root);

    cout << "After Conversion: ";
    preOrder(root);
    cout << endl;
    
    return 0;
}