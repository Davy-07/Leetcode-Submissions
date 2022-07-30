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
        
        if(head==NULL || head->next==NULL ||  k<=0)
        {
            return head;
        }
        ListNode* size = head;
        int len =1;
        while(size->next!=NULL)
        {
            size = size->next;
            len++;
        }
        k = k%len;
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* rotate = NULL;
        while(k!=0)
        {
            
            if(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            else if(temp->next==NULL)
            {
                prev->next=NULL;
                rotate = temp;
                rotate->next = head;
                head = rotate;
                temp = head;
                prev=NULL;
                k--;
            }
            
        }
        return head;
    }
};