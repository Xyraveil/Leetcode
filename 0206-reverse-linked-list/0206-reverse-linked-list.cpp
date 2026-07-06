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
        ListNode* left = head;
        ListNode* right = head;
        if (head != nullptr) {
            while (right->next != nullptr) {
                ListNode* del = nullptr;
                if (right != head) {
                    del = right;
                }
                right = right->next;
                ListNode* temp = new ListNode(right->val, left);
                left = temp;
                delete del;
            }
            head->next = nullptr;
            head = left;
        }
        else
        {

        }
        return head;
    }
};