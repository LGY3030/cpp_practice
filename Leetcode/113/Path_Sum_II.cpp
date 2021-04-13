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
    void search(TreeNode* root, int target, vector<vector<int>> &res, vector<int> vec){
        if(root==nullptr) return;
        vec.push_back(root->val);
        if(target-root->val==0 && (root->left==nullptr && root->right==nullptr)){
            res.push_back(vec);
            return;
        }
        search(root->left, target-root->val, res, vec);
        search(root->right, target-root->val, res, vec);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        search(root, targetSum, res, {});
        return res;
    }
};

//Solution 2
class Solution {
private:
    void search(TreeNode* root, int target, vector<vector<int>> &res, vector<int> &vec){
        if(root==nullptr) return;
        vec.push_back(root->val);
        if(target-root->val==0 && (root->left==nullptr && root->right==nullptr)){
            res.push_back(vec);
            vec.pop_back();
            return;
        }
        search(root->left, target-root->val, res, vec);
        search(root->right, target-root->val, res, vec);
        vec.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> vec;
        search(root, targetSum, res, vec);
        return res;
    }
};
