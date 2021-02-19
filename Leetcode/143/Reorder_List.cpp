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
    void reorderList(ListNode* head) {
        if(head==nullptr) return ;
        ListNode* cur=head;
        vector<ListNode*> vec;
        while(cur){
            vec.push_back(cur);
            cur=cur->next;
        }
        cur=head;
        for(int i=1;i<vec.size();i++){
            if(i%2==1) cur->next=vec[vec.size()-(i+1)/2];
            else cur->next=vec[i/2];
            cur=cur->next;
        }
        cur->next=nullptr;
    }
};


//Solution 2
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return ;
        ListNode* fast=head;
        ListNode* slow=head->next;
        while(slow && slow->next){
            fast=fast->next;
            slow=slow->next->next;
        }
        slow=fast->next;
        fast->next=nullptr;
        fast=head->next;
        
        //reverse slow
        ListNode *pre, *cur, *nt;
        pre=nullptr;
        cur=slow;
        nt=slow->next;
        while(nt){
            cur->next=pre;
            pre=cur;
            cur=nt;
            nt=nt->next;
        }
        cur->next=pre;
        slow=cur;
        
        head->next=slow;
        slow=slow->next;
        head=head->next;
        while(slow){
            head->next=fast;
            fast=fast->next;
            head=head->next;
            head->next=slow;
            slow=slow->next;
            head=head->next;
        }
        if(fast!=nullptr) head->next=fast;
        
    }
};


//Solution 3
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return ;
        ListNode* first=head;
        ListNode* second=head->next;
        while(second && second->next){
            first=first->next;
            second=second->next->next;
        }
        second=first->next;
        first->next=nullptr;
        
        //reverse second
        ListNode *pre=nullptr;
        while(second){
            ListNode *post=second->next;
            second->next=pre;
            pre=second;
            second=post;
        }
        
        first=head;
        second=pre;
        while(second){
            ListNode*tmp=first->next;
            first->next=second;
            second=second->next;
            first->next->next=tmp;
            first=tmp;
        }
    }
};
