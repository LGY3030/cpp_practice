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
        ListNode* cur=head;
        ListNode* res=nullptr;
        int flag=0;
        while(cur&&cur->next){
            if(cur->val==cur->next->val){
                flag=1;
            }
            else{
                if(flag==0){
                    
                    if(res==nullptr) {   
                        head=cur;
                        res=cur;
                    }
                    else{
                        res->next=cur;
                        res=res->next;
                    }
                }
                flag=0;
            }
            cur=cur->next;
        } 
        if(res==nullptr){
            if(flag==0) return cur;
            else return nullptr;
        }
        else{
            if(flag==0) res->next=cur;
            else res->next=nullptr;
        }
        return head;
    }
};



//Solution 2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* cur=head;
        ListNode* res=nullptr;
        while(cur){
            if(cur->next && cur->val==cur->next->val){
                while(cur->next && cur->val==cur->next->val)
                    cur=cur->next;
            }
            else{
                if(res==nullptr){
                    res=cur;
                    head=res;
                }
                else{
                    res->next=cur;
                    res=cur;
                }
            }
            cur=cur->next;
        }
        if(res) res->next=cur;
        else return cur;
        return head;
    }
};

//Solution 3
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* res=dummy;
        int count=-101;
        while(head->next!=nullptr){
            if(head->val!=count && head->val!=head->next->val){
                dummy->next=head;
                dummy=dummy->next;
            }
            count=head->val;
            head=head->next;
        }
        if(head->val!=count){
            dummy->next=head;
            dummy=dummy->next;
        }
        dummy->next=nullptr;
        return res->next;
    }
};

//Solution 4
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* res=dummy;
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val) head=head->next;
            }
            else{
                dummy->next=head;
                dummy=dummy->next;
            }
            head=head->next;
        }
        dummy->next=nullptr;
        return res->next;
    }
};
