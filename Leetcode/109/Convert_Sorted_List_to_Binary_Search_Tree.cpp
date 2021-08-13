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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return new TreeNode(head->val);
        ListNode* dummy=new ListNode(0);
        ListNode* start=dummy;
        dummy->next=head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            dummy=dummy->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        dummy->next=nullptr;
        root->left=sortedListToBST(start->next);
        root->right=sortedListToBST(slow->next);
        return root;
    }
};
