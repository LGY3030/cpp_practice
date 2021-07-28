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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=b-a+2;
        ListNode*fast=list1;
        ListNode*slow=list1;
        for(int i=0;i<count;i++) fast=fast->next;
        for(int i=0;i<a-1;i++){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=list2;
        while(list2->next) list2=list2->next;
        list2->next=fast;
        return list1;
    }
};

//Solution 2
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        dummy->next=list1;
        ListNode* res=dummy;
        for(int i=0; i<a; i++){
            dummy=dummy->next;
        }
        ListNode* nxt=dummy;
        for(int i=0; i<b-a+2; i++){
            nxt=nxt->next;
        }
        dummy->next=list2;
        while(dummy->next){
            dummy=dummy->next;
        }
        dummy->next=nxt;
        return res->next;
    }
};
