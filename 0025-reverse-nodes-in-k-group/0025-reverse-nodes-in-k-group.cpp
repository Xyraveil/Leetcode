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
    void reverseK(ListNode*Head,int k,ListNode* prevTail )
    {
        int x = k;
        if(!Head) 
        {
            prevTail->next = nullptr;
            return;
        }
        ListNode* curr = Head->next; 
        ListNode* prev= Head; 

        while(--k && curr)
        {
            curr=curr->next;
            continue;
        }
        if(k>0) 
        {
            prevTail->next = Head;
            return;
        }
        k=x;
        curr = Head->next;
        while(--k && curr)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        prevTail->next = prev;
        return reverseK(curr,x,Head);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        reverseK(head,k,dummy);
        return dummy->next;
    }
};