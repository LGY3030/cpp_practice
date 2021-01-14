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
    void getBST(TreeNode *root, vector<int> &vec){
        if(root==nullptr) return;
        getBST(root->left, vec);
        vec.push_back(root->val);
        getBST(root->right, vec);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        vector<int> tmp;
        getBST(root, vec);
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i]==vec[i+1]) return false;
        }
        tmp=vec;
        sort(vec.begin(),vec.end());
        return vec==tmp;
    }
};


//Solution 2
class Solution {
public:
    bool getBST(TreeNode *root, TreeNode* &pre){
        if(root==nullptr) return true;
        if(!getBST(root->left, pre)) return false;
        if(pre!=nullptr && root->val<=pre->val) return false;
        pre = root;
        return getBST(root->right, pre);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre=nullptr;
        return getBST(root, pre);
    }
};


//Solution 3
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> sta;
        TreeNode* pre=nullptr;
        while(root || !sta.empty()){
            while(root){
                sta.push(root);
                root=root->left;
            }
            root=sta.top();
            sta.pop();
            if(pre && pre->val>=root->val) return false;
            pre=root;
            root=root->right;
        }
        return true;
    }
};
