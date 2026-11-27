/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* next = head->next;
        ListNode* pre = head;
        head->next = nullptr;
        while (next) {
            ListNode* temp = next->next;
            next->next = pre;
            if (temp == nullptr) return next;
            pre = next;
            next = temp;
        }

        return nullptr;
    }
};
