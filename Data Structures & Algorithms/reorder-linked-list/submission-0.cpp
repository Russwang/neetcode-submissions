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
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;

        ListNode* dummy = head;

        while (head->next) {
            dq.push_back(head->next);
            head = head->next;
        }

        head = dummy;
        while (dq.size()) {
            head->next = dq.back();
            dq.pop_back();
            head = head->next;
            if (dq.size()) {
                head->next = dq.front();
                dq.pop_front();
                head = head->next;
            }
        }
        head->next = nullptr;
        head = dummy;

    }
};
