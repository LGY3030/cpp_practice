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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr) return head;
        ListNode*root=head;
        ListNode*roots=head->next;
        ListNode*first=head;
        ListNode*second=head->next;
        while(second->next!=nullptr&&second->next->next!=nullptr){
            first->next=first->next->next;
            second->next=second->next->next;
            first=first->next;
            second=second->next;
        }
        if(second->next){
            first->next=first->next->next;
            first=first->next;
        }
        second->next=nullptr;
        first->next=roots;
        return root;
    }
};


//Solution 2, Concise version
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode*first=head;
        ListNode*second=head->next;
        ListNode*sec=second;
        while(second!=nullptr&&second->next!=nullptr){
            first->next=first->next->next;
            second->next=second->next->next;
            first=first->next;
            second=second->next;
        }
        first->next=sec;
        return head;
    }
};

//Solution 3
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* odd=new ListNode(0);
        ListNode* resodd=odd;
        ListNode* even=new ListNode(0);
        ListNode* reseven=even;
        bool count=true;
        while(head){
            if(count){
                odd->next=head;
                odd=odd->next;
                count=false;
            }
            else{
                even->next=head;
                even=even->next;
                count=true;
            }
            head=head->next;
        }
        odd->next=reseven->next;
        even->next=nullptr;
        return resodd->next;
    }
};
