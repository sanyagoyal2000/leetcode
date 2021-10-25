        if(s.size()<2)return -1;
        int i=0;
        for(auto x:s){
            i++;
            if(i==2){
                return x;
                break;}
        }
        return -1;
    }
};
​
/*
​
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL || root->left==NULL)
            return -1;
        int first=root->val;
        int l=helper(root->left,first);
        int r=helper(root->right,first);
        if(l!=-1 && r!=-1)
            return min(l,r);
        return max(l,r);
    }
    
    int helper(TreeNode* root,int x)
    {
        if(root==NULL)
            return -1;
        if(root->val==x)
        {
            int y=helper(root->left,x);
            int z=helper(root->right,x);
            
            if(y!=-1 && z!=-1)
                return min(y,z);
            else
                return max(y,z);
        }
        else
        {
            return (root->val);
        }
    }
};
*/
