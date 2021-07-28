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
    int getDecimalValue(ListNode* head) {
        stack<int> sta;
        ListNode* cur=head;
        while(cur){
            sta.push(cur->val);
            cur=cur->next;
        }
        int res=0;
        int count=0;
        while(sta.size()){
            res+=sta.top()*pow(2, count);
            sta.pop();
            count++;
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res=0;
        while(head){
            res<<=1;
            res|=head->val;
            head=head->next;
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        queue<int> que;
        while(head){
            que.push(head->val);
            head=head->next;
        }
        int res=0;
        while(!que.empty()){
            int temp=que.front()<<(que.size()-1);
            res|=temp;
            que.pop();
        }
        return res;
    }
};
