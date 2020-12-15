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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==nullptr || head->next==nullptr) return head;
        ListNode *first=head;
        ListNode *second=head;
        int count = 0;
        while(first!=nullptr){
            count++;
            first=first->next;
        }
        first=head;
        k%=count;
        for(int i=0;i<k;i++){
            first=first->next;
        }
        if(first==nullptr) return head;
        while(first->next!=nullptr){
            first=first->next;
            second=second->next;
        }
        first->next = head;
        head = second->next;
        second->next = nullptr;
        return head;
    }
};


//Solution 2, Àôª¬
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *cur=head;
        ListNode *pre=head;
        int size=1;
        while(cur->next!=nullptr){
            size++;
            cur=cur->next;
        }
        cur->next = head;
        k%=size;
        for(int i=0;i<size-k-1;i++){
            pre=pre->next;
        }
        head=pre->next;
        pre->next=nullptr;
        return head;
    }
   
}; 
