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
