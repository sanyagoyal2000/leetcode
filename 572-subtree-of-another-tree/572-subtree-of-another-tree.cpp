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
    bool isIdentical(TreeNode *root, TreeNode *subRoot){
        if(!root and !subRoot)return true;
        if(!root or !subRoot) return false;
        if((root->val==subRoot->val) and isIdentical(root->left,subRoot->left) 
            and isIdentical(root->right,subRoot->right))return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)return true;
        if(!root)return false;
        if (isIdentical(root,subRoot))return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
        
    }
};