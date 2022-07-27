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
    ListNode* reverseComplete(ListNode* head)
    {
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
    ListNode* reverseLeft(ListNode* head,int left, int right)
    {
        ListNode* cur = head;
			ListNode* lat = head;
			int len = right - left + 1;
			stack<ListNode*> s;	
			while(len--) {
				s.push(cur);
				lat = cur;
				cur = cur->next;
			}
			lat = cur;
			head = cur = s.top();
			s.pop();
			while(!s.empty()) {
				cur->next = s.top();
				cur = s.top();
				s.pop();
			}
			cur->next = lat;
            return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        int size = 0;
        ListNode* len = head;
        while(len!=NULL)
        {
            len=len->next;
            size++;
        }
        if(left==1 && right==size)
        {
            return reverseComplete(head);
        }
        if(left==right)
        {
            return head;
        }
        
        if(left==1)
        {
            return reverseLeft(head,left,right);
        }
        
        ListNode* temp,*left1,*temp1,*temp2,*temp3,*prev;
        temp=head;
        int i=1;
        while(i<left-1)
        {
            temp=temp->next;
            i++;
        }
        temp1=temp;
        left1 =temp->next;
        i++;
        prev=NULL;
        temp2=NULL;
        temp3=left1;
        while(i<=right)
        {
            temp2=temp3;
            temp3 = temp3->next;
            temp2->next = prev;
            prev=temp2;
            i++;
        }
        temp1->next=prev;
        left1->next=temp3;
        
        return head;
        
    }
};