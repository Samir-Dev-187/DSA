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
        ListNode* middleNode(ListNode* head)
        {
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s1;
    ListNode* mid = s1.middleNode(head);
    cout << "Middle node value: " << mid->val <<endl;

    return 0;
}