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
    pair<int,int> solve(TreeNode* root, int &ans){
        if(root==NULL){
            return {0,0};
        }
        
        pair<int,int> ans1 = solve(root->left,ans);
        pair<int,int> ans2 = solve(root->right,ans);
        
        int c_sum = ans1.first + ans2.first + root->val;
        int c_count = ans1.second + ans2.second + 1;
        if(c_sum/c_count == root->val) ans++;\
            
        return {c_sum,c_count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans =0;
        solve(root,ans);
        return ans;
    }
};