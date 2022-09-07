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
    TreeNode*lca(TreeNode*root,int s,int d)
    {
        if(!root)
            return NULL;
        if(root->val==s||root->val==d)
            return root;
        TreeNode*l=lca(root->left,s,d);
        TreeNode*r=lca(root->right,s,d);
        if(l&&r)
            return root;
        return l?l:r;
    }
    
    //step 2 : path from lca to s and lca to d
    bool path(TreeNode*root,int s,string &p)
    {
        if(!root)
            return false;
        //if we find the node then return true
        if(root->val==s)
            return true;
        // check id the node exist in left subtree
        p.push_back('L');
        if(path(root->left,s,p))
            return true;
        //if not then remove l
        p.pop_back();
        
        //check in right subtree
        p.push_back('R');
        if(path(root->right,s,p))
            return true;
        //if not found then remove r
        p.pop_back();
        //if not found in root,left subtree and right subtree then return false
        return false;
    }
    
    
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode*l=lca(root,s,d); //get lca
        string ls="",ld="";
        path(l,s,ls);   //find path from lca to s
        path(l,d,ld);   //path from lca to d
        
        //lca to s has to be always an upward move as per the ques .. hence replace l and r with u (bcoz we want path from s to lca)
        for(auto &x:ls)
            x='U';
        //return the paths sum
        return ls+ld;
    }
};