        if(root->left == NULL && root->right == NULL){
            if(cam)
                return 1;
            else{
                if(parCam)
                    return 0;
                else return inf;
            }
        }
        
        if(dp.find({root, {cam, parCam}}) != dp.end())
            return dp[{root, {cam, parCam}}];
        if(cam){
            return dp[{root, {cam, parCam}}] = 1 + min(solve(root->left, 0, 1), solve(root->left, 1, 1)) +
                        min(solve(root->right, 0, 1), solve(root->right, 1, 1));
        }
        else{
            if(parCam){
                return dp[{root, {cam, parCam}}] = min(solve(root->left, 0, 0), solve(root->left, 1, 0)) +
                        min(solve(root->right, 0, 0), solve(root->right, 1, 0));
            }
            else{
                int op1 = solve(root->left, 1, 0) + min(solve(root->right, 0, 0), solve(root->right, 1, 0));
                int op2 = solve(root->right, 1, 0) + min(solve(root->left, 0, 0), solve(root->left, 1, 0));
                return dp[{root, {cam, parCam}}] = min(op1, op2);
            }
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        dp.clear();
        return min(solve(root, 0, 0), solve(root, 1, 0));
    }
};
