#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution 
{
    public:
        Node* connect(Node* root) 
        {
            if(root == NULL || root->left == NULL)
            {
                return root;
            }

            queue<Node*> q;
            q.push(root);
            q.push(NULL); //mark the end of the level

            Node* prev = NULL;

            while (q.size() > 0)
            {
                Node* curr = q.front();
                q.pop();

                if(curr == NULL)
                {
                    if(q.size() == 0)
                    {
                        break;
                    }
                    q.push(NULL);
                }
                else
                {
                    if(curr->left != NULL)
                    {
                        q.push(curr->left);
                    }

                    if(curr->right != NULL)
                    {
                        q.push(curr->right);
                    }

                    if(prev != NULL)
                    {
                        prev->next = curr;
                    }
                }
                prev = curr;
            }

            return root;            
        }

        void printLevelOrderWithNext(Node* root)
        {
            Node* level_start = root;
            while (level_start)
            {
                Node* curr = level_start;
                level_start = NULL;

                // Traverse current level and print
                while (curr)
                {
                    cout << curr->val << ",";

                    // Prepare next level's starting node
                    if (!level_start)
                    {
                        if (curr->left) level_start = curr->left;
                        else if (curr->right) level_start = curr->right;
                    }

                    curr = curr->next;
                }

                cout << "#,";
            }
        }
};

int main()
{
    Solution s1;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    s1.connect(root);
    s1.printLevelOrderWithNext(root);

    return 0;
}