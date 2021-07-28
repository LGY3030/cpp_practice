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
    bool isPalindrome(ListNode* head) {
        stack<int> sta;
        if(head==nullptr||head->next==nullptr) return true;
        ListNode*first=head->next;
        ListNode*second=head;
        while(first!=nullptr&&first->next!=nullptr){
            sta.push(second->val);
            first=first->next->next;
            second=second->next;
        }
        
        if(first!=nullptr){
            sta.push(second->val);
        }
        second=second->next;
        
        while(second!=nullptr){
            if(second->val!=sta.top()) return false;
            sta.pop();
            second=second->next;
        }
        return true;
    }
};

//Solution 2
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow->next;
        
        ListNode* pre=nullptr;
        ListNode* cur=fast;
        while(cur){
            ListNode* pos=cur->next;
            cur->next=pre;
            pre=cur;
            cur=pos;
        }
        fast=pre;
        
        slow->next=nullptr;
        slow=head;
        while(fast){
            if(fast->val!=slow->val) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};
