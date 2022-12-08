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
    bool dfs2(TreeNode* root, vector<int> &st,int &i) {
        if (!root) return true;
        if (!root->right && !root->left) {
            if (i < st.size() && st[i++] == root->val) return true;
            return false;
        }
        return dfs2(root->left, st,i) && dfs2(root->right, st,i);
    }
    void dfs(TreeNode * root, vector<int> &st){
        if (!root) return;
        if (!root->right && !root->left) st.push_back(root->val);
        dfs(root->left, st);
        dfs(root->right, st);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> st;int i = 0;
        dfs(root1, st);     
        //size check may be the second tree nodes were greater in size
        if (dfs2(root2, st, i) && i == st.size()) return true;
        return false;
    }
};
