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
    void helper(TreeNode *root,vector<string>&ans,string curr){
        if(!root)return;
        if(root->left or root->right){
            curr+=(root->val +'a');
        }
        else{
            curr+=(root->val +'a');
            reverse(curr.begin(),curr.end());
                ans.push_back(curr);
        }
        helper(root->left,ans,curr);
        helper(root->right,ans,curr);
    }
    
    string smallestFromLeaf(TreeNode* root) {
    vector<string>ans;
        string curr="";
        helper(root,ans,curr);
        sort(ans.begin(),ans.end());
        string res=ans[0];
        return res;
    }
    
};