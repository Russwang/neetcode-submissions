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

        stack<ListNode*> st;

        while (head) {
            st.push(head);
            head = head->next;
        }

        ListNode* dummy = new ListNode();
        head = dummy;

        while (st.size()) {
            head->next = st.top();
            st.pop();
            head = head->next;
        }
        head->next = nullptr;

        return dummy->next;
    }
};
