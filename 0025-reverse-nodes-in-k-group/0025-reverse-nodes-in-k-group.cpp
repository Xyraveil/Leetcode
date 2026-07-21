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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left, *right;
        left = dummy;
        right = head;
        int x = k;
        while(true)
        {
            k = x;
            ListNode* temp1 = right;
            for (int i = 0; i < x; i++)
            {
                if (!temp1)
                    return dummy->next;

                temp1 = temp1->next;
            }
            ListNode* curr = left->next->next;
            ListNode* prev = left->next;

            while(--k)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            left->next->next = curr;
            ListNode* temp = left->next;
            left->next = prev;
            left = temp;
            right = curr;
        }
        return dummy->next;
    }
};