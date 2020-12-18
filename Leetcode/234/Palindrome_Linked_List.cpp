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
