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
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	        int carry = 0;
	        int flag = 0;
	        ListNode * head = NULL;
	        ListNode * first = NULL;
	        while(l1 != NULL && l2 != NULL){
	            ListNode * tmp = new ListNode;
	            tmp->val = (l1->val + l2->val + carry)%10;
	            carry = (l1->val + l2->val + carry)/10;
	            tmp->next = NULL;
	            if(flag == 0){
	                head = tmp;
	                first = tmp;
	                flag++;
	            }
	            else{
	                first->next = tmp;
	                first = tmp;
	            }
	            l1 = l1->next;
	            l2 = l2->next;
	        }
	        while(l1 != NULL){
	            ListNode * tmp = new ListNode;
	            tmp->val = (l1->val + carry)%10;
	            carry = (l1->val + carry)/10;
	            tmp->next = NULL;
	            first->next = tmp;
	            first = tmp;
	            l1 = l1->next;
	        }
	        while(l2 != NULL){
	            ListNode * tmp = new ListNode;
	            tmp->val = (l2->val + carry)%10;
	            carry = (l2->val + carry)/10;
	            tmp->next = NULL;
	            first->next = tmp;
	            first = tmp;
	            l2 = l2->next;
	        }
	        if(carry == 1){
	            ListNode * tmp = new ListNode;
	            tmp->val = 1;
	            tmp->next = NULL;
	            first->next = tmp;
	            first = tmp;
	        }
	        return head;
	    }
};
