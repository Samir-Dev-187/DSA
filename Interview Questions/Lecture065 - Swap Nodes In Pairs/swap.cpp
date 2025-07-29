#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
    public:
        ListNode* swapPairs(ListNode* head)
        {
            if(head == NULL || head->next == NULL)
            {
                return head;
            }

            ListNode* first = head;
            ListNode* sec = head->next;
            ListNode* prev = NULL;

            while (first != NULL && sec != NULL)
            {
                ListNode* third = sec->next;

                sec->next = first;
                first->next = third;

                if(prev != NULL)
                {
                    prev->next = sec;
                }
                else
                {
                    head = sec;
                }

                //update
                prev = first;
                first = third;
                if(third != NULL)
                {
                    sec = third->next;
                }
                else
                {
                    sec = NULL;
                }
            }
           
            return head;
        }
};

int main()
{
    ListNode*  head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s1;
    head = s1.swapPairs(head);

    ListNode* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    
    return 0;
}