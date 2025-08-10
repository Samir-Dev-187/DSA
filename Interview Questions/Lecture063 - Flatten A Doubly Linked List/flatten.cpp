#include<iostream>
using namespace std;

class Node
{
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
};

class Solution
{
    public:
        Node* faltten(Node* head)
        {
            if(head == NULL) return head;

            Node* curr = head;
            while(curr != NULL)
            {
                if(curr->child != NULL)
                {
                    //flatten the child nodes
                    Node* next = curr->next;
                    curr->next = faltten(curr->child);

                    curr->next->prev = curr;
                    curr->child = NULL;

                    //find tail
                    while(curr->next != NULL)
                    {
                        curr = curr->next;
                    }

                    //attach tail with next ptr
                    if(next != NULL)
                    {
                        curr->next = next;
                        next->prev = curr;
                    }
                }
                curr = curr->next;
            }

            return head;
        }
};

int main()
{
    Node* n1 = new Node();
    n1->val = 1;
    Node* n2 = new Node();
    n2->val = 2;
    Node* n3 = new Node();
    n3->val = 3;
    Node* n4 = new Node();
    n4->val = 4;
    Node* n5 = new Node();
    n5->val = 5;

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    // Level 2 (child of 3)
    Node* n6 = new Node();
    n6->val = 6;
    Node* n7 = new Node();
    n7->val = 7;
    Node* n8 = new Node();
    n8->val = 8;

    n6->next = n7;
    n7->prev = n6;
    n7->next = n8;
    n8->prev = n7;

    n3->child = n6;

    // Level 3 (child of 7)
    Node* n9 = new Node();
    n9->val = 9;
    Node* n10 = new Node();
    n10->val = 10;

    n9->next = n10;
    n10->prev = n9;

    n7->child = n9;

    Solution s1;
    Node* flatHead = s1.faltten(n1); // Your original function name

    // Print flattened list 
    Node* temp = flatHead;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}