/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* solve(TreeNode*& root, int& p, int& q)
    {
        if(root == nullptr)
            return nullptr;
        
        if(root->val == p || root->val == q)
            return root;
        TreeNode* left = solve(root->left,p,q);
        TreeNode* right = solve(root->right,p,q);
        if(right != nullptr && left != nullptr)
        {
            return root;
        }else if(right == nullptr)
            return left;
        return right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p->val,q->val);    
    }
};