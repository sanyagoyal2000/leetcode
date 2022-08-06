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
#define pb push_back
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int x=1;
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            while(n--){
                root=q.front();
                v.push_back(root->val);
                q.pop();
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
            x++;
            if(x%2!=0){
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};