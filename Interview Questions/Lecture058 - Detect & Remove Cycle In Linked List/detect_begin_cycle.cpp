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
        ListNode *detectCycle(ListNode *head)
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
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
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
    ListNode* list = s1.detectCycle(head);
    cout << list->val << endl;

    return 0;
}
