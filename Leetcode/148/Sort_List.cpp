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
 //Solution 1, Time exceeded, O(n^2)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* newL = nullptr;
        ListNode* res = nullptr;
        while(head!=nullptr){
            ListNode* cur=head;
            ListNode* pre=nullptr;
            ListNode* rec=head;
            ListNode* rec_pre=nullptr;
            int min=rec->val;
            while(cur!=nullptr){
                if(cur->val<min){
                    rec=cur;
                    rec_pre=pre;
                    min=rec->val;
                }
                if(cur==head){
                    pre=head;
                }
                else{
                    pre=pre->next;
                }
                cur=cur->next;
            }
            if(rec==head) head=rec->next;
            else{
                rec_pre->next=rec->next;
            }
            if(newL==nullptr){
                newL=rec;
                res=newL;
            }
            else{
                newL->next=rec;
                newL=newL->next;
            }
        }
        return res;
    }
};


//Solution 2, merge sort
class Solution {
public:
    ListNode* merge(ListNode* f, ListNode* s){
        ListNode* newL=nullptr;
        ListNode* root=nullptr;
        ListNode* cur;
        while(f!=nullptr&&s!=nullptr){
            if(f->val < s->val){
                cur=f;
                f=f->next;
            }
            else{
                cur=s;
                s=s->next;
            }
            if(newL==nullptr){
                newL=cur;
                root=newL;
            }
            else{
                newL->next=cur;
                newL=newL->next;
            }
        }
        if(f!=nullptr) newL->next=f;
        else newL->next=s;
        return root;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* first=head->next;
        ListNode* second=head;
        while(first!=nullptr && first->next!=nullptr){
            first=first->next->next;
            second=second->next;
        }
        first=second->next;
        second->next=nullptr;
        return merge(sortList(head), sortList(first));
        
    }
};
