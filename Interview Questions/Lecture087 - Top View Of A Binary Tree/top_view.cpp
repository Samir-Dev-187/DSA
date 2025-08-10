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

void TopView(Node* root)
{
    queue<pair<Node*, int>> q;
    map<int, int> m;

    q.push({root, 0});

    while (q.size() > 0)
    {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end())
        {
            m[currHD] = curr->data;
        }

        if(curr->left != NULL)
        {
            q.push({curr->left, currHD-1});
        }

        if(curr->right != NULL)
        {
            q.push({curr->right, currHD+1});
        }
    }

    for(auto it : m)
    {
        cout << it.second << " ";
    }
    cout << endl;

}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = builtTree(preorder);

    TopView(root);
    
    return 0;
}