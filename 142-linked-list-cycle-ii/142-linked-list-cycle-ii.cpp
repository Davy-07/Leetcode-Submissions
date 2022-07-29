/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* start = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(start!=slow)
                {
                    slow=slow->next;
                    start=start->next;
                }
                return start;
            }
        }
        return NULL;
        
    }
};