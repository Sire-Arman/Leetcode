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
    void dfs(TreeNode* root, int val , int depth){
        if(depth <= 0) return;
        if(depth == 1){
            TreeNode* t = new TreeNode(val);
            TreeNode* x = new TreeNode(val);
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = t;
            root->right = x;
            t->left = l;
            x->right = r;
            x->left = NULL;
            t->right = NULL;
        }
        if(root->left) dfs(root->left,val,depth-1);
        if(root->right) dfs(root->right,val ,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* t = new TreeNode(val);
            t->left = root;
            t->right = NULL;
            return t;
        }
        dfs(root,val,depth-1);
        return root;
    }
};