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
   int costToDistribute(TreeNode *root, int& moves) {
	if(root && !root->left && !root->right) {
		// no new moves for this subtree
		return 1-root->val;
	}
	int leftCost = 0, rightCost = 0;
	if(root->left) {
		if(!root->left->left && !root->left->right) leftCost = 1-root->left->val;
		else leftCost = costToDistribute(root->left, moves);
	}
	if(root->right) {
		if(!root->right->left && !root->right->right) rightCost = 1-root->right->val;
		else rightCost = costToDistribute(root->right, moves);
	}
	moves+=abs(leftCost) + abs(rightCost); //assume all wealth to be at the root
	int total_cost = leftCost + rightCost + (1-root->val);
	return total_cost;
}

int distributeCoins(TreeNode* root) {
	if(!root) return 0;
	int moves = 0;
	costToDistribute(root, moves);
	return moves;
}
};