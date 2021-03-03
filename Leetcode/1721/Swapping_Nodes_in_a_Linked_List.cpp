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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* current;
        for(int i=1;i<k;i++){
            fast=fast->next;
        }
        current=fast;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        int tmp=current->val;
        current->val=slow->val;
        slow->val=tmp;
        return head;
    }
};
