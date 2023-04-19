/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 1, hash table
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> uset;
        if(head==nullptr) return false;
        while(head!=nullptr){
            if(uset.find(head)!=uset.end()) return true;
            uset.insert(head);
            head=head->next;
        }
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> uset;
        while(head){
            if(uset.count(head)){
                return true;
            }
            uset.insert(head);
            head = head->next;
        }
        return false;
    }
};


//Solution 3, double pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return false;
        ListNode *first=head, *second=head;
        while(first!=nullptr && first->next!=nullptr){
            first=first->next->next;
            second=second->next;
            if(first==second) return true;
        }
        return false;
    }
};
