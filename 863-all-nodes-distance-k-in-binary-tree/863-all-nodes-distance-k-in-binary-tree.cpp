/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode *root,map<TreeNode*,TreeNode*>&par){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left){
                par[temp->left]=temp;
                q.push(temp->left);
                
            }
             if(temp->right){
                par[temp->right]=temp;
                q.push(temp->right);
                
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        map<TreeNode*,TreeNode*>par;
        markParent(root,par);
        set<TreeNode*>vis;
        vis.insert(target);
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        while(!q.empty()){
            auto[node,dis]=q.front();
            if(dis==k){ans.push_back(node->val);}
            if(dis>k)break;
            q.pop();
            if(node->left and vis.find(node->left)==vis.end()){
                vis.insert(node->left);
                q.push({node->left,dis+1});
            }
            if(node->right and vis.find(node->right)==vis.end()){
                vis.insert(node->right);
                q.push({node->right,dis+1});
            }
            if(par[node] and vis.find(par[node])==vis.end()){
                vis.insert(par[node]);
                q.push({par[node],dis+1});
            }
        }
        return ans;
    }
};