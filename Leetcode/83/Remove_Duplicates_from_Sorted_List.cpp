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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* cur = head->next;
        ListNode* pre = head;
        while(cur!=nullptr){
            if(pre->val==cur->val){
                pre->next=cur->next;
                delete cur;
                cur=pre->next;
            }
            else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};


//Solution 2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur&&cur->next){       
            if(cur->val!=cur->next->val){
                cur=cur->next;
            }
            else{
                //ListNode* tmp = cur->next;
                cur->next=cur->next->next;
                //delete tmp;
            }
        }
        return head;
    }
};

//Solution 3
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* dummy=new ListNode(0);
        ListNode* res=dummy;
        while(head){
            while(head->next && head->val==head->next->val) head=head->next;
            dummy->next=head;
            dummy=dummy->next;
            head=head->next;
        }
        dummy->next=nullptr;
        return res->next;
    }
};
