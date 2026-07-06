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
    ListNode* reverse(ListNode*curr, ListNode * prev = nullptr)
    {
        if(curr==nullptr) return prev;
        ListNode* temp = curr->next;
        curr->next= prev;
        return reverse(temp,curr);
    }   


    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* start = head, *end = reverse(slow,nullptr);
        bool ans = true;
        while( end)
        {
            if(start->val == end->val) 
            {
                start = start->next;
                end = end->next;
            }
            else 
            {
                ans = false;
                break;
            }
        }
        return ans;
    }
};