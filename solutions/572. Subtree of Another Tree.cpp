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
string s1,s2,p1,p2;
void inOrder(TreeNode *root,string &s){
    if(!root)return;
    
    inOrder(root->left,s);
    s.push_back(root->val +'0');
    s.push_back('#');
    inOrder(root->right,s);
    
}
void preOrder(TreeNode *root,string &s){
    if(!root)return;
    s.push_back(root->val +'0');
    s.push_back('#');
    preOrder(root->left,s);
    preOrder(root->right,s);
​
}
class Solution {
public:
    bool isIdentical(TreeNode *root, TreeNode *subRoot){
        if(!root and !subRoot)return true;
        if(!root or !subRoot) return false;
        if((root->val==subRoot->val) and isIdentical(root->left,subRoot->left) 
            and isIdentical(root->right,subRoot->right))return true;
        return false;
    }
