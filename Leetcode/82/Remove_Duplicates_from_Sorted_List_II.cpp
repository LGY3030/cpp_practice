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
