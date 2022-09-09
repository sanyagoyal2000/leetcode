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
    void sum(TreeNode *root,vector<int>&v,int &ind){
        if(root==NULL)
            return;
        if(root->left!=NULL)
            sum(root->left,v,ind);
        root->val=v[ind++];
        if(root->right!=NULL)
            sum(root->right,v,ind);
    }
    void tree(TreeNode *root,vector<int>&v){
        if(root!=NULL){
            tree(root->left,v);
            v.push_back(root->val);
            tree(root->right,v);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
         if(root==NULL)
              return NULL;
          vector<int>v;
          tree(root,v);
          for(int i=v.size()-2;i>=0;--i)
              v[i]+=v[i+1];
          int ind=0;
          sum(root,v,ind);
          return root;
    }
};