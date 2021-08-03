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
private:
    void getvector(TreeNode* root, vector<int> &vec, int sum){
        if(root->left==nullptr && root->right==nullptr){
            vec.push_back(sum*10+root->val);
            return;
        }
        if(root->left) getvector(root->left, vec, sum*10+root->val);
        if(root->right) getvector(root->right, vec, sum*10+root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> vec;
        getvector(root, vec, 0);
        int res=0;
        for(auto &i: vec) res+=i;
        return res;
    }
};

//Solution 2
class Solution {
private:
    int getvector(TreeNode* root, int sum){
        if(root->left==nullptr && root->right==nullptr) return sum*10+root->val;
        int val=0;
        if(root->left) val+=getvector(root->left, sum*10+root->val);
        if(root->right) val+=getvector(root->right, sum*10+root->val);
        return val;
    }
public:
    int sumNumbers(TreeNode* root) {
        return getvector(root, 0);
    }
};

//Solution 3
class Solution {
private:
    void bk(TreeNode* root, int& res, int current){
        if(root->left==nullptr && root->right==nullptr){
            res+=(current+root->val);
            return;
        }
        if(root->left) bk(root->left, res, (current+root->val)*10);
        if(root->right) bk(root->right, res, (current+root->val)*10);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        int res=0;
        bk(root, res, 0);
        return res;
    }
};
