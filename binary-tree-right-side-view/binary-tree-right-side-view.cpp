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
   void rhsRec(TreeNode* root, int level, vector<int> &rhs)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(level == rhs.size())
        {
            rhs.push_back(root->val);
        }
        
        
        rhsRec(root->right,level+1,rhs);
        rhsRec(root->left,level+1,rhs);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rhs;
        rhsRec(root, 0, rhs);
        return rhs;
    }
};