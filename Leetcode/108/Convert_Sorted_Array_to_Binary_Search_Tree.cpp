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
   TreeNode* get(vector<int>& nums, int start, int end){
       if(end<start) return nullptr;
       int mid=(end+start)/2;
       TreeNode * root =new TreeNode(nums.at(mid));
       root->left=get(nums,start, mid-1);
       root->right=get(nums,mid+1,end);
       return root;
   }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return get(nums, 0, nums.size()-1);
    }
};
