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
            
        
        int size=0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            size++;
            temp = temp->next;
        }
        temp = head;
        ListNode* temp2;
        if(size!=n)
        {
            for(int i=0;i<size-n-1;i++)
            {
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = temp2->next;
        }
        else{
            head=head->next;
        }
        return head;        
    }
};