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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int count=0;
        for(auto&i:lists){
            if(i){
                lists[count]=i;
                count++;
            }
        }
        if(count==0) return nullptr;
        lists.erase(lists.begin()+count, lists.end());
        ListNode* dummy=new ListNode(0);
        ListNode* res=dummy;
        while(lists.size()>0){
            int idx=0;
            int minidx=lists[0]->val;
            for(int i=0; i<lists.size(); i++){
                if(lists[i]->val<minidx){
                    idx=i;
                    minidx=lists[i]->val;
                }
            }
            dummy->next=lists[idx];
            dummy=dummy->next;
            lists[idx]=lists[idx]->next;
            if(lists[idx]==nullptr) lists.erase(lists.begin()+idx);
        }
        dummy->next=nullptr;
        return res->next;
    }
};
