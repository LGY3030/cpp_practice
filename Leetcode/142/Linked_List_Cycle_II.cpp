/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 1, use unordered_set
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        unordered_set<ListNode*> uset;
        while(head->next!=nullptr){
            if(uset.find(head)!=uset.end()) return head;
            uset.insert(head);
            head=head->next;
        }
        return nullptr;
        
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 2, slow and fast pointers
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
