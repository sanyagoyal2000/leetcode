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
class Solution {
public:
    int preindex=0;
  TreeNode* inpre(vector<int> preorder,vector<int> inorder,int left,int right)
  {
      if(left>right)
      {
          return NULL;
      }
      TreeNode* root=new TreeNode(preorder[preindex++]);
      int inindex=0;
      for(int i=left;i<=right;i++)
      {
          if(inorder[i]==root->val)
          {
              inindex=i;
              break;
          }
      }
      root->left=inpre(preorder,inorder,left,inindex-1);
      root->right=inpre(preorder,inorder,inindex+1,right);
      return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return inpre(preorder,inorder,0,inorder.size()-1);
    }
};
