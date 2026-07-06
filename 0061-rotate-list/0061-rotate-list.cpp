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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* Newhead = head;
        int size =0;
        if (head != nullptr) {
            while (curr != nullptr) {
                curr = curr->next;
                size++;
            }
            if(size<=1) return head;
            curr = head;
            k = size - k%size;
            while (k--) {
                curr = curr->next;
            }
            if(curr == nullptr) return head;
            Newhead = curr;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = head;
            while (curr->next != Newhead) {
                curr = curr->next;
            }
            curr->next = nullptr;
        }
        return Newhead;
    }
};