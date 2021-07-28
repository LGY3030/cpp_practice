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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> forl1;
        stack<int> forl2;
        ListNode* one=l1;
        ListNode* two=l2;
        int flag=0;
        while(one && two){
            forl1.push(one->val);
            forl2.push(two->val);
            one=one->next;
            two=two->next;
        }
        while(one){
            forl1.push(one->val);
            one=one->next;
        }
        while(two){
            forl2.push(two->val);
            two=two->next;
        }
        
        stack<int> sum;
        int carry=0;
        while(forl1.size()>0 && forl2.size()>0){
            int get=forl1.top()+forl2.top()+carry;
            if(get>=10){
                get=get%10;
                carry=1;
            }
            else carry=0;
            forl1.pop();
            forl2.pop();
            sum.push(get);
        }
        while(forl1.size()>0){
            int get=forl1.top()+carry;
            if(get>=10){
                get=get%10;
                carry=1;
            }
            else carry=0;
            forl1.pop();
            sum.push(get);
        }
        while(forl2.size()>0){
            int get=forl2.top()+carry;
            if(get>=10){
                get=get%10;
                carry=1;
            }
            else carry=0;
            sum.push(get);
            forl2.pop();
            flag=1;
        }
        if(flag==1){
            ListNode*tmp=l1;
            l1=l2;
            l2=tmp;
        }
        ListNode* cur=l1;
        while(cur){
            cur->val=sum.top();
            cur=cur->next;
            sum.pop();
        }
        
        if(carry==1){
            ListNode* add=new ListNode(1);
            add->next=l1;
            l1=add;
        }
        return l1;
    }
};


//Solution 2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vec1;
        vector<int> vec2;
        while(l1){
            vec1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            vec2.push_back(l2->val);
            l2=l2->next;
        }
        int sum=0;
        int carry=0;
        ListNode* head=nullptr;
        for(int i=vec1.size()-1, j=vec2.size()-1; i>=0 || j>=0 || carry==1; i--, j--){
            sum=carry;
            if(i>=0) sum+=vec1[i];
            if(j>=0) sum+=vec2[j];
            if(sum>=10) carry=1;
            else carry=0;
            ListNode * p=new ListNode(sum%10);
            p->next=head;
            head=p;
        }
        return head;
    }
};

//Solution 3
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp=new ListNode(0);
        ListNode* res=tmp;
        stack<int> sta;
        stack<int> for1;
        stack<int> for2;
        while(l1){
            for1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            for2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        while(!for1.empty() || !for2.empty() || carry){
            int count=carry;
            if(!for1.empty()){
                count+=for1.top();
                for1.pop();
            }
            if(!for2.empty()){
                count+=for2.top();
                for2.pop();
            }
            sta.push(count%10);
            carry=count/10;
        }
        while(!sta.empty()){
            ListNode* add=new ListNode(sta.top());
            sta.pop();
            tmp->next=add;
            tmp=tmp->next;
        }
        return res->next;
    }
};
