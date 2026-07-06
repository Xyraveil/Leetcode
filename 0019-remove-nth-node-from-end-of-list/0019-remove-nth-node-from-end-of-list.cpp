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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while(curr)
        {
            curr = curr->next;
            size++;
        }
        int steps = size -n;
        if(steps ==0)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        curr = head;
        steps--;
        while(steps--)
        {
            curr=curr->next;
        }
        ListNode* temp = curr->next;
        curr-> next = curr->next->next;
        delete temp;
        return head;
    }
};