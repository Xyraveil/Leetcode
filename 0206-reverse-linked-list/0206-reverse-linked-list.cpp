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
//////////////////////////////////////////////////////// Iterative Answer:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr;
    //     while(head!=nullptr)
    //     {
    //         ListNode* temp ;
    //         temp = head->next;
    //         head->next = prev;
    //         prev = head;
    //         head = temp;
    //     }
    //     return prev;
    // }
//////////////////////////////////////////////////////// recursive Answer:R
    ListNode* reverseList(ListNode* head,ListNode* prev = nullptr) {
        if(head == nullptr)
        {
            return prev;
        }
        ListNode* temp = head->next;
        head->next = prev;
        return reverseList(temp,head);
    }
};