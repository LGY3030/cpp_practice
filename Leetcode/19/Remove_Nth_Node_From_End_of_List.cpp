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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        int total=0;
        while(cur!=0){
            total++;
            cur=cur->next;
        }
        if(total==0) return head;
        if(total-n==0){
            cur=head;
            head=head->next;
            delete cur;
        }
        else{
            int target = total-n-1;
            cur=head;
            int count=0;
            while(count!=target){
                cur=cur->next;
                count++;
            }
            ListNode* tmp=cur->next;
            cur->next=tmp->next;
            delete tmp;
        }
        return head;
    }
};

//Solution 2, double pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first=head, *second=head;
        if(head == 0) return head;
        for(int i=0;i<n;i++){
            first=first->next;
        }
        if(first==0){
            ListNode *tmp=head;
            head=head->next;
            delete tmp;
        }
        else{
            while(first->next!=0){
                first=first->next;
                second=second->next;
            }
            ListNode *tmp=second->next;
            second->next=tmp->next;
            delete tmp;
        }
        return head;
    }
};
