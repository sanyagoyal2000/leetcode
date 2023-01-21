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
/*
class Solution {
    pair<int,int> inorder(TreeNode* root, int &ans){
​
        if(root->left==NULL && root->right==NULL)
            return {root->val,root->val};
        
        pair<int,int>p ={root->val, root->val};
        if(root->left){
​
            pair lp = inorder(root->left, ans);
            ans = max(ans, abs(root->val-lp.first));
            ans = max(ans, abs(root->val-lp.second));
            p.first = min(p.first, lp.first);
            p.second = max(p.second, lp.second);
​
        }
        if(root->right){
​
            pair rp = inorder(root->right,ans);
            ans = max(ans, abs(root->val-rp.first));
            ans = max(ans, abs(root->val-rp.second));
            p.first = min(p.first,rp.first);
            p.second = max(p.second, rp.second);
​
        }
        return p;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        inorder(root, ans);
​
        return ans;
        
    }
};
*/
