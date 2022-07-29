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
        
        if(head==NULL)
        {
            return NULL;
        }
        
        vector<ListNode*> ref;
        ListNode* temp = head;
        ref.push_back(temp);
        ListNode* ans = NULL;
        vector<int>::iterator it;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            if(find(ref.begin(),ref.end(),temp)==ref.end())
            {
                ref.push_back(temp);
            }
            else if(find(ref.begin(),ref.end(),temp)!=ref.end())
            {
                ans=temp;
                break;
            }        
        }
        
        return ans;
        
    }
};