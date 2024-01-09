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
    void dfs(TreeNode* root, int prev, int& cnt){
        if(root == NULL) return;
        if(root->val >= prev){
            cnt++;
            prev = max(root->val,prev);
        }
        if(root->left) dfs(root->left,prev,cnt);
        if(root->right) dfs(root->right,prev,cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        int prev =INT_MIN;
        dfs(root,prev,cnt);
        return cnt;
    }
};