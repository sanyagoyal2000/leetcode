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
    int function(TreeNode *root,int &maxi){
        if(!root)return 0;
        int left=max(0,function(root->left,maxi));
        int right=max(0,function(root->right,maxi));
        maxi=max(maxi,root->val+left+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int maxi=INT_MIN;
        function(root,maxi);
        return maxi;
    }
};