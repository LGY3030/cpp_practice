/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 1, �����L+set 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> uset;
        while(headA!=nullptr){
            uset.insert(headA);
            headA=headA->next;
        }
        while(headB!=nullptr){
            if(uset.find(headB)!=uset.end()) return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};


//Solution 2, ���LheadA+headB�|���bintersection, �Y�S���hnull 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * first = headA;
        ListNode * second = headB;
        while(first!=second){
            first = first? first->next:headB;
            second = second? second->next:headA;
        }
        return first;
    }
};
