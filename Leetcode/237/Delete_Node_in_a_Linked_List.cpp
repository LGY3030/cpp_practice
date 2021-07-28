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


//Solution 2, ���@�Ӫ��Ҧ����copy���L , ���ɦ���Ӥ@�˪�node, �R����@��, �]���e�@�Ӧ��O�d�e����next���� 
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
