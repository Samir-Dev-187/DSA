#include<iostream>
#include<unordered_map>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr) {}
};


class Solution
{
    public:
        Node* copyRandomList(Node* head)
        {
            if(head == NULL)
            {
                return NULL;
            }
            unordered_map<Node*, Node*> m;

            Node* newHead = new Node(head->val);
            Node* oldTemp = head->next;
            Node* newTemp = newHead;
            m[head] = newHead;

            while (oldTemp != NULL)
            {
                Node* copyNode = new Node(oldTemp->val);
                m[oldTemp] = copyNode;
                newTemp->next = copyNode;

                oldTemp = oldTemp->next;
                newTemp = newTemp->next;
            }
            
            oldTemp = head; newTemp = newHead;
            while (oldTemp != NULL)
            {
                newTemp->random = m[oldTemp->random];
                oldTemp = oldTemp->next;
                newTemp = newTemp->next;
            }
            
            return newHead;
        }
};

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;

    // Set random pointers:
    node1->random = node3; // 1's random points to 3
    node2->random = node1; // 2's random points to 1
    node3->random = node2; // 3's random points to 2

    // Call the solution
    Solution sol;
    Node* copiedHead = sol.copyRandomList(node1);

    // Print the copied list for verification
    Node* temp = copiedHead;
    while (temp != nullptr) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val << endl;
        else
            cout << ", Random: NULL" << endl;
        temp = temp->next;
    }

    return 0;    
}