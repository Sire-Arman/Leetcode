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
    int solve(TreeNode* root,TreeNode* par){
        if(root == NULL) return 0;
        int val = solve(root->left,root) + solve(root->right,root);
        int x = root->val-1;
        if(par) par->val += x;
        val+=abs(x);
        return val;
        
    }
    int dfs(TreeNode* root, int step, int& cost){
        if(root == NULL) return 0;
        if(root->val >1){
            cost += root->val-1;
            root->val = 1;
        }
        int ans =0;
        if(cost == 0 && root->val<=1){
            ans += 0+dfs(root->left,0,cost);
            if(cost == 0){
                ans += 0+dfs(root->right,0,cost);
            }
            else{
                if(root->val ==0 )
                    {ans += step;
                    root->val = 1;
                    cost--;}
                    ans += 0+dfs(root->right,step+1,cost);
            }
        }
        else{
            if(root->val == 0){
                ans += step;
                cost--;
            }
            ans += dfs(root->left,step+1,cost);
            ans += dfs(root->right,step+1,cost);
            
        }
        return ans;
    }
    int distributeCoins(TreeNode* root) {
        return solve(root,NULL);
    }
};