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
void dfs(TreeNode* root, vector<int>& v, int low, int high){
    if (root==NULL)return;
    //if (root->left && root->val>low)dfs(root->left,v,high,low);
    //v.push_back(root->val);
    //if (root->right && root->val<high)dfs(root->right,v,high,low);
    //v.push_back(root->val);

    if (root->left)dfs(root->left,v,high,low);
    v.push_back(root->val);
    if (root->right)dfs(root->right,v,high,low);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        vector<int> v;
        dfs(root,v,high,low);
        for (auto val: v){
            if(val>=low && val<=high)
            ans+= val;
        }
        return ans;
    }
};