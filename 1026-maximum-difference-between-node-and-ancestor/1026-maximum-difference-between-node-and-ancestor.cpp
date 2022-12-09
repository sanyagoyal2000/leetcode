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
    int diff(TreeNode* root,int mi,int mx)
    {
        if(!root)
        return abs(mi-mx);
        mi=min(mi,root->val);
        mx=max(mx,root->val);
        return max(diff(root->left,mi,mx),diff(root->right,mi,mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        return diff(root,INT_MAX,INT_MIN);
    }
};