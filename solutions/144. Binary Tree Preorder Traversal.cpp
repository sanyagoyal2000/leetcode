/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define pb push_back
class Solution {
public:
    vector <int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        
        
        stack<TreeNode*>s;
        while(!s.empty() or root ){
           if (root) {
                ans.pb(root -> val);
                if (root -> right) {
                    s.push(root -> right);
                }
                root = root -> left;
            } else {
                root = s.top();
                s.pop();
            }
                
            }
       return ans;
         
        
    }
    void preorder(TreeNode* root){
        if(!root){
            return;
        }
        ans.pb(root->val);
        preorder(root->left);
        preorder(root->right);
        
    }
};
