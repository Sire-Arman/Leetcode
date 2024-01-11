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
    void dfs(TreeNode* root , int mini, int maxi, int& diff){
        if(root== NULL){
            return ;
        }
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);
        // cout<<maxi<<' '<<mini<<' '<<root->val<<endl;
        diff = max(abs(mini-root->val), max(abs(maxi-root->val),diff));
        if(root->left) dfs(root->left, mini,maxi,diff);
        if(root->right) dfs(root->right,mini,maxi,diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        dfs(root,root->val,root->val,diff);
        return diff;
    }
};