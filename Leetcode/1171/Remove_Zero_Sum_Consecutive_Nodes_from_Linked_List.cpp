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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        unordered_map<int, ListNode*> umap;
        umap[0]=dummy;
        int sum=0;
        while(head){
            sum+=head->val;
            if(umap.find(sum)!=umap.end()){
                ListNode* temp=umap[sum];
                ListNode* tmp=temp->next;
                while(tmp!=head){
                    sum+=tmp->val;
                    umap.erase(sum);
                    tmp=tmp->next;
                }
                sum+=head->val;
                umap[sum]=temp;
                temp->next=head->next;
            }
            else umap[sum]=head;
            head=head->next;
        }
        return dummy->next;
    }
};
