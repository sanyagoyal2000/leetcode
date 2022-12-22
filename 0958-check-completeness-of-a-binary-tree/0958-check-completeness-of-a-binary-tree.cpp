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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL)     // We encounter a NULL and this should be our end node. Like ex-1.
                flag = true;  
            else  // cur != NULL
            {
                if(flag == true)  // means after encountering a NULL we again encountered a node like ex-2.
                    return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;  // We never encounter a false so return true;
    }
};