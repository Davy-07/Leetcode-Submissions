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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* dummyHead=dummy;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                dummy->next=temp1;
                temp1=temp1->next;
            }
            else if(temp1->val>temp2->val)
            {
                dummy->next=temp2;
                temp2=temp2->next;
            }
            dummy=dummy->next;
        }
        while(temp1!=NULL)
        {
            dummy->next=temp1;
            temp1=temp1->next;
            dummy=dummy->next;
        }
        while(temp2!=NULL)
        {
            dummy->next=temp2;
            temp2=temp2->next;
            dummy=dummy->next;
        }
        return(dummyHead->next);
    }
};