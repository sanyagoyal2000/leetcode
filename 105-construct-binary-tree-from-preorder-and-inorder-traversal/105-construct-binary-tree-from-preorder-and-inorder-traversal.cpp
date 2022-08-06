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
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder,int is,int ie,int ps,int pe,map<int,int>&m){
        if(is>ie or ps>pe)return NULL;
        TreeNode *root= new TreeNode(preorder[ps]);
        int ele=m[root->val];
        int nele=ele-is;//total no. of nodes in left subtree
        root->left=construct(preorder,inorder,is,ele-1,ps+1,ps+nele,m);
        root->right=construct(preorder,inorder,ele+1,ie,ps+nele+1,pe,m);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int is=0;
        int ie=inorder.size()-1;
        int ps=0;
        int pe=preorder.size()-1;
        return construct(preorder,inorder,is,ie,ps,pe,m);
    }
};