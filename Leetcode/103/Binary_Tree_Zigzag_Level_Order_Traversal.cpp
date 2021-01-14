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
 //Solution 1
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==nullptr) return vec;
        queue<TreeNode*> que;
        que.push(root);
        bool flag=false;
        while(que.size()!=0){
            vector<int> tmp;
            int size=que.size();
            for(int i=0;i<size;i++){
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                tmp.push_back(que.front()->val);
                que.pop();
            }
            if(flag){
                reverse(tmp.begin(),tmp.end());
            }
            vec.push_back(tmp);
            flag=!flag;
        }
        return vec;
    }
};


//Solution2
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==nullptr) return vec;
        queue<TreeNode*> que;
        que.push(root);
        bool flag=false;
        while(que.size()!=0){
            vector<int> tmp(que.size());
            int size=que.size();
            for(int i=0;i<size;i++){
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                if(flag) tmp[size-1-i]=que.front()->val;
                else tmp[i]=que.front()->val;
                que.pop();
            }
            vec.push_back(tmp);
            flag=!flag;
        }
        return vec;
    }
};
