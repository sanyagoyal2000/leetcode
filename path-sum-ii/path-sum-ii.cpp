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
    void paths(TreeNode *root,int k,vector<vector<int>>&res,vector<int>&curr){
        if(!root)return;
        
        k=k-root->val;
        curr.push_back(root->val);
        if(k==0 and !root->left and !root->right){
            res.push_back(curr);
        }
        paths(root->left,k,res,curr);
        paths(root->right,k,res,curr);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>curr;
        paths(root,targetSum,res,curr);
        return res;
    }
};