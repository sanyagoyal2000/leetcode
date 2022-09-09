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
class FindElements {
public:
    unordered_map<int,int> m;
    void preorder(TreeNode* r,int v)
    {
        if(!r)
            return;
        m[v]++;
        preorder(r->left,2*v+1);
        preorder(r->right,2*v+2);
    }
    FindElements(TreeNode* root) {
        preorder(root,0);
    }
    
    bool find(int target) {
        return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */