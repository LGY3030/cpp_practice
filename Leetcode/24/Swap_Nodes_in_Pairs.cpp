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
//Solution 1
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *pos = head->next;
        while(pos!=nullptr){
            if(pre==nullptr){
                cur->next = pos->next;
                pos->next = cur;
                head = pos;
                
            }
            else{
                pre->next = pos;
                cur->next = pos->next;
                pos->next = cur;
            }
            
            ListNode *tmp = cur;
            cur=pos;
            pos=tmp;
            pre=pos;
            if(pos->next==nullptr) break;
            cur=cur->next->next;
            pos=pos->next->next;
        }
        return head;
    }
};

//Solution 2
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* res=head->next;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(true){
            dummy->next=fast;
            slow->next=fast->next;
            fast->next=slow;
            ListNode* temp=slow;
            slow=fast;
            fast=temp;
            if(fast->next==nullptr || fast->next->next==nullptr) break;
            fast=fast->next->next;
            slow=slow->next->next;
            dummy=dummy->next->next;
        }
        return res;
    }
};
