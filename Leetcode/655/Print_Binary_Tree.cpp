//Solution 1
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
    int getDepth(TreeNode* root){
        if(!root) return 0;
        return 1+max(getDepth(root->left), getDepth(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = getDepth(root);
        int n = pow(2, depth)-1;
        vector<vector<string>> res(depth, vector<string>(n, ""));
        queue<pair<TreeNode*, int>> que;
        que.push({root, (n-1)/2});
        int r=0;
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                auto temp=que.front();
                que.pop();
                string nodeval="";
                bool neg=false;
                if(temp.first->val<0) neg=true;
                temp.first->val=abs(temp.first->val);
                while(temp.first->val){
                    nodeval=char(temp.first->val%10+'0')+nodeval;
                    temp.first->val=temp.first->val/10;
                }
                if(neg) nodeval='-'+nodeval;
                if(nodeval=="") res[r][temp.second] = "0";
                else res[r][temp.second] = nodeval;
                if(temp.first->left) que.push({temp.first->left, temp.second-pow(2, depth-1-r-1)});
                if(temp.first->right) que.push({temp.first->right, temp.second+pow(2, depth-1-r-1)});
            }
            r++;
        }
        return res;
    }
};

//Solution 2
class Solution {
public:
    int getDepth(TreeNode* root){
        if(!root) return 0;
        return 1+max(getDepth(root->left), getDepth(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = getDepth(root);
        int n = pow(2, depth)-1;
        vector<vector<string>> res(depth, vector<string>(n, ""));
        queue<pair<TreeNode*, int>> que;
        que.push({root, (n-1)/2});
        int r=0;
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                auto temp=que.front();
                que.pop();
                res[r][temp.second] = to_string(temp.first->val);
                if(temp.first->left) que.push({temp.first->left, temp.second-pow(2, depth-1-r-1)});
                if(temp.first->right) que.push({temp.first->right, temp.second+pow(2, depth-1-r-1)});
            }
            r++;
        }
        return res;
    }
};
