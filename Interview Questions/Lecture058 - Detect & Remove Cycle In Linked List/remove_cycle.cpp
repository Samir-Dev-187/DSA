#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
    public:
        ListNode *removeCycle(ListNode *head)
        {
            ListNode* slow = head;
            ListNode* fast = head;
            bool isCycle = false;

            while(fast!=NULL && fast->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(slow ==  fast)
                {
                    isCycle = true;
                    break;
                }
            }

            if(!isCycle)
            {
                return NULL;
            }
            else
            {
                slow = head;
                ListNode* prev = NULL;
                while(slow!=fast)
                {
                    slow = slow->next;
                    prev = fast;
                    fast = fast->next;
                }
                prev->next = NULL; //remove cycle
            }
        }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;

    Solution s1;
    s1.removeCycle(head);

    cout << head->val << "->";
    cout << head->next->val << "->";
    cout << head->next->next->val << "->";
    cout << head->next->next->next->val << "->";
    cout << head->next->next->next->next->val << "->";
    cout << head->next->next->next->next->next->val <<endl;

    return 0;
}
