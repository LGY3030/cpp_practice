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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur=head;
        ListNode *pre=nullptr;
        while(cur && cur->val==val){
            head=head->next;
            cur=head;
        }
        while(cur){
            if(cur->val==val){
                pre->next=cur->next;
                cur=cur->next;
                continue;
            }
            pre=cur;
            cur=cur->next;
        }
            
        return head;
    }
};


//Solution 2, Concise
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val){
            head=head->next;
        }
        ListNode *cur=head;
        ListNode *pre=nullptr;
        while(cur){
            if(cur->val==val) pre->next=cur->next;
            else pre=cur;
            cur=cur->next;
        }
        return head;
    }
};


//Solution 3
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val){
            head=head->next;
        }
        ListNode *cur=head;
        while(cur && cur->next){
            if(cur->next->val==val) cur->next=cur->next->next;
            else cur=cur->next;
        }
        return head;
    }
};
