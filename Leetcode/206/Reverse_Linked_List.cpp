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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* pre=nullptr;
        ListNode* cur=head;
        ListNode* pos=cur->next;
        while(pos!=nullptr){
            cur->next=pre;
            pre=cur;
            cur=pos;
            pos=pos->next;
        }
        cur->next=pre;
        return cur;
    }
};

//Solution 2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* pre=nullptr;
        ListNode* cur=head;
        while(cur){
            ListNode* pos=cur->next;
            cur->next=pre;
            pre=cur;
            cur=pos;
        }
        return pre;
    }
};
