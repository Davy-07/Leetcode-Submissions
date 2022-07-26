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
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* temp,*temp2,*prev;
        temp=head;
        temp2=prev=NULL;
        while(temp->next!=NULL)
        {
            temp2=temp;
            temp=temp->next;
            temp2->next = prev;
            prev = temp2;
        }
        head = temp;
        head->next = prev;
        return head;
        
    }
};