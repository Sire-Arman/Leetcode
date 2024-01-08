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
    void dfs(TreeNode* root,int &sum,int lb,int ub){
        if(root == NULL) return;
        if(root->left) dfs(root->left,sum,lb,ub);
        if(root->val >=lb && root->val <= ub){
            sum+=root->val;
        }
        if(root->right) dfs(root->right,sum,lb,ub);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(low == high) return low;
        int sum =0;
        dfs(root,sum,low,high);
        return sum;
    }
};