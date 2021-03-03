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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode * left=nullptr;
        ListNode * right=nullptr;
        ListNode * rleft=nullptr;
        ListNode * rright=nullptr;
        ListNode * tmp=head;
        while(tmp){
            if(tmp->val<x){
                if(left==nullptr){
                    left=tmp;
                    rleft=left;
                }
                else{
                    left->next=tmp;
                    left=left->next;
                }
            }
            else{
                if(right==nullptr){
                    right=tmp;
                    rright=right;
                }
                else{
                    right->next=tmp;
                    right=right->next;
                }
            }
            tmp=tmp->next;
        }
        if(rleft==nullptr){
            right->next=nullptr;
            return rright;
        }
        if(rright==nullptr){
            left->next=nullptr;
            return rleft;
        }
        left->next=rright;
        right->next=nullptr;
        return rleft;
    }
};


//Solution 2
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode n1(0);
        ListNode n2(0);
        ListNode* left = &n1;
        ListNode* right = &n2;
        while(head){
            if(head->val<x){
                left->next=head;
                left=left->next;
            }
            else{
                right->next=head;
                right=right->next;
            }
            head=head->next;
        }
        right->next=nullptr;
        left->next=n2.next;
        return n1.next;
    }
};
