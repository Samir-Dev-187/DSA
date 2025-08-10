#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node* rightMostInLeftSubtree(Node* root)
{
    Node* ans;
    while (root != NULL)
    {
        ans = root;
        root = root->right;
    }
    
    return ans;
}

Node* leftMostInRightSubtree(Node* root)
{
    Node* ans;
    while (root != NULL)
    {
        ans = root;
        root = root->left;
    }
    
    return ans;
}

vector<int> getPredSucc(Node* root, int key)
{
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL)
    {
        if(key < curr->val)
        {
            succ = curr;
            curr = curr->left;
        }
        else if(key > curr->val)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            if(curr->left != NULL)
            {
                // Inorder Pred
                pred = rightMostInLeftSubtree(curr->left);
            }

            if(curr->right != NULL)
            {
                succ = leftMostInRightSubtree(curr->right);
            }

            break;
        }
    }

    return {pred->val, succ->val};
}

int main() 
{
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right= new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 3;
    vector<int> ans = getPredSucc(root, key);
    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;
    

    return 0;
}