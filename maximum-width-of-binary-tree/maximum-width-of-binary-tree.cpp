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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>>q;//int is for storing index in an array
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
           int n=q.size();
            int start=q.front().second;
            ans=max(ans,q.back().second-q.front().second +1);
        
        while(n--){
            auto p=q.front();
            q.pop();
            int index=p.second-start;
            if(p.first->left){
                q.push({p.first->left,2*index+1});
            }
            if(p.first->right){
                q.push({p.first->right,2*index+2});
            }
             
        }
    }
        return ans;
    }
};