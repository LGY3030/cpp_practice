/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 1
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next!=nullptr){
            node->val=node->next->val;
            node=node->next;
        }
        node->val=node->next->val;
        ListNode* tmp=node->next;
        node->next=nullptr;
        delete tmp;
    }
};


//Solution 2, 把後一個的所有資料copy給他 , 此時有兩個一樣的node, 刪掉後一個, 因為前一個有保留前面的next指標 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*tmp=node->next;
        *node=*tmp;
        delete tmp;
    }
};

//Solution 3
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode* tmp=node->next;
        node->next=tmp->next;
        delete tmp;
    }
};
