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
 //Solution 1
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> umap;
        ListNode* cur=head;
        int count=0;
        while(cur){
            umap[cur->val]=count;
            count++;
            cur=cur->next;
        }
        vector<int> vec(count);
        for(auto&i:G){
            vec[umap[i]]++;
        }

        int res=0;
        bool flag=false;
        for(auto&i:vec){
            if(i!=0){
                if(!flag){
                    res++;
                    flag=true;
                }
                else continue;
            }
            else{
                if(flag) flag=false;
            }
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
    	// direct vector to set: unordered_set<int> setG (G.begin(), G.end());
        unordered_set<int> uset;
        for(auto&i:G) uset.insert(i);
        int pre=0;
        int res=0;
        while(head){
            if(uset.count(head->val)){
                if(pre==0) res++;
            }
            pre=uset.count(head->val);
            head=head->next;
        }
        return res;
    }
};
