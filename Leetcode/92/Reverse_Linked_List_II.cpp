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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right-left==0) return head;
        ListNode* dum=new ListNode(0);
        dum->next=head;
        ListNode* slow=dum;
        for(int i=0;i<left-1;i++){
            slow=slow->next;
        }
        
        ListNode* fast=slow->next;
        for(int i=0;i<right-left;i++){
            ListNode* tmp=fast->next;
            fast->next=fast->next->next;
            tmp->next=slow->next;
            slow->next=tmp;
        }
        return dum->next;
    }
};
