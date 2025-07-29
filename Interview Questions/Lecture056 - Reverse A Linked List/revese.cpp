#include<iostream>
using namespace std;

// ✅ Define ListNode before using it
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// ✅ Then use it inside your Solution class
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    // Create a simple list: 1 -> 2 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol;
    ListNode* prev = sol.reverseList(head);

    // Just print the head of reversed list (which is prev)
    cout << "Value at prev (new head of reversed list): " << prev->val << endl;

    return 0;
}
    