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
        ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
        {
            if(head1==NULL || head2==NULL)
            {
                return head1 == NULL ? head2 : head1;
            }
            //case1
            if(head1->val <= head2->val)
            {
                head1->next = mergeTwoLists(head1->next, head2);
                return head1;
            }
            else //case 2
            {
                head2->next = mergeTwoLists(head1, head2->next);
                return head2;
            }
        }
};

int main()
{
    Solution s1;
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode* merge = s1.mergeTwoLists(head1, head2);

    cout << merge->val << "->";
    cout << merge->next->val << "->";
    cout << merge->next->next->val << "->";
    cout << merge->next->next->next->val << "->";
    cout << merge->next->next->next->next->val << "->";
    cout << merge->next->next->next->next->next->val << endl;
}