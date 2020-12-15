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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=nullptr;
        ListNode *cur=nullptr;
        ListNode *first=l1;
        ListNode *second=l2;
        int firstval=0;
        int secondval=0;
        while(first!=nullptr || second!=nullptr){
            firstval=200;
            secondval=200;
            if(first) firstval=first->val;
            if(second) secondval=second->val;
            
            ListNode *tmp = new ListNode;
            
            if(firstval<secondval){
                tmp->val=firstval; 
                first=first->next;
            }
            else{
                tmp->val=secondval; 
                second=second->next;
            }
            tmp->next=nullptr;
            if(head==nullptr){
                head = tmp;
                cur = head;
            }
            else{
                cur->next = tmp;
                cur = cur->next;
            }
            
           
        }
        return head;
    }
};

 //Solution 2
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode *head=nullptr;
        ListNode *tmp=nullptr;
        while(l1!=nullptr || l2!=nullptr){
            int f = 200;
            int s = 200;
            if(l1!=nullptr) f = l1->val;
            if(l2!=nullptr) s = l2->val;
            if(f<s){
                if(head==nullptr){
                    head=l1;
                    tmp=head;
                    l1=l1->next;
                }
                else{
                    tmp->next=l1;
                    tmp=tmp->next;
                    l1=l1->next;
                }
            }
            else{
                if(head==nullptr){
                    head=l2;
                    tmp=head;
                    l2=l2->next;
                }
                else{
                    tmp->next=l2;
                    tmp=tmp->next;
                    l2=l2->next;
                }
            }
        }
        return head;
    }
};
