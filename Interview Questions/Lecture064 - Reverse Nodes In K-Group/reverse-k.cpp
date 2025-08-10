#include<iostream>
using namespace std;

class Listnode
{
    public: 
        int val;
        Listnode* next;
        Listnode* prev;
};

class Solution
{
    public:
        Listnode* reverseKGroup(Listnode* head, int k)
        {
            Listnode* temp = head;
            int cnt = 0;
            //check if k nodes exist
            while(cnt < k)
            {
                if(temp == NULL)
                {
                    return head;
                }
                temp = temp->next;
                cnt++;
            }

            //recursively call for rest of LL
            Listnode* prevNode = reverseKGroup(temp, k);

            //reverse current group
            temp = head;
            cnt = 0;
            while(cnt < k)
            {
                Listnode* next = temp->next;
                temp->next = prevNode;

                prevNode = temp;
                temp = next;

                cnt++;
            }
            return prevNode;
        }
};

int main()
{
    Listnode* n1 = new Listnode();
    n1->val = 1;
    Listnode* n2 = new Listnode();
    n2->val = 2; // ← this line was n1->val = 2
    Listnode* n3 = new Listnode();
    n3->val = 3;
    Listnode* n4 = new Listnode();
    n4->val = 4;
    Listnode* n5 = new Listnode();
    n5->val = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    int k = 2;
    Solution s1;
    Listnode* revNode = s1.reverseKGroup(n1, k);

    // Printing reversed list
    Listnode* temp = revNode;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}