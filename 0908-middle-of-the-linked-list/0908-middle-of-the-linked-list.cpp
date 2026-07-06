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
    ListNode* middleNode(ListNode* head) {
        /////////////////////////////////////// Iterative answer:
        // ListNode* curr = head;
        // int size = 0;
        // while(curr!= nullptr)
        // {
        //     curr = curr->next;
        //     size++;
        // }
        // size = size/2 +1;
        // curr = head;
        // int i = 1;
        // while(i!=size)
        // {
        //     curr = curr->next;
        //     i++;
        // }
        // return curr;
        ////////////////////////////////////////// using SlowFast pointers:
        ListNode* slow = head, * fast = head;
        bool b = false;
        while(fast!=nullptr)
        {
            if(b) slow = slow->next;
            b =!b;
            fast = fast->next;
        }
        return slow;
    }
};