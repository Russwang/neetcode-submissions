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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;

        while (list1 && list2) {
            head->next = (list1->val < list2->val) ? list1 : list2;
            if (list1->val < list2->val) list1 = list1->next;
            else list2 = list2->next;
            head = head->next;
        }

        if (!list1) head->next = list2;
        else head->next = list1;

        return dummy->next;
    }
};
