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
 //Solution 1, bad time complexity
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vec;
        while(head!=nullptr){
            ListNode* cur=head;
            int curnum=cur->val;
            int tmp=0;
            while(cur->next!=nullptr){
                if(cur->next->val>curnum){
                    tmp=cur->next->val;
                    break;
                }
                cur=cur->next;
            }
            vec.push_back(tmp);
            head=head->next;
        }
        return vec;
    }
};


//Solution 2, bad complexity
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vec;
        vector<int> res;
        while(head){
            vec.push_back(head->val);
            res.push_back(0);
            if(vec.size()>=2 && head->val>vec[vec.size()-2]){
                for(int i=vec.size()-2;i>=0;i--){
                    if(res[i]!=0) continue;
                    if(vec[i] >= head->val) continue;
                    res[i]=head->val;
                }
            }
            head=head->next;
        }
        return res;
    }
};


//Solution 3
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode*tmp=head;
        vector<int> record;
        while(tmp){
            record.push_back(tmp->val);
            tmp=tmp->next;
        }
        vector<int> res(record.size());
        stack<int> sta;
        for(int i=record.size()-1; i>=0; i--){
            if(sta.empty()){
                res[i]=0;
                sta.push(record[i]);
            }
            else{
                while(!sta.empty()){
                    if(sta.top()<=record[i]) sta.pop();
                    else{
                        res[i]=sta.top();
                        sta.push(record[i]);
                        break;
                    }
                }
                if(sta.empty()){
                    res[i]=0;
                    sta.push(record[i]);
                }
            }
        }
        return res;
    }
};


//Solution 4
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> res;
        stack<int> sta;
        
        while(head){
            res.push_back(head->val);
            head=head->next;
        }
        
        for(int i=res.size()-1; i>=0; i--){
            if(sta.empty()){
                sta.push(res[i]);
                res[i]=0;
            }
            else{
                while(!sta.empty()){
                    if(sta.top()<=res[i]) sta.pop();
                    else{
                        int tmp=sta.top();
                        sta.push(res[i]);
                        res[i]=tmp;
                        break;
                    }
                }
                if(sta.empty()){
                    sta.push(res[i]);
                    res[i]=0;
                }
            }
        }
        return res;
    }
};

//Solution 5
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int size=0;
        ListNode* cur=head;
        while(cur){
            size++;
            cur=cur->next;
        }
        vector<int> res(size);
        
        cur=head;
        stack<pair<int, int>> sta;
        int idx=-1;
        while(cur){
            idx++;
            while(!sta.empty() && cur->val>sta.top().first){
                res[sta.top().second]=cur->val;
                sta.pop();
            }
            sta.push({cur->val, idx});
            cur=cur->next;
        }
        
        
        return res;
    }
};
